<?php if (!$teaser): ?>
    <div class="magazine-item-teaser">
        <div class="row-fluid">
            <div class="span8">

                <div class="row-fluid">
                    <div class="span12">
                        <?php print render($content['magazine_image']); ?>
                    </div>
                </div>
                <?php print render($content['user_type']); ?>
                <div class="row-fluid">
                    <div class="span12">
                        <h4><?php print l($node->title, 'magazine/' . $node->nid); ?></h4>
                    </div>

                </div>
                <div class="row-fluid">
                    <div class="span12 magazine-decription">
                        <?php print render($content['magazine_tags']); ?>
                    </div>
                </div>

                <div class="row-fluid">
                    <div class="span12 magazine-decription">
                        <?php print render($content['description']); ?>
                    </div>
                </div>

            </div>
            <div class="span4">
                <?php if(!empty($content['related_content'])): ?>
                
                <ul>
                    <h2>Related Posts</h2>
                    <?php
                    // Related Block
                    
                    foreach ($content['related_content'] as $single_content) {
                        ?> 
                        <li><div>
                                  <?php
                                $variables = array(
                                    'path' => $single_content['image'],
                                    'alt' => $single_content['title'],
                                    'title' => $single_content['title'],
                                    'attributes' => array('class' => 'img-polaroid', 'id' => $single_content['title']),
                                );
                                print theme('image', $variables);
                                ?>
                                <?php print l($single_content['title'], 'magazine/' . $single_content['nid']); ?>
                              
                        <?php print $single_content['description']; ?>
                            </div></li>
                        <?php
                    }
                    ?>
                </ul>
                <?php endif; ?>
            </div>
        </div>


    </div>


<?php endif; ?>
<?php if ($teaser): ?>
    <div class="magazine-item-teaser">
        <div class="row-fluid">
            <div class="span12">
    <?php print render($content['magazine_image']); ?>
            </div>
        </div>
    <?php print render($content['user_type']); ?>
        <div class="row-fluid">
            <div class="span12">
                <h4><?php print l($node->title, 'magazine/' . $node->nid); ?></h4>
            </div>

        </div>
        <div class="row-fluid">
            <div class="span12 magazine-decription">
    <?php print render($content['description']); ?>
            </div>
        </div>

        <div class="row-fluid actions">
            <div class="span12">
    <?php print l(t('Read more'), 'magazine/' . $node->nid, array('attributes' => array('class' => array('btn btn-primary')))) ?>
            </div>
        </div>
    </div>
<?php endif; ?>
