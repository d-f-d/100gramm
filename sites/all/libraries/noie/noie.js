(function ($, mzr) {
  mzr.generatedcontent || $(function () {
    var noie6 = "<div id=noie6-overlay></div><div id=noie6-wrap><a href=# id=noie6-close title=close>Закрыть</a>" +
      "<div id=noie6-wrap-inner><div id=noie6-message><div id=noie6-message-inner>" +
      "<h2>Internet Explorer 6 очень старый браузер и не поддерживается этим сайтом.</h2>" +
      "<p>Ниже приводится список некоторых из причин, почему этот браузер не поддерживается:</p>" +
      "<ul><li>Он не поддерживает <a href='http://www.w3.org/standards/agents/browsers'>W3C стандарты</a>." +
      "<li>Он не совместим с <a href='http://www.css3.info/selectors-test/'>CSS3</a>." +
      "<li>Он имеет очень низкие показатели в <a href='http://acid3.acidtests.org/'>Acid 3 тестах</a>." +
      "<li>Он небезопасный и медленный." +
      "<li>Существует несколько движений против этого браузера: <a href='http://ie6.forteller.net/index.php?title=Main_Page'>Не хотим IE6!</a>, " +
      "<a href='http://iedeathmarch.org/'>IE Похоронный марш</a>, <a href='http://dearie6.com/'>Милый IE6</a>. " +
      "<li>Google официально <a href='http://googleenterprise.blogspot.com/2010/01/modern-browsers-for-modern-applications.html'>прекратил</a> его поддержку." +
      "<li>И даже <a href='http://ie6funeral.com/'>похороны</a> состоялись." +
      "<li>Если у вас IE 7, не удивляйтесь, его мы не поддерживаем по тем же причинам, что и <a href='http://googledocs.blogspot.com/2011/06/our-plans-to-support-modern-browsers.html'>Google</a></ul>" +
      "<h4>Мы настоятельно рекомендуем загрузить один из следующих браузеров:</h4></div></div>" +
      "<div id=noie6-browsers><ul><li id=noie6-firefox class=last> <a href='http://www.mozilla.com/firefox/' class=noie6-browser title=Firefox>Firefox</a>" +
      "<li id=noie6-safari> <a href='http://www.apple.com/safari/download/' class=noie6-browser title=Safari>Safari</a>" +
      "<li id=noie6-chrome> <a href='http://www.google.com/chrome/' class=noie6-browser title=Chrome>Chrome</a>" +
      "<li id=noie6-opera> <a href='http://www.opera.com/download/' class=noie6-browser title=Opera>Opera</a>" +
      "<li id=noie6-update-ie class=last><a href='http://www.microsoft.com/windows/internet-explorer/default.aspx' class=noie6-browser title='Update IE'>Update IE</a>" +
      "</ul></div></div>.</div>";
    $('body').prepend(noie6);
    $('#noie6-overlay').height($(document).height());
    var noie6_center = $('#noie6-wrap').width() / (-2);
    var noie6_wrap_bg = $('#noie6-wrap').css('background-image');
    $('#noie6-wrap')
      .css({'margin-left' : noie6_center, 'background-image' : 'none'})
      .slideDown(function () {
        $(this).css('background-image', noie6_wrap_bg);
      }
    );
    $('#noie6-close').click(function () {
      $('#noie6-wrap, #noie6-overlay').fadeOut('normal');
      return false;
    });
  });
})(jQuery, Modernizr);