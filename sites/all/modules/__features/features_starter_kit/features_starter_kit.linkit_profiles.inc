<?php
/**
 * @file
 * features_starter_kit.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function features_starter_kit_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'nodes';
  $linkit_profile->admin_title = 'Материалы';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'plain_text' => 'plain_text',
      'filtered_html' => 'filtered_html',
      'full_html' => 'full_html',
      'raw_text' => 'raw_text',
      'php_code' => 'php_code',
    ),
    'search_plugins' => array(
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => 'Материалы',
      'include_unpublished' => 0,
    ),
    'entity:user' => array(
      'result_description' => 'Пользователи',
    ),
    'insert_plugin' => array(
      'url_method' => '2',
    ),
    'attribute_plugins' => array(
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'imce' => 0,
    'autocomplete' => array(
      'charLimit' => '5',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['nodes'] = $linkit_profile;

  return $export;
}
