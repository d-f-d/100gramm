<?php
/**
 * @file
 * features_ds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_ds_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function features_ds_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function features_ds_image_default_styles() {
  $styles = array();

  // Exported image style: photo_grid.
  $styles['photo_grid'] = array(
    'name' => 'photo_grid',
    'effects' => array(
      2 => array(
        'label' => 'Изменение размера',
        'help' => 'Изменение размера, делает изображение соответствующим введённым размерам, без соблюдения исходных пропорций. Это может привести к растягиванию или сплющиванию итогового изображения, если пропорции введённых размеров, не будут соответствовать пропорциям исходного изображения.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 290,
          'height' => 290,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
