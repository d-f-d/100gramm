<?php
namespace d\Antipanels\TaxonomyTerm;

use d\Antipanels\RenderInterface;
use Drupal\d_submodules\Callback;
use d\Twig\Twig;


class View implements RenderInterface {
  use Callback;

  protected $context = [];

  /**
   * @implement menu_alter
   */
  static function menu_alter(&$menu) {
    $menu['taxonomy/term/%taxonomy_term']['page callback'] = self::getCallbackName('pageCallback');
  }

  function __construct(array $context) {
    $this->context = $context;
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

  function render() {
    $this->preRender();
    return [
      '#markup' => Twig::render(file_get_contents(__DIR__ . '/View.html.twig'), $this->context, __CLASS__),
    ];
  }
}