<?php

/**
 * Implements hook_preprocess_html().
 */
function fita_preprocess_html(&$variables, $hook) {
//  drupal_add_css(drupal_get_path('theme', 'fita') . "/third-party/jQuery-UI-FileInput/css/enhanced.css", array('group' => CSS_THEME));
  drupal_add_js(drupal_get_path('theme', 'fita') . "/third-party/jQuery-UI-FileInput/js/fileinput.jquery.js", array('group' => JS_THEME));
  drupal_add_js(drupal_get_path('theme', 'fita') . "/js/init.js", array('group' => JS_THEME));
  libraries_load('webhostinghub.glyphs', 'cdn');
}

/**
 * Helper function for loading theme assets in case 'Omega' is the active theme.
 *
 * @see omega_preprocess_html()
 */
function _fita_preprocess_html(&$variables) {
  // @todo
}
