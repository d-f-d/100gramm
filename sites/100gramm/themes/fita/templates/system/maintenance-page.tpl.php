<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in html.tpl.php and page.tpl.php.
 * Some may be blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 * @ingroup themeable
 */
?><!DOCTYPE html>
<?php if (omega_extension_enabled('compatibility') && omega_theme_get_setting('omega_conditional_classes_html', TRUE)): ?>
<!--[if IEMobile 7]><html class="ie iem7" lang="<?= $language->language; ?>" dir="<?= $language->dir; ?>"><![endif]-->
<!--[if lte IE 6]><html class="ie lt-ie9 lt-ie8 lt-ie7" lang="<?= $language->language; ?>" dir="<?= $language->dir; ?>"><![endif]-->
<!--[if (IE 7)&(!IEMobile)]><html class="ie lt-ie9 lt-ie8" lang="<?= $language->language; ?>" dir="<?= $language->dir; ?>"><![endif]-->
<!--[if IE 8]><html class="ie lt-ie9" lang="<?= $language->language; ?>" dir="<?= $language->dir; ?>"><![endif]-->
<!--[if (gte IE 9)|(gt IEMobile 7)]><html class="ie" lang="<?= $language->language; ?>" dir="<?= $language->dir; ?>"><![endif]-->
<![if !IE]><html lang="<?= $language->language; ?>" dir="<?= $language->dir; ?>"><![endif]>
<?php else: ?>
<html lang="<?= $language->language; ?>" dir="<?= $language->dir; ?>">
<?php endif; ?>
<head>
  <title><?= $head_title; ?></title>
  <?= $head; ?>
  <?= $styles; ?>
  <?= $scripts; ?>
</head>
<body<?= $attributes;?>>
<div class="l-page">
  <header class="l-header" role="banner">
    <div class="l-branding">
      <?php if ($logo): ?>
        <a href="<?= $front_page; ?>" title="<?= t('Home'); ?>" rel="home" class="site-logo"><img src="<?= $logo; ?>" alt="<?= t('Home'); ?>" /></a>
      <?php endif; ?>

      <?php if ($site_name || $site_slogan): ?>
        <?php if ($site_name): ?>
          <h1 class="site-name">
            <a href="<?= $front_page; ?>" title="<?= t('Home'); ?>" rel="home"><span><?= $site_name; ?></span></a>
          </h1>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <h2 class="site-slogan"><?= $site_slogan; ?></h2>
        <?php endif; ?>
      <?php endif; ?>
    </div>

    <?= $header; ?>
  </header>

  <div class="l-main">
    <div class="l-content" role="main">
      <?php if ($title): ?><h1><?= $title; ?></h1><?php endif; ?>
      <?= $messages; ?>
      <?= $content; ?>
    </div>
  </div>

  <footer class="l-footer" role="contentinfo">
    <?= $footer; ?>
  </footer>
</div>
