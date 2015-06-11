<?php

namespace d\Antipanels\Everywhere\Variant;

use d\Antipanels\RenderInterface;
use d\Antipanels\Everywhere\VariantBase;
use d\Twig\Twig;

class Main extends VariantBase implements RenderInterface {

  function access() {
    return TRUE;
  }

  function render() {
    $this->preRender();
    return Twig::render(file_get_contents(__DIR__ . '/Main.html.twig'), $this->context, 'page--v-main');
  }
}
