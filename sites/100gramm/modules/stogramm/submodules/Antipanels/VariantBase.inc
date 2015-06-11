<?php

namespace d\Antipanels;

abstract class VariantBase implements VariantInterface, RenderInterface {
  protected $context = [];

  /**
   * @param array $context
   */
  function __construct(array $context) {
    $this->context = $context;
  }
}