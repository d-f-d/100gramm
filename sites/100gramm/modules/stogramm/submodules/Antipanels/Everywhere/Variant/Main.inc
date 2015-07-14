<?php

namespace d\Antipanels\Everywhere\Variant;

use d\Antipanels\RenderInterface;
use d\Antipanels\Everywhere\VariantBase;

class Main extends VariantBase implements RenderInterface {
  function access() {
    return TRUE;
  }
}
