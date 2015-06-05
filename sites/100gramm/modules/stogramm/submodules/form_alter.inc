<?php

namespace d\supadupa_alter;

use  Drupal\d_submodules\Submodules;

/**
 * @param $form
 * @return mixed
 * @implement form_alter
 * @form_id supadupa_form
 */
function form(&$form) {
  $form['#submit'][] = __FUNCTION__ . '_submit';
  $form['input'] = [
    '#type' => 'textfield',
    '#default_value' => __FUNCTION__,
    '#element_validate' => [Submodules::generateCallbackName(__FUNCTION__ . '_input_validate')]
  ];
  $form['#validate'][] = Submodules::generateCallbackName(__FUNCTION__ . '_validate');

  $form['submit']['#ajax'] = [
    'callback' => Submodules::generateCallbackName(__FUNCTION__ . '_ajax'),
    'wrapper' => $form['#id'],
    'method' => 'replace',
  ];
}

/**
 * @implement callback
 * @return NULL
 */
function form_submit() {
  dsm(__FUNCTION__);
}

/**
 * @implement callback
 * @return NULL
 */
function form_validate() {
  dsm(__FUNCTION__);
}

/**
 * @implement callback
 * @return NULL
 */
function form_input_validate() {
  dsm(__FUNCTION__);
}
