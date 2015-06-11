<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * omega-base theme.
 */

function fita_css_alter(&$css) {
  $fita = drupal_get_path('theme', 'fita');
  foreach ($css as $k => $style) {
    $n = $k;
    $n = preg_replace('/.*system.messages.*/', $fita . '/css/modules/system/system.messages.theme.css', $n);
    if ($n != $k) {
      $css[$k]['data'] = $n;
      $css[$n] = $css[$k];
      unset($css[$k]);
    }
  }
}

function fita_preprocess_views_view_table(&$vars) {
  $vars['classes_array'][] = 'table';
}

