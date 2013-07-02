<?php

/**
 * @file
 * Default theme implementation to display a node.
 */

?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
	<div class="row">
		<div class="span8">
			<div class="heading"> 
				<?php print render($title_prefix); ?>
				<h2 class="post-title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
				<?php print render($title_suffix); ?>
				<?php print render($content['flippy_pager']);?> 
			</div><!-- /.heading -->
			<?php if (!empty($node->field_image)): ?>
				<img class="img-polaroid" src="<?php print image_style_url('portfolio_item', $node->field_image['und'][0]['uri']); ?>" /> 
			<?php endif ?>
		</div><!-- /.span8 -->
		<div class="span4">
			<div class="heading"><h2>About This Project</h2></div>
				<?php
					hide($content['comments']);
					hide($content['links']);
					print render($content);
				?>
		</div><!-- /.span4 -->
	</div><!-- /.row -->
	

</div>