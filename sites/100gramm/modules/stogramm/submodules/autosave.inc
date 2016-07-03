<?php

namespace d;

function getTags() {
  yield 'fromdonetsk';
  yield 'govoritdonetsk';
}

function getData() {
  foreach (getTags() as $tag) {
//    $request = drupal_http_request(url("https://api.instagram.com/v1/tags/{$tag}/media/recent", [
//      'query' => [
//        'access_token' => variable_get('stogramm_access_token', NULL),
//      ]
//    ]));
//    $resp = drupal_json_decode($request->data);
//    if (!empty($resp['data']) && is_array($resp['data'])) {
//      foreach($resp['data'] as $data)
//      yield $data;
//    }
    $request = drupal_http_request(url("https://api.vk.com/method/photos.search", [
      'query' => [
        'q'     => "#$tag",
        'sort'  => 0,
        'count' => 10,
        'v'     => '5.52'
      ]
    ]));
    $resp = drupal_json_decode($request->data)['response'];
    if (!empty($resp['items']) && is_array($resp['items'])) {
      foreach ($resp['items'] as $data) {
        yield $data;
      }
    }
  }
}

/**
 * @implement cron
 */
function cron() {
  foreach (getData() as $data) {
    $node = stogramm_get_node(['id' => 'vk-img-' . $data['id']]);
    if (!isset($node->nid)) {
      vkgramm_save_image_to_node($data);
    }
  }
}