<?php

namespace d\Antipanels\Everywhere;

use d\Antipanels\RenderInterface;
use d\Antipanels\RenderVariant;
use Drupal\d_submodules\Callback;

class Everywhere implements RenderInterface {

  use RenderVariant;
  use Callback;

  protected $context = [];
  static $variants = [
    'photo' => 'd\Antipanels\Everywhere\Variant\Main',
    'others' => 'd\Antipanels\Everywhere\Variant\Others',
  ];


  function __construct(array $context) {
    $this->context = $context;
  }

  /**
   * @implement theme
   */

  static function theme() {
    return [
      __CLASS__ => [
        'render element' => 'page',
        'function' => self::getCallbackName('page_render')
      ]
    ];
  }

  /**
   * @implement page_build
   */
  static function page_build(&$page) {
    if (!path_is_admin(current_path())) {
      $page['#theme'] = __CLASS__;
    }
  }

  /**
   * @implement callback
   */
  static function page_render($variables) {
    $self = get_called_class();
    return render((new $self(['page' => $variables['page']]))->render());
  }
}