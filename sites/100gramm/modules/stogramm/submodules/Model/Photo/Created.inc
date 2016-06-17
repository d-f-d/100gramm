<?php

namespace d\Model\Photo;

class Created {

  /**
   * @implement node_presave
   */
  static function fix($node) {
    if (isset ($node->meta['created_time'])) {
      $node->created = $node->meta['created_time'];
    }
  }
}