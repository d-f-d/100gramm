<?php
function  fita_menu_tree($variables) {
  $level = drupal_static('base_menu_level', 0);
  $index = & drupal_static('base_menu_index', 0);
  $index = 0;
  $attributes['class'][] = 'menu';
  $attributes['class'][] = 'menu-level-' . $level;
  return '<ul ' . drupal_attributes($attributes) . '>' . $variables['tree'] . '</ul>';
}