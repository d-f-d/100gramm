<?php

namespace Drupal\d_submodules;

trait SelfPath {
  static function getSelfPath($class = __CLASS__) {
    return dirname(Submodules::getClassMap()[$class]);
  }
}