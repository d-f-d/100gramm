<?php

namespace d\Antipanels;

trait RenderVariant {
  function render() {
    foreach (static::$variants as $variant) {
      $display = new $variant($this->context);
      if ($display->access()) {
//        _log(0, 1);
        $output = $display->render();
//        _log($variant);
        return $output;
      }
    }
    return [];
  }
}