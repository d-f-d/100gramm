<?php
/**
 * @file
 * features_ds.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function features_ds_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'cackle_comments' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'like_it' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'photografer' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'description' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'photo__created_time' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'photo__tags' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'share_it' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|photo|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function features_ds_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cackle_comments';
  $ds_field->label = 'cackle_comments';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div id="mc-container"></div>
<script type="text/javascript">
var mcSite = \'22815\';
var mcChannel = \'node-<?=$entity->nid?>\';
    var mc = document.createElement(\'script\');
    mc.type = \'text/javascript\';
    mc.async = true;
    mc.src = \'//cackle.me/mc.widget-min.js\';
    (document.getElementsByTagName(\'head\')[0] || document.getElementsByTagName(\'body\')[0]).appendChild(mc);
</script>
<a href="http://cackle.me" id="mc-link">система комментирования <b style="color:#4FA3DA">CACKL</b><b style="color:#F65077">E</b></a>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['cackle_comments'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'description';
  $ds_field->label = 'photo-description';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'photo|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?= isset($entity->meta[\'caption\'][\'text\'])?$entity->meta[\'caption\'][\'text\']:NULL;?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['description'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'discus_comments';
  $ds_field->label = 'discus-comments';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '    <div id="disqus_thread"></div>
    <script type="text/javascript">
        /* * * CONFIGURATION VARIABLES: EDIT BEFORE PASTING INTO YOUR WEBPAGE * * */
        var disqus_shortname = \'100grammdonetsk\'; // required: replace example with your forum shortname

        /* * * DON\'T EDIT BELOW THIS LINE * * */
        (function() {
            var dsq = document.createElement(\'script\'); dsq.type = \'text/javascript\'; dsq.async = true;
            dsq.src = \'//\' + disqus_shortname + \'.disqus.com/embed.js\';
            (document.getElementsByTagName(\'head\')[0] || document.getElementsByTagName(\'body\')[0]).appendChild(dsq);
        })();
    </script>
    <noscript>Please enable JavaScript to view the <a href="http://disqus.com/?ref_noscript">comments powered by Disqus.</a></noscript>
    <a href="http://disqus.com" class="dsq-brlink">comments powered by <span class="logo-disqus">Disqus</span></a>
    ',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['discus_comments'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'like_it';
  $ds_field->label = 'like_it';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<span class=\'st_fblike_hcount\' displayText=\'Facebook\'></span>
<span class=\'st_twitter_hcount\' displayText=\'Tweet\'></span>
<span class=\'st_plusone_hcount\' displayText=\'Google +1\'></span>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['like_it'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'photo__created_time';
  $ds_field->label = 'photo__created_time';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'photo|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?=format_date($entity->meta[\'created_time\'])?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['photo__created_time'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'photo__tags';
  $ds_field->label = 'photo__tags';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'photo|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?
foreach ($entity->meta[\'tags\'] as $tag){
echo "<span class=tag>#$tag</span> ";
}
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['photo__tags'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'photografer';
  $ds_field->label = 'Автор фото';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'photo|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<figuret>
<img src=\'<?=$entity->meta[\'user\'][\'profile_picture\']?>\'>
<figcaption><?=l($entity->meta[\'user\'][\'username\'], \'//instagram.com/\'.$entity->meta[\'user\'][\'username\'], array(\'attributes\'=>array(\'rel\'=> array(\'nofollow\', \'me\'),\'target\'=>\'_blank\')))?></figcaption>
</figure>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['photografer'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'share_it';
  $ds_field->label = 'share_it';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<script type="text/javascript">var switchTo5x=true;</script>
<script type="text/javascript" src="http://w.sharethis.com/button/buttons.js"></script>
<script type="text/javascript">stLight.options({publisher: "6ef8bdb3-26ac-4fbf-a188-334548b26038", doNotHash: true, doNotCopy: false, hashAddressBar: false});</script>
<span class=\'st_facebook_large\' displayText=\'Facebook\'></span>
<span class=\'st_vkontakte_large\' displayText=\'Vkontakte\'></span>
<span class=\'st_googleplus_large\' displayText=\'Google +\'></span>
<span class=\'st_livejournal_large\' displayText=\'LiveJournal\'></span>
<span class=\'st_twitter_large\' displayText=\'Tweet\'></span>
<span class=\'st_linkedin_large\' displayText=\'LinkedIn\'></span>
<span class=\'st_mail_ru_large\' displayText=\'mail.ru\'></span>
<span class=\'st_odnoklassniki_large\' displayText=\'Odnoklassniki\'></span>
<span class=\'st_pinterest_large\' displayText=\'Pinterest\'></span>',
      'format' => 'raw_text',
    ),
    'use_token' => 0,
  );
  $export['share_it'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function features_ds_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_photo',
      ),
      'right' => array(
        1 => 'like_it',
        2 => 'photografer',
        3 => 'photo__created_time',
        4 => 'photo__tags',
        5 => 'description',
      ),
      'footer' => array(
        6 => 'share_it',
        7 => 'cackle_comments',
      ),
    ),
    'fields' => array(
      'field_photo' => 'left',
      'like_it' => 'right',
      'photografer' => 'right',
      'photo__created_time' => 'right',
      'photo__tags' => 'right',
      'description' => 'right',
      'share_it' => 'footer',
      'cackle_comments' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => 'role="article"',
    'layout_attributes_merge' => 0,
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|photo|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|thumb';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'thumb';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_photo',
      ),
    ),
    'fields' => array(
      'field_photo' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => 'style = \'position:relative\'',
    'layout_attributes_merge' => 1,
  );
  $export['node|photo|thumb'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function features_ds_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'thumb';
  $ds_view_mode->label = 'thumb';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['thumb'] = $ds_view_mode;

  return $export;
}
