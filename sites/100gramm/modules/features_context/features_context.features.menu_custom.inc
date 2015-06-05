<?php
/**
 * @file
 * features_context.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function features_context_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-top-menu.
  $menus['menu-top-menu'] = array(
    'menu_name' => 'menu-top-menu',
    'title' => 'Верхнее меню',
    'description' => 'Социальные ссылки и такое',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Верхнее меню');
  t('Социальные ссылки и такое');


  return $menus;
}
