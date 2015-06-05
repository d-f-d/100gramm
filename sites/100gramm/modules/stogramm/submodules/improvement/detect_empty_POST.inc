<?php

namespace d\improvement\detect_empty_POST;

/**
 * @implement boot
 */
function detect() {
  if (request_path() === "system/ajax" && empty($_POST)) {
    require_once 'includes/common.inc';
    if ($_SERVER['CONTENT_LENGTH'] > parse_size(ini_get('post_max_size'))) {
      $error['code'] = 413;
      $error['message'] = 'Request Entity Too Large';
    }
    else {
      $error['code'] = 418;
      $error['message'] = "I'm a teapot";
    }
    ob_end_clean();
    drupal_add_http_header('Status', "{$error['code']} {$error['message']}");
    drupal_add_http_header('Content-Type', 'application/json; charset=utf-8');
    exit(drupal_json_encode([['command' => 'error', 'error' => $error]]));
  }
}