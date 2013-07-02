<?php ?>
<div id="myCarousel" class="carousel slider_carousel slide">
    <ol class="carousel-indicators">
        <?php for ($i = 0; $i < count($slider); $i++) { ?>
            <li data-target="#myCarousel" data-slide-to="<?php print $i; ?>" class="active"></li>
        <?php } ?>
    </ol>
    <!-- Carousel items -->
    <div class="carousel-inner">
        <?php
        $i = 0;
        foreach ($slider as $slice) {
            ?>
            <div class="<?php print $i == 0 ? 'active' : ''; ?> item">
                <?php
                $image_uri = file_load($slice->image)->uri;
                $variables
                        = array(
                    'path' => image_style_url('slider', $image_uri),
                    'alt' => 'Test alt',
                    'title' => $slice->title,
                    'attributes' => array('class' => array('relative'))
                );
                print theme('image', $variables);
                ?>
                <div class="slider_info_container absolute">
                    <h1 class="slide_title"><?php print $slice->title; ?></h1>
                    <p class="slide_paragraph"><?php print $slice->description; ?></p>
                    <?php if (isset($slice->link_blue) && $slice->link_blue != ''): ?> 
                        <a href="<?php print $slice->link_blue ?>" class="btn btn-primary btn-large pull-left">Join now</a>
                    <?php endif; ?>
                    <?php if (isset($slice->link_gray) && $slice->link_gray != ''): ?> 
                        <a href="<?php print $slice->link_gray ?>" class="btn pull-right">Know more</a>
                    <?php endif; ?>
                </div>
            </div>
            <?php
            $i++;
        }
        ?>
    </div>
    <!-- Carousel nav -->
    <a class="carousel-control left" href="#myCarousel" data-slide="prev">&lsaquo;</a>
    <a class="carousel-control right" href="#myCarousel" data-slide="next">&rsaquo;</a>
</div>
