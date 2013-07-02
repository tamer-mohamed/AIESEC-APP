<?php if (!empty($latest_student)): ?>
    <h2>Magazine</h2>
    <ul class="thumbnails">
        <?php foreach ($latest_student as $single_prog): ?>

            <li class="span11" style="background:white;">
                <div class="thumbnail">
                    <?php
                    $image = file_load($single_prog->image);
                    $variables = array(
                        'path' => image_style_url('programs', $image->uri),
                        'alt' => $single_prog->title,
                        'title' => $single_prog->title,
                        'attributes' => array('class' => '', 'id' => $single_prog->title),
                    );
                    print l(theme('image', $variables), $single_prog->title, array('html' => TRUE));
                    ?>
                    <h3> <?php print l($single_prog->title, 'magazine/' . $single_prog->nid); ?></h3>
                    <p><?php print $single_prog->description; ?></p>
                    <?php print l(t('Read more'), 'magazine/' . $single_prog->nid, array('attributes' => array('class' => array('btn btn-secondary')))); ?>

                </div>
            </li>

        <?php endforeach; ?>
    </ul>
<?php endif; ?>