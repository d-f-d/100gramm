<?php

function fita_preprocess_field(&$variables) {
  $field = &$variables['element'];
  $et = $field['#entity_type'];
  $eb = $field['#bundle'];
  $evm = $field['#view_mode'];
  $fnc = $field['#field_name'];
  $variables['classes_array'] = [
    drupal_html_class("e-{$et}--b-{$eb}--v-{$evm}__f-{$fnc}"),
    drupal_html_class("e-{$et}--b-{$eb}__f-{$fnc}"),
    drupal_html_class("e-{$et}--v-{$evm}__f-{$fnc}"),
    drupal_html_class("e-{$et}__f-{$fnc}"),
    drupal_html_class("f-{$fnc}")
  ];
}


