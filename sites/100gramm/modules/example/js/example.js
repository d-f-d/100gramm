(function ($, D) {
  D.behaviors.kickassPlaceholder = {
    attach : function (content) {
      $('.kickass_placeholder', content).once('kickass_placeholder', function () {
        var settings = {
          url     : D.settings.basePath + D.settings.pathPrefix + 'example/2.0/ajax',
          wrapper : this.id,
          submit  : {
            arg : {form_id : $(this).data('form_id')},
          }
        };
        console.log(settings);
        var ajax = new D.ajax(false, false, settings);
        ajax.eventResponse(ajax, {});
      });
    }
  }
})(jQuery, Drupal);