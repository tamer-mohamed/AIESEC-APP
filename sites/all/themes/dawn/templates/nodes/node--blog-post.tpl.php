<?php

/**
 * @file
 * Default theme implementation to display a node.
 */

?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	<?php print render($title_prefix); ?>
	<div class="heading">
		<h2 class="post-title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
	</div>
	<?php print render($title_suffix); ?>
	
	<?php if ($display_submitted): ?>
		<ul class="post-meta">
			<li><span class="icon-pencil"></span> <?php print $name; ?></li>
			<li>
				<span class="icon-calendar"></span> 
				<?php print format_date($created, 'custom', 'F jS, Y'); ?>
			</li>
			<li><span class="icon-comment"></span> <?php print $comment_count; ?> comments</li>
			<li><span class="icon-tags"></span> <?php print render($content['field_tags']); ?> </li>
		</ul>
	<?php endif; ?>
	
	<img class="img-polaroid" src="<?php print image_style_url('blog_post', $node->field_image['und'][0]['uri']); ?>" /> 

	<?php
		// We hide the comments and links now so that we can render them later.
		hide($content['comments']);
		hide($content['links']);
		print render($content);
	?>

	<?php print render($content['links']); ?>

	<?php print render($content['comments']); ?>

</div>