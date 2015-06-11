<?php

namespace d\improvement\debug_info;


/**
 * @implement preprocess_html
 */
function preprocess_html() {
  drupal_register_shutdown_function(
    function () {
      echo '<!-- Page execution time was ' . timer_read('page') . ' ms-->';
    }
  );
}
