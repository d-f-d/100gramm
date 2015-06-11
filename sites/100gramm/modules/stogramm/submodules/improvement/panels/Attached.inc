<?php

namespace d\improvement\panels;

use Drupal\d_submodules\Callback;
use Symfony\Component\Yaml\Parser;

class Attached {
  use Callback;

  /**
   * @param $ops
   * @param $handler
   * @implement page_manager_variant_operations_alter
   */
  static function variant_insert(&$ops, $handler) {
    reset($ops['children']);
    $children_operations = [];

    while (list($key, $value) = each($ops['children'])) {
      $children_operations[$key] = $value;

      if ($key == 'context') {
        $children_operations['attached'] = [
          'title' => '#attached',
          'description' => 'Allows loading of CSS, Javascript, libraries, or custom types when the panel is built. ',
          'form' => self::getCallbackName('form'),
        ];
      }
    }

    $ops['children'] = $children_operations;
  }

  /**
   * @implement callback
   */
  static function form($form, &$form_state) {
    $conf = &$form_state['handler']->conf;

    $conf['panels_attached'] = isset($conf['panels_attached']) ? $conf['panels_attached'] : '';

    $form['settings']['panels_attached'] = [
      '#type' => 'textarea',
      '#title' => '#attached',
      '#description' => 'Enter YAML #attached conf',
      '#default_value' => $conf['panels_attached'],
    ];
    return $form;
  }

  /**
   * @implement callback
   */
  static function form_submit(&$form, &$form_state) {
    $conf = &$form_state['handler']->conf;
    $conf['panels_attached'] = $form_state['values']['panels_attached'];
    return $form;
  }

  /**
   * @param $info
   * @param $page
   * @param $context
   * @implement ctools_render_alter
   */
  static function ctools_render_alter($info, $page, $context) {
    $conf = $context['handler']->conf;
    $attached = isset($conf['panels_attached']) ? trim($conf['panels_attached']) : NULL;
    if (!$attached) {
      return;
    }
    try {
      $attached = ctools_context_keyword_substitute($attached, [], $context['contexts']);
      $key = md5($attached);
      $cache = cache_get('yaml-parse--' . $key);
      if ($cache && $cache->data) {
        $attached = $cache->data;
      }
      else {
        $attached = (new Parser())->parse($attached);
        cache_set('yaml-parse--' . $key, $attached, 'cache', REQUEST_TIME + 3600);
      }
      $attached = ['#attached' => $attached];
      drupal_render($attached);
    } catch (\Exception $e) {
      drupal_set_message($e->getMessage(), 'error');
    }
  }
}