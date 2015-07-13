<?php

namespace d\performance\cacheAlias;

/**
 * @implement entity_load
 */

function entity_load($entities, $type) {
  array_walk($entities, function ($entity) use ($type) {
    $path = entity_uri($type, $entity)['path'];
    if ($path && $path !== ($alias = drupal_get_path_alias($path))) {
      $entity->_path['alias'] = $alias;
    }
  });
}

/**
 * @implement entitycache_load
 */

function entitycache_load($entities, $type) {
  global $language;
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['cache'] = &drupal_static('drupal_lookup_path');
  }
  $cache = &$drupal_static_fast['cache'];
  $cache['first_call'] = FALSE;
  $lg = $language->language;
  array_walk($entities, function ($entity) use ($type, &$cache, $lg) {
    if (($path = entity_uri($type, $entity)['path']) && !empty($entity->_path['alias'])) {
      $cache['map'][$lg][$path] = $entity->_path['alias'];
      $cache['no_aliases'][$lg][$path . '/edit'] = 1;
      $cache['no_aliases'][$lg][$path . '/devel'] = 1;
      $cache['map']['und'] = $cache['map'][$lg];
    }
  });
}