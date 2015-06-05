(function ($, D) {
  "use strict";
  D.libraries_load = function () {
    var libraries, test = 1, callback = $.noop;
    if (!arguments.length) {
      return;
    }
    else {
      libraries = arguments[0];
    }
    if (arguments.length == 2) {
      callback = $.isFunction(arguments[1]) ? arguments[1] : $.noop;
      test = $.isFunction(arguments[1]) ? 1 : arguments[1];
    }
    if (arguments.length == 3) {
      test = arguments[1];
      callback = arguments[2];
    }
    if (!test) {
      callback();
      return;
    }
    D.data_load('libraries_loader/' + libraries, function (data) {
      var behaviors = $.extend({}, D.behaviors);
      var settings = {};
      var resources = [];
      $.each(data, function (i, response) {
        switch (response.command) {
          case 'settings' :
            settings = response.settings;
            break;
          case 'add_css' :
            D.settings.ajaxPageState.css[response.name] || resources.push(response.data);
            break;
          case 'add_js' :
            D.settings.ajaxPageState.js[response.name] || resources.push(response.data);
            break;
        }
      });
      D.settings = $.extend(true, D.settings, settings);
      var cache = $.ajaxSetup().cache;
      $.ajaxSetup({cache : true});
      $('head').append(resources);
      $.ajaxSetup({cache : cache});
      $.each(D.behaviors, function (i, b) { behaviors[i] || b.attach(document) });
    });
    D.data_load('libraries_loader/' + libraries, function () {callback()});
  }
})(jQuery, Drupal);

(function ($, D) {
  "use strict";
  var callbacks = {};
  D.data_load = function (request) {
    var callback = $.isFunction(arguments[1]) ? arguments[1] : $.noop;
    var dataType = arguments[2] ? arguments[2] : 'JSON';
    if (!callbacks[request]) {
      callbacks[request] = $.Callbacks('memory');
      if (window.sessionStorage && !window.sessionStorage.getItem(request)) {
        callbacks[request].add(function (data) {
          sessionStorage.setItem(request, JSON.stringify(data));
        });
      }
      if (window.sessionStorage && window.sessionStorage.getItem(request)) {
        callbacks[request].fire(JSON.parse(window.sessionStorage.getItem(request)))
      }
      else {
        $.get(D.settings.basePath + D.settings.pathPrefix + request + '?' + D.settings.queryString, callbacks[request].fire, dataType);
      }
    }
    callbacks[request].add(callback);
  }
})(jQuery, Drupal);

(function (D, $) {
  if (window.sessionStorage && sessionStorage.getItem('queryString') !== D.settings.queryString) sessionStorage.clear();
  sessionStorage.setItem('queryString', D.settings.queryString);
  $.Topic('head.ready').publish();
})(Drupal, jQuery);