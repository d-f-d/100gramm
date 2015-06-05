<?php

namespace Drupal\d_submodules;

use \ReflectionParameter;
use \ReflectionFunction;
use \ReflectionMethod;
use \ReflectionClass;
use \Underscore\Underscore as __;

class Submodules {
  static private $module = NULL;
  private $implementations = [];
  private $plugins = [];
  private $classes = [];
  private $code = [];
  private $needSelfPath = [];

  function __construct($module = NULL, $reset = FALSE) {
    if (static::$module || !$module) {
      return;
    }
    static::$module = $module;
    require_once DRUPAL_ROOT . '/includes/common.inc';
    require_once DRUPAL_ROOT . '/includes/file.inc';
    require_once DRUPAL_ROOT . '/includes/path.inc';
    if ($reset || $this->isReset() || !file_exists(static::file())) {
      $this->scanImplementations();
      $this->generateCode();
      $this->saveCode();
      variable_del(static::$module . '_reset');
    }
    require_once static::file();
  }

  private function module() {
    return static::$module;
  }

  public static function reset() {
    unlink(static::file());
  }

  private function isReset() {
    global $user;
    return variable_get(static::$module . '_reset')
    || ('admin_menu/flush-cache' === current_path() && isset($_GET['token']) && drupal_valid_token($_GET['token'], current_path()))
//    || (isset($_POST['form_id']) && ('system_performance_settings' === $_POST['form_id'] && 1 === (int) $user->uid))
    || (drupal_is_cli() && function_exists('drush_get_command') && 'cache-clear' === drush_get_command()['command']);
  }

  private function convertParametersToString($parameters) {
    return [
      implode(', ', array_map(function (ReflectionParameter $parameter) {
        return ($parameter->isPassedByReference() ? '&' : '')
        . '$' . $parameter->getName()
        . ($parameter->isDefaultValueAvailable() ? (' = ' . var_export($parameter->getDefaultValue(), TRUE)) : '');
      }, $parameters)),
      implode(', ', array_map(function (ReflectionParameter $parameter) {
        return '$' . $parameter->getName();
      }, $parameters)),
    ];
  }

  private function getImplementations($hook = NULL) {
    return $hook ? (isset($this->implementations[$hook]) ? $this->implementations[$hook] : []) : $this->implementations;
  }

  private function scanImplementations() {
    spl_autoload_register(function ($class) {
      if (isset($this->classes[$class])) {
        return require $this->classes[$class];
      }
      return FALSE;
    });
    $submodules = [];
    foreach (system_list('module_enabled') as $module) {
      $submodules += file_scan_directory(drupal_get_path('module', $module->name) . '/submodules', '/\.inc$/');
    }
    $submodules = array_values($submodules);
    for ($i = 0; $i < count($submodules); $i++) {
      $sub_module = $submodules[$i];
      $code = file_get_contents($sub_module->uri);
      preg_match('/namespace\s+([^\s]+)\s*;/i', $code, $matches);
      $namespace = $matches ? $matches[1] : '';
      preg_match('/(class|trait|interface)\s+([^\s]+)/i', $code, $matches);
      $class = $matches ? $matches[2] : '';
      if ($class && $namespace) {
        $class = $namespace . '\\' . $class;
      }
      if ($class && empty($this->classes[$class])) {
        $this->classes[$class] = $sub_module->uri;
        array_push($submodules, $sub_module);
        continue;
      }
      if ($class && class_exists($class)) {
        $functions = array_map(function ($method) {
          return $method->name;
        }, (new ReflectionClass($class))->getMethods(ReflectionMethod::IS_PUBLIC));
      }
      elseif (!$class) {
        preg_match_all('/function\s+([^\s]+)\s*\(/i', $code, $matches);
        $functions = $matches[1];
      }
      else {
        continue;
      }
      require_once $sub_module->uri;
      foreach ($functions as $function) {
        if (!$class && $namespace) {
          $function = $namespace . '\\' . $function;
        }
        if (!$class && function_exists($function)) {
          $function_info = new ReflectionFunction($function);
        }
        elseif ($class && method_exists($class, $function)) {
          $function_info = new ReflectionMethod($class, $function);
        }
        else {
          continue;
        }
        $doc_block = new DocBlock($function_info->getDocComment() ?: '');
        $function = $class ? "$class::$function" : $function;
        if (NULL !== $doc_block->needSelfPath) {
          $this->needSelfPath[] = [
            'uri' => $sub_module->uri,
            'function' => $function,
          ];
        }
        if ($doc_block->plugin && $doc_block->owner) {
          $this->plugins[$doc_block->owner][] = $doc_block->plugin;
          $doc_block->implement = $doc_block->owner . '_' . $doc_block->plugin;
        }
        if ($doc_block->implement) {
          $this->implementations[$doc_block->implement][] = [
            'uri' => $class ? NULL : $sub_module->uri,
            'function' => $function,
            'doc_block' => $doc_block,
            'arguments' => $this->convertParametersToString($function_info->getParameters())
          ];
        }
      }
    }
  }

