<?php
/**
 * @file
 * features_starter_kit.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_starter_kit_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function features_starter_kit_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Страница'),
      'base' => 'node_content',
      'description' => t('Страница — это документ, который используется для страниц с редко изменяемой информацией. Например, таких страниц как «О сайте» или «Наш адрес». По умолчанию, документы этого типа не выводятся на первую страницу сайта и их комментирование отключено.'),
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
  );
  return $items;
}
