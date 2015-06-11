<?php

namespace d\Antipanels;

interface VariantInterface {

  /**
   * @param array $context
   */
  function __construct(array $context);

  /**
   * @return boolean
   */
  function access();

  /**
   * @return array
   */
  function render();
}