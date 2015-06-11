<?php

namespace d\Twig;

class Twig {
  /**
   * @implement flush_caches
   */
  static function clearCache() {
    file_unmanaged_delete_recursive(variable_get('file_private_path', variable_get('file_public_path', conf_path() . '/files')) . '/.ht.twig_cache');
  }

  static function render($template, $scope, $label = 'content') {
    if (!is_array($template)) {
      $template = [
        $label => $template,
      ];
    }
    $loader = new \Twig_Loader_Array($template);
    $twig = new \Twig_Environment($loader, ['cache' => variable_get('file_private_path', variable_get('file_public_path', conf_path() . '/files')) . '/.ht.twig_cache']);
    $twig->addExtension(new Extension());
    return $twig->render($label, $scope);
  }
}