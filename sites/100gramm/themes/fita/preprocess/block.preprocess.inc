<?php

/**
 * Implements hook_preprocess_block().
 */
function fita_preprocess_block(&$variables) {
  $variables['attributes_array']['class'][] = 'clearfix';
}
