<?php if (!empty($latest_alumni)): ?>
    <h2>Programs</h2>
    <?php foreach ($latest_alumni as $single_prog): ?>
        <?php print l($single_prog->title, 'programs/' . $single_prog->nid); ?>
        <p><?php print $single_prog->description; ?></p>
        <?php print l(t('Read more'), 'programs/' . $single_prog->nid, array('attributes' => array('class' => array('btn btn-secondary')))); ?>
    <?php endforeach; ?>
<?php endif; ?>