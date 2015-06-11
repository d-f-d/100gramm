<?php
namespace d\improvement\panels\field;

use Drupal\d_submodules\Callback;

class ViewMode {
  use Callback;

  /**
   * @param $form
   * @param $form_state
   * @implement form_alter
   * @form_id ctools_entity_field_content_type_formatter_options
   */
  static function form_alter(&$form, &$form_state) {
    $form['view_mode'] = [
      '#type' => 'textfield',
      '#title' => 'view mode',
      '#default_value' => isset($form_state['conf']['view_mode']) ? $form_state['conf']['view_mode'] : ''
    ];
    $form['#submit'][] = self::getCallbackName('submit');
  }

  /**
   * @param $form
   * @param $form_state
   * @implement callback
   */
 static function submit(&$form, &$form_state) {
    $form_state['conf']['view_mode'] = $form_state['values']['view_mode'];
  }

  /**
   * @param $result
   * @param $context
   * @implement field_attach_view_alter
   */
 static function restoreViewMode(&$result, &$context){
    if (isset($context['display']['pane_settings']['view_mode']) && $context['display']['pane_settings']['view_mode']) {
      $result['field_photo']['#view_mode'] = $context['display']['pane_settings']['view_mode'];
    }
  }
}