
    <div class="row">
        <?php foreach ($news['all'] as $new): ?>
            <div class="span4">
                <div class="img-polaroid blog">
                    <a href="#newsAll-<?php print $new['id']; ?>" data-toggle="modal">
                        <span class="view-more"></span>
                        <span class="hover"></span></a>
                    <?php if (file_load($new['img'])): ?>
                        <img typeof="foaf:Image" src="<?php print file_create_url(file_load($new['img'])->uri); ?>" width="440" height="242" alt="">  
                    <?php endif; ?>
                </div>  
                <div class="date">
                    <span class="month"><?php print date('F', $new['created']); ?></span>
                    <span class="day"><?php print date('d', $new['created']); ?></span>
                </div>    
                <h3 class="blog"><a href="#newsAll-<?php print $new['id']; ?>" data-toggle="modal"><?php print $new['title']; ?></a></h3>    
                <p class="blog-teaser"><?php print mb_substr($new['description'], 0, 70) . ".."; ?></p>
            </div>
        <?php endforeach; ?>
        <div class="clearfix"></div>
        <div class="span12">
            <?php print $news['pager']; ?>
        </div>
    </div>



<!-- Modals for newsAll !-->
<?php foreach ($news['all'] as $new): ?>
    <div class="modal hide fade news-modal" id="newsAll-<?php print $new['id']; ?>">
        <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
            <h3><?php print $new['title']; ?></h3>
        </div>
        <div class="modal-body">
            <?php if (file_load($new['img'])): ?>
                <img typeof="foaf:Image" src="<?php print file_create_url(file_load($new['img'])->uri); ?>"height="100" alt="" class="pull-left">  
            <?php endif; ?>
            <div class="content">
                <?php print $new['description']; ?>
            </div>
        </div>
        <div class="modal-footer">
            <button class="btn" data-dismiss="modal" aria-hidden="true">Close</button>
        </div>
    </div>
<?php endforeach; ?>