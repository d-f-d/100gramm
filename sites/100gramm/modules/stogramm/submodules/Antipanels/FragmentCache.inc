<?php

namespace d\Antipanels;

trait FragmentCache {
  protected $cacheKey = '';
  protected $cacheTime = 15;

  function render() {
    $key = get_called_class() . $this->cacheKey;
    if (!(($cache = cache_get($key)) && ($cache->expire > REQUEST_TIME) && ($data = $cache->data))) {
      $data = parent::render();
      cache_set($key, $data, 'cache', REQUEST_TIME + $this->cacheTime);
    }
    return $data;
  }
}