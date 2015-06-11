<?php

namespace d\Antipanels\Page\NodeView;

use d\Antipanels\RenderInterface;
use d\Antipanels\RenderVariant;
use Drupal\d_submodules\Callback;

class NodeView implements RenderInterface {

  use RenderVariant;
  use Callback;

  protected $context = [];

  static $variants = [
    'photo' => 'd\Antipanels\Page\NodeView\Variant\Photo',
    'others' => 'd\Antipanels\Page\NodeView\Variant\Others',
  ];

  /**
   * @param array $context
   */
  function __construct(array $context) {
    $this->context = $context;
  }

  /**
   * !@implement menu
   */
  static function menu() {
    return [
      'd/node/%node' => [
//        'title' => FALSE,
        'page callback' => self::getCallbackName('pageCallback'),
        'page arguments' => [2],
        'access callback' => TRUE,
        'type' => MENU_NORMAL_ITEM
      ]
    ];
  }

  /**
   * @implement menu_alter
   */
  static function menu_alter(&$menu) {
    $menu['node/%node']['page callback'] = self::getCallbackName('pageCallback');
//    unset($menu['node/%node']['title callback']);
//    unset($menu['node/%node']['title arguments']);
  }

  /**
   * @implement callback
   */
  static function pageCallback($node) {
    $self = get_called_class();
    return (new $self(['node' => $node]))->render();
  }
}