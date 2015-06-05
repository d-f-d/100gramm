<?php

namespace d\improvement\menu_rebuild;

/**
 * @implement flush_caches
 */
function rebuild() {
  db_delete('menu_links')->condition('menu_name', 'management')->execute();
  menu_rebuild();
}