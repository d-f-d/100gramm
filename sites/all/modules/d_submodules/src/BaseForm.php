<?php

namespace Drupal\d_submodules;

class BaseForm {
  use Callback;
  static function form(array $form, array &$form_state) {
    if (method_exists(get_called_class(), 'form_submit')) {
      $form['#submit'][] = self::getCallbackName('form_submit');
    }
    if (method_exists(get_called_class(), 'form_validate')) {
      $form['#validate'][] = self::getCallbackName('form_validate');
    }
    return $form;
  }
}