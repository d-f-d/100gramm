<?php
namespace d\Twig;

class Extension extends \Twig_Extension {
  public function getFilters() {
    return [
      new \Twig_SimpleFilter('file_url', 'file_create_url'),
      new \Twig_SimpleFilter('transliterate', 'transliteration_clean_filename'),
    ];
  }

  public function getFunctions() {
    return [
      new \Twig_SimpleFunction('render', [$this, 'render']),
      new \Twig_SimpleFunction('drupal_render', [$this, 'drupal_render']),
      new \Twig_SimpleFunction('theme', 'theme'),
      new \Twig_SimpleFunction('url', 'url'),
    ];
  }

  public function render($class, $context) {
    if (class_exists($class) && method_exists($class, 'render')) {
      return drupal_render((new $class($context))->render());
    }
    return '';
  }

  public function drupal_render($data) {
    return render($data);
  }

  public function getName() {
    return __CLASS__;
  }
}