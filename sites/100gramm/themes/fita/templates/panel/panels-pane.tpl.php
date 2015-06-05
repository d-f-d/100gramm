<?php
/**
 * @file panels-pane.tpl.php
 * Main panel pane template
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<?= $pane_prefix ? $pane_prefix : NULL ?>

<div <?= $attributes; ?>>

  <?= $admin_links ? $admin_links : NULL ?>

  <?= render($title_prefix); ?>
  <?php if ($title): ?>
    <h2<?= $title_attributes; ?>><?= $title; ?></h2>
  <?php endif; ?>
  <?= render($title_suffix); ?>

  <?php if ($feeds): ?>
    <div class="feed">
      <?= $feeds; ?>
    </div>
  <?php endif; ?>

  <div class="pane-content">
    <?= render($content); ?>
  </div>

  <?php if ($links): ?>
    <div class="links">
      <?= $links; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <div class="more-link">
      <?= $more; ?>
    </div>
  <?php endif; ?>
</div>
<?= $pane_suffix ? $pane_suffix : NULL ?>