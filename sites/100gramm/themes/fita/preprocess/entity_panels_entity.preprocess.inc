<?php

function fita_preprocess_entity_panels_entity(&$variables) {
  $element = $variables['element'];
  $entity_type = $element['#entity_panels_entity_type'];
  $bundle = $element['#entity_panels_bundle'];
  $view_mode = $element['#entity_panels_view_mode'];
  $variables['classes_array'] = [
    drupal_html_class('e-' . $entity_type . '--v-' . $view_mode),
    drupal_html_class('e-' . $entity_type . '--b-' . $bundle . '--v-' . $view_mode),
    drupal_html_class('e-' . $entity_type . '--b-' . $bundle),
  ];
}
