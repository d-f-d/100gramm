<?php

namespace d\Antipanels\Fragment;

use d\Antipanels\FragmentBase;

class CackleComments extends FragmentBase {

  function render() {
    return [
      '#markup' => '<div id=mc-container></div>',
      '#attached' => [
        'js' => [
          [
            'data' => <<<CODE
  var mcSite = '22815';
  var mcChannel = 'node-{$this->context['node']->nid}';
  var mc = document.createElement('script');
  mc.type = 'text/javascript';
  mc.async = true;
  mc.src = '//cackle.me/mc.widget-min.js';
  (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(mc);
CODE
            ,
            'type' => 'inline',
            'scope' => 'footer'
          ],
        ],
      ]
    ];
  }
}