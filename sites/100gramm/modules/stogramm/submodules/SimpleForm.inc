<?php

namespace d;

use Drupal\d_submodules\SelfPath;

class SimpleForm extends \Drupal\d_submodules\BaseForm {
  use SelfPath;

  static function form(array $form, array &$form_state) {
    $form = parent::form($form, $form_state);
    $form[] = ['#markup' => '!' . __CLASS__ . '<br>', '#weight' => -100];
    $form[] = ['#markup' => '!' . self::getSelfPath() . '<br>', '#weight' => -100];
    $form['#submit'][] = self::getCallbackName('test_parent_callback');
    return $form;
  }

  /**
   * @implement callback
   * @return null
   */
  static function test_parent_callback() {
    dsm(__CLASS__ . '::' . __FUNCTION__);
  }
}