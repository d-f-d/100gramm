<?php

namespace d\Antipanels;

use d\Twig\Twig;
use Drupal\d_submodules\SelfPath;

abstract class RenderBase implements RenderInterface {
  use SelfPath;

  protected $context = [];
  protected $attached = [];
  protected $templateName = NULL;
  protected $templateDir = [];

  /**
   * @param array $context
   */
  function __construct(array $context = []) {
    $this->context = array_merge($this->context, $context);
    $this->templateName = $this->templateName ?: (new \ReflectionClass($this))->getShortName();
    $selfPath = self::getSelfPath(get_called_class());
    $this->templateDir = [
      $selfPath,
      __DIR__ . '/Fragment',
    ];
    if (is_dir($selfPath . '/Fragment')) {
      array_unshift($this->templateDir, $selfPath . '/Fragment');
    }
  }

  function preRender() {

  }

  function render() {
    $this->preRender();
    return [
      '#attached' => $this->attached,
      Twig::renderFile($this->templateDir, $this->context, $this->templateName . '.html.twig')
    ];
  }
}