  private function template($string, array $data = []) {
    /** @noinspection PhpParamsInspection */
    return __::template($string, __::defaults($data, [
      'module' => $this->module(),
      'classes' => $this->classes,
      'plugins' => $this->plugins,
      '__' => '\Underscore\Underscore'
    ]), ['interpolate' => '/\{\{(.+?)\}\}/']);
  }

  private function generateCode() {
    $this->code[] = "<?php";
    if ($this->classes) {
      $this->code[] = $this->generateClassAutoload();
    }
    if ($this->plugins) {
      $this->code[] = $this->generatePluginHack();
    }
    $implementations = array_diff(array_keys($this->getImplementations()), [
      'form',
      'form_alter',
      'callback'
    ]);
    if ($implementations) {
      $this->code[] = $this->generateHookInvoke();
      foreach ($implementations as $hook) {
        if (preg_match('/_alter$/', $hook) || preg_match('/^(pre)?process_/', $hook) || 'user_login' === $hook) {
          $this->code[] = $this->generateHookAlter($hook);
        }
        else {
          $this->code[] = $this->generateHook($hook);
        }
      }
    }
    if ($this->getImplementations('form')) {
      $this->code[] = $this->generateFormsAlter();
    }
    if ($this->getImplementations('form_alter')) {
      $this->code[] = $this->generateFormsAlter(TRUE);
    }
    foreach ($this->getImplementations('callback') as $implementation) {
      $this->code[] = $this->generateCallback($implementation);
    }
    foreach ($this->needSelfPath as $implementation) {
      $this->code[] = $this->generateSelfPathCallback($implementation);
    }
  }

  private static function file() {
    return static::getDir() . '/' . $GLOBALS['conf']['drupal_private_key'] . '.inc';
  }

  private static function getDir() {
    $dir = variable_get(static::$module . '_path') ?: variable_get('file_private_path', variable_get('file_public_path', conf_path() . '/files')) . '/.ht.submodule';
    if (!is_dir($dir)) {
      @mkdir($dir, 0775, TRUE);
    }
    return $dir;
  }

  static function getSelfPath($function) {
    $callback = static::generateSelfPathCallbackName($function);
    return $callback();
  }

  static function getClassMap() {
    $callback = '_' . static::$module . '_class_map';
    return $callback();
  }

  private function saveCode() {
    file_put_contents(static::file(), implode("\n\n", $this->code) . "\n");
  }

  private function generateClassAutoload() {
    return $this->template(<<<'CODE'
function _{{$module}}_class_map() {
  return [
<%foreach ($classes as $class => $file) {%>
    '{{$class}}' => '{{$file}}',
<%}%>
  ];
}

spl_autoload_register(function ($class) {
  $map = _{{$module}}_class_map();
  if (isset($map[$class])) {
    return require $map[$class];
  }
  else {
    return FALSE;
  }
});
CODE
    );
  }

  private function generateHook($hook) {
    return $this->template(<<<'CODE'
function {{$module}}_{{$hook}}() {
<%foreach($implementations as $implementation) {%>
<%if(isset($implementation['uri'])){%>
  require_once '{{$implementation['uri']}}';
<%}%>
<%}%>
  return _{{$module}}_hook_helper([
<%foreach($implementations as $implementation) {%>
    '{{$implementation['function']}}',
<%}%>
  ], func_get_args());
}
CODE
      , [
        'hook' => $hook,
        'implementations' => $this->getImplementations($hook)
      ]);
  }

  private function generateHookInvoke() {
    return $this->template(<<<'CODE'
function _{{$module}}_hook_helper($functions, $args) {
  $return = [];
  foreach ($functions as $function) {
    $result = call_user_func_array($function, $args);
    if (isset($result) && is_array($result)) {
      $return = array_merge_recursive($return, $result);
    }
    elseif (isset($result)) {
      $return[] = $result;
    }
  }
  return $return;
}
CODE
    );
  }

