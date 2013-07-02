<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<h2 class="heading">What We Do</h2>

<div class="row">
<?php foreach ($rows as $id => $row): ?>
	<?php if(($id % 4 == 0) && $id > 0): ?>
		<?php print ('</div><div class="row">'); ?>
	<?php endif; ?>
    <?php print $row; ?>
<?php endforeach; ?>
</div>