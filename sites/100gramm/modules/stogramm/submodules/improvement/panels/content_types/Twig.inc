<?php

/**
 * Created by PhpStorm.
 * User: punk_undead
 * Date: 09.06.15
 * Time: 22:10
 */

namespace d\panels\content_types;

class Twig {
  use \Drupal\d_submodules\Callback;

  /**
   * @owner ctools
   * @plugin content_types
   */
  static function plugin() {
    return [
      __CLASS__ => [
        'title' => ('Twig'),
        'single' => TRUE,
        'render callback' => self::getCallbackName('render'),
        'edit form' => self::getCallbackName('settings_form'),
        'admin info' => self::getCallbackName('adminInfo'),
        'description' => 'Twig formatted',
        'category' => t('D content'),
        'all contexts' => TRUE,
        'defaults' => array(
          'content' => '',
          'admin_title' => '',
        ),
      ]
    ];
  }

  /**
   * @implement callback
   */
  static function settings_form($form, &$form_state) {
    $conf = &$form_state['conf'];
    $form['content'] = [
      '#type' => 'textarea',
      '#title' => 'Twigggable content',
      '#default_value' => $conf['content'],
    ];
    $form['admin_title'] = [
      '#type' => 'textfield',
      '#title' => 'Admin title',
      '#default_value' => @$conf['admin_title'],
    ];

    return $form;
  }

  /**
   * @implement callback
   */
  static function settings_form_submit($form, &$form_state) {
    foreach ($form_state['plugin']['defaults'] as $k => $v) {
      $form_state['conf'][$k] = $form_state['values'][$k];
    }
  }

  /**
   * @implement callback
   */
  static function render($subtype, $conf, $args, $contexts) {
    $block = new \stdClass();
    $context_keywords = [];
    foreach ($contexts as $context) {
      if (isset($context->keyword)) {
        $context_keywords[$context->keyword] = $context->data;
      }
    }
    $loader = new \Twig_Loader_Array(array(
      'content' => $conf['content'],
    ));
    $twig = new \Twig_Environment($loader, ['cache' => variable_get('file_private_path', variable_get('file_public_path', conf_path() . '/files')) . '/.ht.twig_cache']);
    $block->content[] = ['#markup' => $twig->render('content', $context_keywords)];
    return $block;
  }

  /**
   * @implement callback
   */
  static function adminInfo($subtype, $conf){
    $block = new \stdClass();
    $block->title = @$conf['admin_title'];
    $block->content = '<pre>' . check_plain($conf['content']) . '</pre>';
return $block;
  }
}