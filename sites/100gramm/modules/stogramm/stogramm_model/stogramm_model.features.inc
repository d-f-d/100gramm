<?php
/**
 * @file
 * stogramm_model.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stogramm_model_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function stogramm_model_node_info() {
  $items = array(
    'photo' => array(
      'name' => t('photo'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
