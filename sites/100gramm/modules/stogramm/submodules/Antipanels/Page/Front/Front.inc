<?php
namespace d\Antipanels\Page\Front;

use d\Antipanels\RenderBase;
use Drupal\d_submodules\Callback;


class Front extends RenderBase {
  use Callback;

  protected $context = [];

  /**
   * @implement menu
   * @return array
   */
  static function menu() {
    return [
      'front' => [
//        'title' => FALSE,
        'page callback' => self::getCallbackName('pageCallback'),
        'page arguments' => [2],
        'access callback' => TRUE,
        'type' => MENU_NORMAL_ITEM
      ]
    ];
  }

  /**
   * @implement callback
   */
  static function pageCallback() {
    $self = get_called_class();
    return (new $self())->render();
  }

  function preRender() {
    $nids = db_select('node')
      ->fields('node', ['nid'])
      ->orderBy('created', 'DESC')
      ->condition('type', 'photo')
      ->condition('status', 1)
      ->extend('PagerDefault')
      ->limit(12)
      ->execute()
      ->fetchCol();
    $this->context['nodes'] = node_load_multiple($nids);
  }

}