  private function generatePluginHack() {
    $this->implementations['module_implements_alter'][] = [
      'function' => "_{$this->module()}_module_implements_alter"
    ];
    $this->implementations['ctools_plugin_type'][] = [
      'function' => "_{$this->module()}_ctools_plugin_type"
    ];
    return $this->template(<<<'CODE'
function _{{$module}}_module_implements_alter(&$implementations, &$hook) {
  if ('ctools_plugin_type' === $hook) {
    $group = $implementations['{{$module}}'];
    unset($implementations['{{$module}}']);
    $implementations['{{$module}}'] = $group;
  }
}

function _{{$module}}_ctools_plugin_type() {
  $plugins = [
<%foreach ($plugins as $owner => $types) {%>
    '{{$owner}}' => [
<%foreach ($types as $type) {%>
      '{{$type}}',
<%}%>
    ],
<%}%>
  ];
  $static['plugins'] = &drupal_static('ctools_plugin_type_info');
  foreach ($plugins as $owner => $types) {
    foreach ($types as $type) {
      $static['plugins'][$owner][$type]['use hooks'] = TRUE;
    }
  }
  return [];
}
CODE
    );
  }

  private function generateHookAlter($hook) {
    /** @noinspection PhpParamsInspection */
    return $this->template(<<<'CODE'
function {{$module}}_{{$hook}}({{$args[0]}}) {
<%foreach ($implementations as $implementation) {%>
<%if(isset($implementation['uri'])){%>
  require_once '{{$implementation['uri']}}';
<%}%>
<%}%>
<%foreach ($implementations as $implementation) {%>
  {{$implementation['function']}}({{$args[1]}});
<%}%>
}
CODE
      , [
        'hook' => $hook,
        'args' => $this->convertParametersToString(__::rest((new ReflectionFunction('drupal_alter'))->getParameters())),
        'implementations' => $this->getImplementations($hook)
      ]);
  }

  private function generateFormsAlter($alter = FALSE) {
    return $this->template(<<<'CODE'
<%if ($alter) {%>
function {{$module}}_form_alter(&$form, &$form_state, $form_id) {
<%} else {%>
function {{$module}}_forms($form_id) {
<%}%>
  $implementations = [
<%foreach ($implementations as $implementation) {%>
    '{{$implementation['function']}}' => [
<%if(isset($implementation['uri'])){%>
      'uri' => '{{$implementation['uri']}}',
<%}%>
      'form_id' => '/^({{$implementation['doc_block']->form_id ?: ''}})$/'
    ],
<%}%>
  ];
  foreach ($implementations as $function => $implementation) {
    if (preg_match($implementation['form_id'], $form_id)) {
      if (isset($implementation['uri'])) {
        require_once $implementation['uri'];
      }
<%if($alter){%>
      call_user_func_array($function, [&$form, &$form_state]);
<%} else {%>
      return [$form_id => ['callback' => $function]];
<%}%>
    }
  }
<%if(!$alter){%>
  return [];
<%}%>
}
CODE
      , [
        'alter' => $alter,
        'implementations' => $this->getImplementations($alter ? 'form_alter' : 'form'),
      ]);
  }

  static function generateCallbackName($function) {
    return '_' . static::$module . '__' . preg_replace('/\W/', '__', $function);
  }

  static function generateSelfPathCallbackName($function) {
    return static::generateCallbackName($function) . '__get_self_path';
  }

  private function generateCallback($implementation) {
    return $this->template(<<<'CODE'
function {{$function}}({{$implementation['arguments'][0]}}) {
<%if(isset($implementation['uri'])){%>
  require_once '{{$implementation['uri']}}';
<%}%>
  {{$return}}{{$implementation['function']}}({{$implementation['arguments'][1]}});
}
CODE
      , [
        'function' => $this->generateCallbackName($implementation['function']),
        'return' => strtoupper($implementation['doc_block']->return) !== 'NULL' ? 'return ' : '',
        'implementation' => $implementation
      ]);
  }

  private function GenerateSelfPathCallback($implementation) {
    $function = $this->generateSelfPathCallbackName($implementation['function']);
    return <<<CODE
function $function() {
  return '{$implementation['uri']}';
}
CODE;
  }
}
