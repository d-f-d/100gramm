<?php
function fita_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));
  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  $element['#attributes']['class'][] = 'btn';
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }
  if (strpos($element['#attributes']['id'], 'panel') === FALSE) {
    return ' <button' . drupal_attributes($element['#attributes']) . ' >' . $element["#value"] . '</button> ';
  }
  else {
    return '<input type=submit' . drupal_attributes($element['#attributes']) . ' />';
  }
}
