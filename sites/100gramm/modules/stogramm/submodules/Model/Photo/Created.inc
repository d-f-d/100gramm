<?php

namespace d\Model\Photo;

class Created {

  /**
   * @implement node_presave
   */
  static function fix($node) {
    $node->created = $node->meta['created_time'];
  }
}