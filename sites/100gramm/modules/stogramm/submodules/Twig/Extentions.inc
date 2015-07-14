<?php
namespace d\Twig;

use Twig_Extension;
use Twig_SimpleFilter;
use Twig_SimpleFunction;

class Extension extends Twig_Extension {
  public $attached = [];

  public function getFilters() {
    return [
      new Twig_SimpleFilter('file_url', 'file_create_url'),
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

  public function render($class, $context = []) {
    if (class_exists($class) && method_exists($class, 'render')) {
      return $this->drupal_render((new $class($context))->render());
    }
    return '';
  }

  public function drupal_render($data) {
    $this->extractAttached($data);
    return render($data);
  }

  public function check_markup($text, $format_id, $langcode = '', $cache = TRUE) {
    return check_markup($text, $format_id, $langcode, $cache);
  }

  public function truncate_utf8($string, $max_length, $wordsafe = TRUE, $add_ellipsis = FALSE, $min_wordsafe_length = 1) {
    return truncate_utf8($string, $max_length, $wordsafe, $add_ellipsis, $min_wordsafe_length);
  }

  private function extractAttached(&$data) {
    if (!is_array($data)) {
      return;
    }
    if (isset($data['#attached'])) {
      $this->attached = drupal_array_merge_deep($this->attached, $data['#attached']);
      unset($data['#attached']);
    }
    foreach ($data as $key => &$value) {
      if (!is_string($key) || '#' !== $key[0]) {
        $this->extractAttached($value);
      }
    }
  }

  public function getName() {
    return __CLASS__;
  }
}
