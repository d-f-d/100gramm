<?php

namespace d\Model\Photo;

class Tags {

  /**
   * @implement node_presave
   */
  static function create($node) {
    $vid = taxonomy_vocabulary_machine_name_load('tags')->vid;
    $node->meta['tags'] = $node->meta['tags'] ?: ['fromdonetsk'];
    $exist_tags = db_select('taxonomy_term_data', 't')
      ->fields('t', [
        'name',
        'tid'
      ])
      ->condition('name', $node->meta['tags'], 'in')
      ->condition('vid', $vid)
      ->execute()
      ->fetchAllAssoc('name');
    unset($node->field_tags);
    foreach ($node->meta['tags'] as $tag_name) {
      if (isset($exist_tags[$tag_name])) {
        $node->field_tags['und'][]['tid'] = $exist_tags[$tag_name]->tid;
      }
      else {
        $tag = entity_create('taxonomy_term', [
          'name' => $tag_name,
          'vid' => $vid
        ]);
        entity_save('taxonomy_term', $tag);
        $node->field_tags['und'][]['tid'] = $tag->tid;
      }
    }
  }
}