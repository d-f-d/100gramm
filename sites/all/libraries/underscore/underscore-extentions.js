(function (_) {
  _.mixin({
    queue : function (f, timeout) {
      var nextCall = 0;
      return function () {
        var time = new Date().getTime();
        nextCall = _.max([nextCall, time]) + timeout;
        _.delay(function (t, a) {f.apply(t, a)}, nextCall - time, this, arguments);
      };
    }
  });
})(Underscore);