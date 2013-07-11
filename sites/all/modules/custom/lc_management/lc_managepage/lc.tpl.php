<?php
require_once drupal_get_path('module', 'contact') . '/contact.pages.inc';
$imgpath = file_load($information['bg_img']); 
$imgpath = isset($imgpath->uri) ? file_create_url($imgpath->uri) : false;
$logo = file_load($information['logo']);
$logo = isset($logo->uri) ? image_style_url("lc_logo", $logo->uri): false;
$recipient = user_load($email['uid']);
$contact = drupal_render(drupal_get_form('contact_personal_form', $recipient));
drupal_set_title($information['name']." - LC");
?>
<header id="masthead" class="masthead " style="background:url('<?php echo $imgpath ?>') top center no-repeat">	
    <div class="container">
        
            <img src="<?php echo $logo ?>" height="50" class="img-polaroid pull-left"/>	
        <h1 class="title" id="page-title">
            <?php print $information['name']; ?>
        </h1>
    </div>
    <div class="divider"></div>
</header>
<div class="container" id="main">
    <?php if($information['advertisment'] != ''):?>
    <div class="row">
        <div class="span12">
            <div class="callout">
                <div class="callout-text">
                    <?php print $information['advertisment']; ?>
                </div>
                <div class="clearfix"></div>
            </div>
        </div>
    </div>  
    <?php endif; ?>
    <div class="row">
        <div class="span12">
            <ul class="nav nav-tabs" id="myTab">
                <li class="active"><a href="#home"><i class="icon-home"></i>Home</a></li>
                <?php foreach ($tabs as $tab): ?>
                    <li><a href="#<?php print 'tab' . $tab['id']; ?>"><?php print $tab['title']; ?></a></li>
                <?php endforeach; ?>
                <li><a href="#contactus">Contact us.</a></li>
            </ul>

            <div class="tab-content">
                <div class="tab-pane active" id="home">
                    <div class="row">
                        <div class="lc-page-main-content span12 ">
                            <div class='well'>
                            <?php echo $information['description']; ?> 
                            </div>
                        </div>
                        <div class="clearfix"></div>
                            <div class="news-container span9">
                                
                                <div class="heading">
                                    <h2 class="">
                                        Latest News
                                    </h2>
                                </div>
                                <?php foreach ($news as $new): ?>
                                    <div class="span4">
                                        <div class="img-polaroid blog">
                                            <a href="#news-<?php print $new['id'];?>" data-toggle="modal">
                                                <span class="view-more"></span>
                                                <span class="hover"></span></a>
                                            <?php if(file_load($new['img'])):?>
                                            <img typeof="foaf:Image" src="<?php print file_create_url(file_load($new['img'])->uri); ?>" width="440" height="242" alt="">  
                                            <?php endif; ?>
                                        </div>  
                                        <div class="date">
                                            <span class="month"><?php print date('F', $new['created']); ?></span>
                                            <span class="day"><?php print date('d', $new['created']); ?></span>
                                        </div>    
                                        <h3 class="blog"><a href="#"><?php print $new['title']; ?></a></h3>    
                                        <p class="blog-teaser"><?php print mb_substr($new['description'], 0, 70) . ".."; ?></p>
                                    </div>
                                <?php endforeach; ?>
                                <div class="clearfix"></div>
                            </div>
                            <div class="span3">
                                <div class="heading">
                                    <h2 class="">
                                        Latest Tweets
                                    </h2>
                                </div>
                                <div class="tweet" data-twitter="<?php print $information['twitter']; ?>"></div>
                            </div>
                    </div>
                </div>
                <?php foreach ($tabs as $tab): ?>
                    <div class="tab-pane" id="<?php print 'tab' . $tab['id']; ?>">
                        <?php print $tab['description']; ?>
                    </div>
                <?php endforeach; ?>
                <div class="tab-pane" id="contactus">
                    <div class="row">
                        <div class="span8">
                            
                            <div class="heading">
                                <h2 class="">
                                    Send us a message
                                </h2>
                            </div>
                            <?php print $contact; ?>
                        </div>
                        <div class="span4">
                            <div class="heading">
                                <h2 class="">
                                    Location
                                </h2>
                            </div>
                        </div>
                        <div class="span4">

                            <iframe width="100%" height="200" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="https://maps.google.com/maps?f=q&amp;source=s_q&amp;hl=en&amp;geocode=&amp;q=<?php echo $information['longitude'] . "," . $information['lat']; ?>&amp;t=m&amp;z=5&amp;output=embed"></iframe>
                            <div class="teams-container row">
                                <div class="span4">
                                    <div class="heading">
                                        <h2 class="">
                                            Team
                                        </h2>
                                    </div>
                                </div>
                                <?php foreach ($teams as $team): ?>
                                    <div class="span2 thumbnail">
                                        <div class="image">
                                            <a href="#">
                                                <span class="view-more"></span>
                                                <span class="hover"></span></a>
                                            <?php if(file_load($team['img'])): ?>
                                            <img typeof="foaf:Image" src="<?php print file_create_url(file_load($team['img'])->uri); ?>" width="470" height="356" alt="">
                                            <?php endif; ?>
                                        </div>
                                        <h3><?php print $team['title']; ?></h3>
                                        <h4><?php print mb_substr($team['description'], 0, 30); ?></h4>
                                    </div>
                                <?php endforeach; ?>
                                <div class="clearfix"></div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div class="partners row">
                <div class="span12">
                    <div class="heading">
                        <h2 class="">partners</h2>
                    </div>
                    <div class="clearfix"></div>
                    <?php foreach ($partners as $partner): ?>
                        <div class="span3">
                            <div class="thumbnail">
                                <div class="image">
                                    <a href="<?php print $partner['url']; ?>" target="_blank">
                                        <span class="view-more"></span>
                                        <span class="hover"></span></a>
                                    <?php if(file_load($partner['img'])): ?>
                                    <img typeof="foaf:Image" src="<?php print file_create_url(file_load($partner['img'])->uri); ?>" width="470" height="356" alt="">
                                    <?php endif; ?>
                                </div>
                                <h3><?php print $partner['title']; ?></h3>
                                <h4><?php print mb_substr($partner['description'], 0, 30); ?></h4>
                            </div>    
                        </div>
                    <?php endforeach; ?>
                    <div class="clearfix"></div>
                </div>
            </div>
        </div>
    </div>
</div>

<!-- Modals for news !-->
<?php foreach ($news as $new): ?>
<div class="modal hide fade news-modal" id="news-<?php print $new['id'];?>">
  <div class="modal-header">
    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
    <h3><?php print $new['title'];?></h3>
  </div>
  <div class="modal-body">
    <?php if(file_load($new['img'])): ?>
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