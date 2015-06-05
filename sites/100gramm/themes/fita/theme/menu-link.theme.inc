<?php
function   fita_menu_link(array $variables) {
  $level = & drupal_static('base_menu_level', 0);
  $element = $variables['element'];
  $sub_menu = '';
  $index = & drupal_static('base_menu_index', 0);
  $element['#attributes']['class'][] = 'menu-element-' . $index;
  $save = $index + 1;
  $level++;
  $index = 0;
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $index = $save;
  $level--;
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

