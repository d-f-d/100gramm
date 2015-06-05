<?php
/**
 * @file
 * pp.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function pp_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'entity_panels_node_photo_default__panel_context_4c7cac64-991f-4669-935d-e15408e08836';
  $handler->task = 'entity_panels';
  $handler->subtask = 'node-photo-default';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '42accdc5-a1c4-47e2-a796-8d46e8978844';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-25a464ac-5f01-4a18-955b-c4d290e17d24';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_photo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'colorbox',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'colorbox_node_style' => '',
        'colorbox_node_style_first' => '',
        'colorbox_image_style' => '',
        'colorbox_gallery' => 'post',
        'colorbox_gallery_custom' => '',
        'colorbox_caption' => 'auto',
        'colorbox_caption_custom' => '',
      ),
      'context' => 'argument_entity_panels_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '25a464ac-5f01-4a18-955b-c4d290e17d24';
    $display->content['new-25a464ac-5f01-4a18-955b-c4d290e17d24'] = $pane;
    $display->panels['middle'][0] = 'new-25a464ac-5f01-4a18-955b-c4d290e17d24';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['entity_panels_node_photo_default__panel_context_4c7cac64-991f-4669-935d-e15408e08836'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'entity_panels_node_photo_full__panel_context_099653f7-315b-4b3d-864d-0971489e99dc';
  $handler->task = 'entity_panels';
  $handler->subtask = 'node-photo-full';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '15',
      'granularity' => 'args',
    ),
  );
  $display->title = '';
  $display->uuid = '22235ba1-394d-454c-bb1c-078f04e8332d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f7e631ef-4079-42ea-ac30-6cdab32681a9';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_photo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'colorbox',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'colorbox_node_style' => '',
        'colorbox_node_style_first' => '',
        'colorbox_image_style' => '',
        'colorbox_gallery' => 'post',
        'colorbox_gallery_custom' => '',
        'colorbox_caption' => 'auto',
        'colorbox_caption_custom' => '',
      ),
      'context' => 'argument_entity_panels_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f7e631ef-4079-42ea-ac30-6cdab32681a9';
    $display->content['new-f7e631ef-4079-42ea-ac30-6cdab32681a9'] = $pane;
    $display->panels['middle'][0] = 'new-f7e631ef-4079-42ea-ac30-6cdab32681a9';
    $pane = new stdClass();
    $pane->pid = 'new-db902818-568a-4a12-9fd2-e9f7f539fc00';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => 'kokoko kekeke',
      'format' => 'plain_text',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'db902818-568a-4a12-9fd2-e9f7f539fc00';
    $display->content['new-db902818-568a-4a12-9fd2-e9f7f539fc00'] = $pane;
    $display->panels['middle'][1] = 'new-db902818-568a-4a12-9fd2-e9f7f539fc00';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f7e631ef-4079-42ea-ac30-6cdab32681a9';
  $handler->conf['display'] = $display;
  $export['entity_panels_node_photo_full__panel_context_099653f7-315b-4b3d-864d-0971489e99dc'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'entity_panels_node_photo_teaser__panel_context_120ce6cd-2b7a-41e8-9fbc-6e8453497b85';
  $handler->task = 'entity_panels';
  $handler->subtask = 'node-photo-teaser';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '15',
      'granularity' => 'context',
    ),
  );
  $display->title = '';
  $display->uuid = '02486d7f-ecfd-4161-908a-17ee990b815f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b8c6a85c-63ef-42a0-a1bd-9e1412aa77ed';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_photo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'medium',
        'image_link' => 'content',
      ),
      'context' => 'argument_entity_panels_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b8c6a85c-63ef-42a0-a1bd-9e1412aa77ed';
    $display->content['new-b8c6a85c-63ef-42a0-a1bd-9e1412aa77ed'] = $pane;
    $display->panels['middle'][0] = 'new-b8c6a85c-63ef-42a0-a1bd-9e1412aa77ed';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b8c6a85c-63ef-42a0-a1bd-9e1412aa77ed';
  $handler->conf['display'] = $display;
  $export['entity_panels_node_photo_teaser__panel_context_120ce6cd-2b7a-41e8-9fbc-6e8453497b85'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__panel_context_c97dedc6-d6a4-4a26-86fc-7806a9246d4f';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'omega:fita-simple';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'highlighted' => NULL,
      'help' => NULL,
      'content' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '62fcffd1-4be4-4c87-93a9-4cb10677b2cc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9e8029ae-f707-4dff-a2bb-9b86ca8c9111';
    $pane->panel = 'content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9e8029ae-f707-4dff-a2bb-9b86ca8c9111';
    $display->content['new-9e8029ae-f707-4dff-a2bb-9b86ca8c9111'] = $pane;
    $display->panels['content'][0] = 'new-9e8029ae-f707-4dff-a2bb-9b86ca8c9111';
    $pane = new stdClass();
    $pane->pid = 'new-48cdf91d-9759-4885-926c-5651f8818b98';
    $pane->panel = 'content';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '48cdf91d-9759-4885-926c-5651f8818b98';
    $display->content['new-48cdf91d-9759-4885-926c-5651f8818b98'] = $pane;
    $display->panels['content'][1] = 'new-48cdf91d-9759-4885-926c-5651f8818b98';
    $pane = new stdClass();
    $pane->pid = 'new-c97c3408-035f-4652-bb1d-da66a926039c';
    $pane->panel = 'content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c97c3408-035f-4652-bb1d-da66a926039c';
    $display->content['new-c97c3408-035f-4652-bb1d-da66a926039c'] = $pane;
    $display->panels['content'][2] = 'new-c97c3408-035f-4652-bb1d-da66a926039c';
    $pane = new stdClass();
    $pane->pid = 'new-03ee1e4c-5577-4ce0-9ece-be3ca93e1056';
    $pane->panel = 'header';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '03ee1e4c-5577-4ce0-9ece-be3ca93e1056';
    $display->content['new-03ee1e4c-5577-4ce0-9ece-be3ca93e1056'] = $pane;
    $display->panels['header'][0] = 'new-03ee1e4c-5577-4ce0-9ece-be3ca93e1056';
    $pane = new stdClass();
    $pane->pid = 'new-f5f847f6-49da-4242-bb83-089a676e4143';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'site top menu',
      'title' => '',
      'body' => '<ul class="menu">
	<li><a href="http://www.facebook.com/DonetskieKartinki" title="">facebook</a></li>
	<li><a href="http://vk.com/public55398565" title="">vk</a></li>
	<li><a href="http://twitter.com" title="">twitter</a></li>
	<li><a href="http://www.odnoklassniki.ru/group/56773223710752" title="">odnoklassniki.ru</a></li>
	<li><a href="/about.html" title="">About</a></li>
</ul>',
      'format' => 'raw_text',
      'substitute' => 0,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'site-top-menu',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f5f847f6-49da-4242-bb83-089a676e4143';
    $display->content['new-f5f847f6-49da-4242-bb83-089a676e4143'] = $pane;
    $display->panels['header'][1] = 'new-f5f847f6-49da-4242-bb83-089a676e4143';
    $pane = new stdClass();
    $pane->pid = 'new-ea735e2e-6967-494c-9cc0-8b0993201e9f';
    $pane->panel = 'help';
    $pane->type = 'block';
    $pane->subtype = 'system-help';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ea735e2e-6967-494c-9cc0-8b0993201e9f';
    $display->content['new-ea735e2e-6967-494c-9cc0-8b0993201e9f'] = $pane;
    $display->panels['help'][0] = 'new-ea735e2e-6967-494c-9cc0-8b0993201e9f';
    $pane = new stdClass();
    $pane->pid = 'new-214b89c2-2bf1-47f8-aa2d-4d4391e45863';
    $pane->panel = 'highlighted';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '214b89c2-2bf1-47f8-aa2d-4d4391e45863';
    $display->content['new-214b89c2-2bf1-47f8-aa2d-4d4391e45863'] = $pane;
    $display->panels['highlighted'][0] = 'new-214b89c2-2bf1-47f8-aa2d-4d4391e45863';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c97c3408-035f-4652-bb1d-da66a926039c';
  $handler->conf['display'] = $display;
  $export['site_template__panel_context_c97dedc6-d6a4-4a26-86fc-7806a9246d4f'] = $handler;

  return $export;
}
