<?php

namespace d\Antipanels;

abstract class FragmentBase implements RenderInterface {
  protected $context = [];

  /**
   * @param array $context
   */
  function __construct(array $context) {
    $this->context = $context;
  }
}

