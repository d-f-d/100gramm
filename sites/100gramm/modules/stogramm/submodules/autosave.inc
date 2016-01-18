<?php

namespace d;

function getTags() {
  yield from['fromdonetsk', 'govoritdonetsk'];
}

function getData() {
  foreach (getTags() as $tag) {
    $request = drupal_http_request(url("https://api.instagram.com/v1/tags/{$tag}/media/recent", [
      'query' => [
        'access_token' => variable_get('stogramm_access_token', NULL),
      ]
    ]));
    $resp = drupal_json_decode($request->data);
    if (!empty($resp['data']) && is_array($resp['data'])) {
      yield from $resp['data'];
    }
  }
}

/**
 * @implement cron
 */
function cron() {
  foreach (getData() as $data) {
    $node = stogramm_get_node($data);
    if (!isset($node->nid)) {
      stogramm_save_image_to_node($data);
    }
  }
}