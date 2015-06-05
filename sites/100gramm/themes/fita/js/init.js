(function ($, D) {
  D.behaviors.inputUI = {
    attach : function (context) {
      $('input[type=radio], input[type=checkbox]', context).once('inputUI',
        function () {
          $(this).wrap('<span class=inputUI-wrap></span>').after('<a class=ui-' + this.type + '></a>');
        })
    }
  };

//  D.behaviors.numerateMenu = {
//    attach : function (context) {
//      $('.menu', context).once('numerate', function () {
//        $(this)
//          .addClass('level-' + $(this).parents('.menu').length)
//          .children().each(function (i) { $(this).addClass('element-' + i); });
//      });
//    }
//  };

//  $.fn.button && (D.behaviors.uiButton = {
//    attach : function (context) {
//      $('input[type=submit], .button, button', context)
//        .not('.not-ui').not(':disabled')
//        .button()
//        .filter("[value='" + D.t('Delete') + "'], [value='" + D.t('Remove') + "']").button({icons : {primary : 'ui-icon-trash'}}).end()
//        .filter("[value='" + D.t('Upload') + "']").button({icons : {primary : 'ui-icon-circle-arrow-n'}}).end()
//        .filter("[value='" + D.t('Save') + "']").button({icons : {primary : 'ui-icon-disk'}}).end()
//        .filter("[value='" + D.t('Preview') + "']").button({icons : {primary : 'ui-icon-arrowrefresh-1-s'}}).end()
//        .filter("[value='" + D.t('Log in') + "']").button({icons : {primary : 'ui-icon-person'}}).end();
//    }
//  });

  $.fn.customFileInput && (D.behaviors.customFileInput = {
    attach : function (context) {
      $('input[type=file]', context).once('customfile-input').customFileInput();
    }
  });

  $(function () { });
})(jQuery, Drupal);