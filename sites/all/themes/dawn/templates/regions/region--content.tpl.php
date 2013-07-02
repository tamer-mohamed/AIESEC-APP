<?php

/**
 * @file
 * Default theme implementation to display a region.
 */
?>

<?php if ($content): ?>
<div class="<?php print $classes; ?>">
	
	<?php print $content; ?>
	
	<?php if (!drupal_is_front_page() && $feed_icons): ?>
		<?php print $feed_icons; ?>
	<?php endif; ?>
</div>
<?php endif; ?>
