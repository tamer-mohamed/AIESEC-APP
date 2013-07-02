<?php if (!$teaser): ?>

    <div class="row-fluid">

        <div class="span8">
            <div class="row-fluid">
                <?php print render($content['events_image']); ?>
            </div>
            <div class="row-fluid">

                <div class="span8">
                    <?php print render($content['title']); ?>
                </div>
                <div class="span4 actions">
                    <?php print render($content['attend_button']); ?>
                </div>
            </div>
            <div class="row-fluid">
                <div class="span9 event-details">
                    <div class="span12">
                        <span class="icon-calendar"></span><?php print render($content['start_date']); ?> <?php print t('until'); ?><?php print render($content['end_date']); ?>
                        <!--                <div class="span12 event-location">
                                            <span class="icon-map-marker"></span><?php //print ($content['location']);                                                    ?>
                                        </div>-->

                        <div class="">
                            <span class="icon-user"></span>
                            <?php print render($content['organizer']); ?>
                        </div> 
                        <div class="row-fluid">
                            <div class="span12 event-decription">
                                <?php print render($content['description']); ?>
                            </div>
                            <div class="row-fluid">
                                <div class="span12 event-posts">
                                    <h3><?php print t('Announcements'); ?></h3>
                                    <?php
                                   
                                    print render(drupal_get_form('event_announcement_form'));
                                    ?>
                                </div>
                            </div>

                        </div>
                    </div>

                </div>



                <div class="span3">
    <?php print render($content['event_attendees']); ?>
                </div>
            </div>


    <?php if (isset($content['event_attendees'])): ?>
                <div class="row-fluid">

                </div>
    <?php endif; ?>
        </div>
        <div class="span4">
            <?php
            $upcoming_events = module_invoke('events', 'block_view', 'events_upcoming');
            print $upcoming_events['content'];
            ?>
        </div>
    </div>

<?php endif; ?>
<?php if ($teaser): ?>
    <div class="row-fluid">
        <div class="span4">
    <?php print render($content['events_image']); ?>
        </div>
        <div class="span8">
            <div class="row-fluid">
                <div class="span12">
                    <h4><?php print l($node->title, 'events/' . $node->nid); ?></h4>
                </div>

            </div>
            <div class="row-fluid">
                <div class="span9 event-dates">
                    <span class="icon-calendar"></span><?php print render($content['start_date']); ?> <?php print t('until'); ?><?php print render($content['end_date']); ?>
                </div>
            </div>
            <div class="row-fluid">
                <div class="span12 event-decription">
    <?php print render($content['description']); ?>
                </div>
            </div>


        </div>

    </div>
<?php endif; ?>
