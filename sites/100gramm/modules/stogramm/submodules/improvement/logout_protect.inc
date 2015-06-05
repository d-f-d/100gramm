<?php

namespace d\improvement\logout_protect;

use  Drupal\d_submodules\Submodules;

/**
 * @param $items
 * @implement menu_alter
 */
function menu_alter(&$items) {
  $items['user/logout']['access callback'] = Submodules::generateCallbackName(__NAMESPACE__ . '\access');
}

/**
 * @implement callback
 */
function access() {
  return user_is_logged_in() && isset($_GET['token']) && drupal_get_token() === $_GET['token'];
}
