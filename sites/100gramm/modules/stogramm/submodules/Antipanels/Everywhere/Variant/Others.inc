<?php

namespace d\Antipanels\Everywhere\Variant;

use d\Antipanels\RenderInterface;
use d\Antipanels\Everywhere\VariantBase;

class Others extends VariantBase implements RenderInterface {

  function access() {
    return TRUE;
  }

  function render() {
    return theme('page', $this->context['page']);
  }
}
