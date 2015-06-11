<?php

namespace d\Antipanels\Page\NodeView\Variant;

use d\Antipanels\RenderInterface;
use d\Antipanels\VariantBase;

class Others extends VariantBase implements RenderInterface {

  function access() {
    return TRUE;
  }

  function render() {
    drupal_set_title($this->context['node']->title);
    return node_view($this->context['node']);
  }
}
