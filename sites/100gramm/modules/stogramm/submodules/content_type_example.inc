<?php

namespace d\ctool\content_types\example;

use  Drupal\d_submodules\Submodules;

/**
 * @owner ctools
 * @plugin content_types
 */
function plugin() {
  return [
    'd_example' => [
      'title' => t('Example'),
      'single' => TRUE,
      'render callback' => Submodules::generateCallbackName(__FUNCTION__ . '_render'),
      'description' => t('Example block.'),
      'category' => t('D content'),
    ]
  ];
}
/**
 * @implement callback
 */
function plugin_render() {
  $block = new \stdClass();
  $block->title = __NAMESPACE__;
  $block->content[] = ['#markup' => __FUNCTION__];
  return $block;
}