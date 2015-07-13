<?php

/**
 * @file
 * Default template for feed displays that use the RSS style.
 *
 * @ingroup views_templates
 */
?>
<?php print "<?xml"; ?> version="1.0" encoding="utf-8" <?php print "?>"; ?>
<rss version="2.0" xml:base="<?php print $link; ?>"<?php print $namespaces; ?>>
  <channel>
    <title><?php print $title; ?></title>
    <link><?php print $link; ?></link>
    <description><?php print $description; ?></description>
    <language><?php print $langcode; ?></language>
    <rss2lj:owner xmlns:rss2lj="http://rss2lj.net/NS">doctor_moro</rss2lj:owner>
    <?php print $channel_elements; ?>
    <?php print $items; ?>
  </channel>
</rss>
