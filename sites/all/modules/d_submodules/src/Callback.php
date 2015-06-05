<?php

namespace Drupal\d_submodules;

trait Callback {
  static function getCallbackName($method) {
    return Submodules::generateCallbackName(get_called_class() . '::' . $method);
  }
}