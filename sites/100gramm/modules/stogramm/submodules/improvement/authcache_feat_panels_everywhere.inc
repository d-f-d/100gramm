<?php

namespace d\improvement\authcache_feat_panels_everywhere;

/**
 * @implement preprocess_panels_everywhere_page
 */

function cache_cancel(&$var) {
  if (!empty($_SESSION['messages'])) {
    authcache_cancel(t('Status message on page'));
  }
}
