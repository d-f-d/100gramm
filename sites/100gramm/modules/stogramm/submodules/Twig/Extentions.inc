<?php
namespace d\Twig;

use Twig_Extension;
use Twig_SimpleFilter;
use Twig_SimpleFunction;

class Extension extends Twig_Extension {
  public function getFilters() {
    return [
      new Twig_SimpleFilter('file_url', 'file_create_url'),
      new Twig_SimpleFilter('transliterate', 'transliteration_clean_filename'),
      new Twig_SimpleFilter('drupal_date', 'format_date'),
      new Twig_SimpleFilter('check_markup', [$this, 'check_markup']),
      new Twig_SimpleFilter('truncate_utf8', [$this, 'truncate_utf8']),
      new Twig_SimpleFilter('text_summary', 'text_summary'),
    ];
  }

  public function getFunctions() {
    return [
      new Twig_SimpleFunction('render', [$this, 'render']),
      new Twig_SimpleFunction('drupal_render', [$this, 'drupal_render']),
      new Twig_SimpleFunction('theme', 'theme'),
      new Twig_SimpleFunction('url', 'url'),
      new Twig_SimpleFunction('drupal_date', 'format_date'),
      new Twig_SimpleFunction('check_markup', 'check_markup'),
      new Twig_SimpleFunction('timer_start', 'timer_start'),
      new Twig_SimpleFunction('timer_read', 'timer_read'),
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