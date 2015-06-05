<div class="l-page">
  <div class="l-main">
    <header class="l-header" role="banner">
      <?= render($page['header']); ?>
      <?= render($page['navigation']); ?>
    </header>
    <div class="l-content" role="main">
      <?= render($page['highlighted']); ?>
      <a id="main-content"></a>
      <?= render($tabs); ?>
      <?= render($page['help']); ?>
      <?= render($page['content']); ?>
      <?= $feed_icons; ?>
    </div>

    <?= render($page['sidebar_first']); ?>
    <?= render($page['sidebar_second']); ?>
  </div>

  <footer class="l-footer" role="contentinfo">
    <?= render($page['footer']); ?>
  </footer>
</div>
