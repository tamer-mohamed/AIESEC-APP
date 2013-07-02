<div class="well">
    <h3><?php print t('upcoming Events'); ?></h3>
    <ul>
        <li>
            <div class="row-fluid">
                <div class="span4"> <?php foreach ($events as $event): ?>
                        <?php
                        $image = file_load($event->image);

                        $imgvars = array(
                            'path' => image_style_url('events', $image->uri),
                            'alt' => $event->title,
                            'title' => $event->title,
                            'attributes' => array('class' => 'img-polaroid', 'id' => $event->title),
                        );
                        print theme('image', $imgvars);
                        ?>
                    </div>
                    <div class="span8">
                        <h6><?php print l($event->title, 'events/' . $event->nid); ?></h6> 
                        <p><?php print $event->description; ?></p> 
                    </div>
                </div>
                <div class="row-fluid">
                    <div class="span12"> 
                        <span class="icon-calendar"></span><?php print date('d M', $event->start_date); ?> - <span class="icon-calendar"></span><?php print date('d M', $event->end_date); ?>
                    </div>
                    <!--                <div class="span12"> 
                    <?php print l(t('Attend'), 'events/' . $event->nid, array('attributes' => array('class' => array('btn btn-mini btn-secondary')))); ?>
                                    </div>-->
                </div>
            </li> 
        <?php endforeach; ?>
    </ul>
</div>
