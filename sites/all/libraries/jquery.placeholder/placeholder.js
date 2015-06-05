(function ($) {
  Drupal.behaviors.placeholder = {
    attach:function (context, settings) {
      $('input[placeholder],textarea[placeholder]', context).placeholder();
    }
  };
}(jQuery));