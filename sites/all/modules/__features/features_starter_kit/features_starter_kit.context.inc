<?php
/**
 * @file
 * features_starter_kit.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function features_starter_kit_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '403';
  $context->description = '';
  $context->tag = 'error';
  $context->conditions = array(
    'error' => array(
      'values' => array(
        403 => '403',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'content',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('error');
  $export['403'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '404';
  $context->description = '';
  $context->tag = 'error';
  $context->conditions = array(
    'error' => array(
      'values' => array(
        404 => '404',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'fita' => array(
        'disable' => array(
          'header' => 'header',
          'navigation' => 'navigation',
          'highlighted' => 'highlighted',
          'help' => 'help',
          'sidebar_first' => 'sidebar_first',
          'sidebar_second' => 'sidebar_second',
          'footer' => 'footer',
          'content' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('error');
  $export['404'] = $context;

  return $export;
}
