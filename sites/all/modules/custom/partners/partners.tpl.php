<?php if (!empty($partners)): ?>
    <div class="row">
        <div class="span12">
            <ul>

                <?php foreach ($partners as $single_partner): ?>
                    <?php
                    $attributes = array(
                        'id' => 'front-partner-listing',
                        'class' => 'partners-list', // a string or indexed (string) array with the classes for the list tag
                    );
                    $image = file_load($single_partner->image);
                    $variables = array(
                        'path' => image_style_url('programs', $image->uri),
                        'alt' => $single_partner->title,
                        'title' => $single_partner->title,
                        'attributes' => array('class' => '', 'id' => $single_partner->title),
                    );
                    ?>
                    <div class="heading">
                        <h2 class=""><?php print t('Partners'); ?></h2>
                        <div class="title-suffix">
                            <?php print l(t('Become a partner'), 'partner/apply'); ?> →</a></div>			
                    </div>
                    <li class="thumbnail span2" style="margin-left: 0">
                        <?php print l('<div class="image">' . theme('image', $variables) . '</div>', 'lol', array('html' => TRUE)); ?>
                    </li>
                <?php endforeach; ?>

            </ul>
        </div>
    </div>
<?php endif; ?>