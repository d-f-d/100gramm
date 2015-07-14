<?php
namespace d\Antipanels\TaxonomyTerm;

use d\Antipanels\RenderBase;
use Drupal\d_submodules\Callback;


class View extends RenderBase {
  use Callback;

  protected $context = [];

  /**
   * @implement menu_alter
   */
  static function menu_alter(&$menu) {
    $menu['taxonomy/term/%taxonomy_term']['page callback'] = self::getCallbackName('pageCallback');
  }

  /**
   * @implement callback
   */
  static function pageCallback($term) {
    $self = get_called_class();
    return (new $self(['term' => $term]))->render();
  }

  function preRender() {
    if ($nids = taxonomy_select_nodes($this->context['term']->tid, TRUE, 12)) {
      $this->context['nodes'] = node_load_multiple($nids);
    }
  }
}