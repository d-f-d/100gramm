<?php
/**
 * @file
 * stogramm_model.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stogramm_model_taxonomy_default_vocabularies() {
  return array(
    'tags' => array(
      'name' => 'tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
