<?php

/**
 * @file
 * Default theme implementation to display a block.
 */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>" <?php print $attributes; ?>>

		<?php if ($block->subject): ?>
			<div class="heading">
			<?php print render($title_prefix); ?>
			<h2 <?php print $title_attributes; ?>>
				<?php print $block->subject ?>
			</h2>
			<?php print render($title_suffix); ?>
			</div>
		<?php endif;?>
	<?php print $content ?>
</div>
