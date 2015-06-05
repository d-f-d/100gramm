<?php

namespace Drupal\d_submodules;

/**
 * @implement flush_caches
 */

function reset() {
  variable_set('d_submodules_reset', TRUE);
}