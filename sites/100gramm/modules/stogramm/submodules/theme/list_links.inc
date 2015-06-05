<?php

namespace d\theme\list_link;

use  Drupal\d_submodules\Submodules;

/**
 * @implement theme
 */
function theme() {
  return [
    'd_list_links' => [
      'variables' => ['items' => []],
      'function' => Submodules::generateCallbackName(__NAMESPACE__ . '\render')
    ]
  ];
}

/**
 * @implement callback
 */
function render($variables) {
  if (!$variables['items']) {
    return '';
  }
  $base_path = base_path();
  $output = '';
  foreach ($variables['items'] as $item) {
    $output .= '<li><a href="' . $base_path . (isset($item->alias) ? $item->alias : ('node/' . $item->nid)) . '">' . $item->title . '</a></li>';
  }
  return '<ul>' . $output . '</ul>';
}
