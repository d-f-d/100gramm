<?php

namespace d\Twig;

use Twig_Environment;
use Twig_Loader_Array;
use Twig_Loader_Filesystem;

class Twig {
  /**
   * @implement flush_caches
   */
  static function clearCache() {
    file_unmanaged_delete_recursive(variable_get('file_private_path', variable_get('file_public_path', conf_path() . '/files')) . '/.ht.twig_cache');
  }

  static function renderTemplate($template, $scope, $name = 'content') {
    if (!is_array($template)) {
      $template = [
        $name => $template,
      ];
    }
    return self::render(new Twig_Loader_Array($template), $name, $scope);
  }

  static function renderFile($source, $scope, $name = 'index.html.twig') {
    if (!is_array($source)) {
      $name = basename($source);
      $source = dirname($source);
    }
    return self::render(new Twig_Loader_Filesystem($source), $name, $scope);
  }

  /**
   * @param \Twig_LoaderInterface $loader
   * @param $name
   * @param $scope
   * @return array
   */
  private static function render(\Twig_LoaderInterface $loader, $name, $scope) {
    $twig = new Twig_Environment($loader, ['cache' => variable_get('file_private_path', variable_get('file_public_path', conf_path() . '/files')) . '/.ht.twig_cache']);
    $ext = new Extension();
    $twig->addExtension($ext);
    $render = $twig->render($name, $scope);
    return [
      '#markup' => $render,
      '#attached' => $ext->attached
    ];
  }
}