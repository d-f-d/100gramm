<?php

namespace d\performance\cachePreload;

/**
 * @implement boot
 */
function boot() {
  drupal_static('ctools_export_load_object_table_exists',
    [
      'page_manager_pages' => 1,
      'page_manager_handlers' => 1,
      'panels_renderer_pipeline' => 1,
      'ctools_custom_content' => 1,
      'views_view' => 1
    ]
  );
  $cache_libraries_object = _cache_get_object('cache_libraries');
  if (method_exists($cache_libraries_object, 'getAll')) {
    $cache_libraries_object->getAll();
  }
}
