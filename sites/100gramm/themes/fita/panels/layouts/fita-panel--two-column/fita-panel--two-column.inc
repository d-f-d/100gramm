<?php

// Plugin definition.
$plugin = array(
  'title' => t('Two column (no style)'),
  'category' => t('Fita content layouts'),
  'theme' => 'fita-panel--two-column',
  'icon' => 'fita-panel--two-column.png',
  'css' => 'fita-panel--two-column.css',
  'regions' => array(
    'header' => t('Header'),
    'section_first' => t('First section'),
    'section_second' => t('Second section'),
    'footer' => t('Footer'),
  ),
);
