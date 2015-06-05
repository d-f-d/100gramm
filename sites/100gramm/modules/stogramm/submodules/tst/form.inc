<?php

namespace d\supadupa;

use d\SimpleForm;
use Drupal\d_submodules\SelfPath;

class supadupa extends SimpleForm {
  use SelfPath;
  /**
   * @param array $form
   * @param array $forms_tate
   * @return array
   * @implement form
   * @form_id supadupa_form
   */
  static function form(array $form, array &$form_state) {
    $form = parent::form($form, $form_state);

    $form[]['#markup'] = '#' . __CLASS__ . '<br>';
    $form[]['#markup'] = '#' . self::getSelfPath() . '<br>';
    $form['submit'] = [
      '#type' => 'submit',
      '#value' => 'submit'
    ];
    return $form;
  }

  /**
   * @implement callback
   */
  static function form_submit() {
    dsm(__CLASS__ . '::' . __FUNCTION__);
  }
}
