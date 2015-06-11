<?php

namespace d\Antipanels\Everywhere;

use d\Antipanels\RenderInterface;
use d\Antipanels\VariantBase as AbstractVariantBase;

abstract class VariantBase extends AbstractVariantBase implements RenderInterface {
  function preRender() {
    $this->context['title'] = drupal_get_title();
    $this->context['logo'] = theme_get_setting('logo');
    $this->context['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => drupal_get_breadcrumb()));
    $this->context['messages'] = theme('status_messages');
    $this->context['tabs'] = menu_local_tabs();
  }
}