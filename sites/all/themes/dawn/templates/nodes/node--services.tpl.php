<?php

/**
 * @file
 * Default theme implementation to display a node.
 */

?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	<div class="heading">
		<h2 class="post-title"><?php print $title?></h2>
	</div>
	
	<?php
		// We hide the comments and links now so that we can render them later.
		hide($content['comments']);
		hide($content['links']);
		print render($content);
	?>

	<?php print render($content['links']); ?>

	<?php print render($content['comments']); ?>

</div>