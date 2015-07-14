<?php

namespace d\Antipanels\Page\NodeView\Variant;

use d\Antipanels\VariantBase;
use d\Antipanels\RenderInterface;
use d\Twig\Twig;
use Underscore\Underscore as __;

class Photo extends VariantBase implements RenderInterface {

  function access() {
    return $this->context['node']->type === 'photo';
  }

  function preRender() {
    drupal_set_title('');
    $tags = __::flatten($this->context['node']->field_tags) ?: [];
    $tags = entity_load('taxonomy_term', $tags);
    $this->context['tags'] = $tags;
    $this->attached = [
      'js' => [
        [
          'data' => <<<SCRIPT

var switchTo5x=true
jQuery.ajaxSetup({cache: true});
jQuery.getScript('//w.sharethis.com/button/buttons.js', function(){
  stLight.options({publisher: "6ef8bdb3-26ac-4fbf-a188-334548b26038", doNotHash: true, doNotCopy: false, hashAddressBar: false});
})
SCRIPT
          ,
          'type' => 'inline',
          'scope' => 'footer'
        ],
      ],
      'drupal_add_html_head' => [
        [
          [
            "#tag" => 'meta',
            "#attributes" => [
              'property' => 'og:image',
              'content' => file_create_url($this->context['node']->field_photo['und'][0]['uri'])
            ]
          ],
          'og:image'
        ],
        [
          [
            "#tag" => 'meta',
            "#attributes" => [
              'property' => 'og:image:url:width',
              'content' => 640
            ]
          ],
          'og:image:width'
        ],
        [
          [
            "#tag" => 'meta',
            "#attributes" => [
              'property' => 'og:image:height',
              'content' => 640
            ]
          ],
          'og:image:height'
        ],
        [
          [
            "#tag" => 'meta',
            "#attributes" => [
              'property' => 'og:description',
              'content' => isset($this->context['node']->meta['caption']['text']) ? $this->context['node']->meta['caption']['text'] : '',
            ]
          ],
          'og:description'
        ],
      ]
    ];
  }
}
