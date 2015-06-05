<?php

namespace d\performance\opcache_reset;

/**
 * @implement flush_caches
 */

function reset() {
  if (function_exists('opcache_reset')) {
    opcache_reset();
  }
}