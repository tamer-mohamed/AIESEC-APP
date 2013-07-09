<?php
require_once drupal_get_path('module', 'contact') . '/contact.pages.inc';
$imgpath = file_load($information['bg_img']);
$imgpath = isset($imgpath->uri) ? file_create_url($imgpath->uri) : false;
$logo = file_load($information['logo']);
$logo = isset($logo->uri) ? file_create_url($logo->uri) : false;
$recipient = user_load($email['uid']);
$contact = drupal_render(drupal_get_form('contact_personal_form', $recipient));
?>
<header id="masthead" class="masthead" style="background:url('<?php echo $imgpath ?>') top center no-repeat">	
    <div class="container">
        <h1 class="title" id="page-title">
            <img src="<?php echo $logo ?>" height="50" class="img-polaroid"/>			
        </h1>
    </div>
    <div class="divider"></div>
</header>
<div class="container" id="main">
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
                        <div class="lc-page-main-content span12">
                            <?php echo $information['description']; ?> <br/>
                        </div>
                        <div class="clearfix"></div>
                        <div class="row">
                            <div class="news-container span9">
                                <?php foreach ($news as $new): ?>
                                    <div class="span4">
                                        <div class="img-polaroid blog">
                                            <a href="/drupal/dawn/node/29">
                                                <span class="view-more"></span>
                                                <span class="hover"></span></a>
                                            <img typeof="foaf:Image" src="<?php print file_create_url(file_load($new['img'])->uri); ?>" width="440" height="242" alt="">  
                                        </div>  
                                        <div class="date">
                                            <span class="month"><?php print date('F', $new['created']); ?></span>
                                            <span class="day"><?php print date('d', $new['created']); ?></span>
                                        </div>    
                                        <h3 class="blog"><a href="/drupal/dawn/node/29"><?php print $new['title']; ?></a></h3>    
                                        <p class="blog-teaser"><?php print mb_substr($new['description'], 0, 70) . ".."; ?></p>
                                    </div>
                                <?php endforeach; ?>
                                <div class="clearfix"></div>
                            </div>
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
                            <?php print $contact; ?>
                        </div>
                        <div class="span4">
                            <iframe width="100%" height="200" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="https://maps.google.com/maps?f=q&amp;source=s_q&amp;hl=en&amp;geocode=&amp;q=12.33,12.33&amp;t=m&amp;z=5&amp;output=embed"></iframe>
                            <div class="teams-container row">
                                <?php foreach ($teams as $team): ?>
                                    <div class="span2 thumbnail">
                                        <div class="image">
                                            <a href="#">
                                                <span class="view-more"></span>
                                                <span class="hover"></span></a>
                                            <img typeof="foaf:Image" src="<?php print file_create_url(file_load($team['img'])->uri); ?>" width="470" height="356" alt="">
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
                                    <img typeof="foaf:Image" src="<?php print file_create_url(file_load($partner['img'])->uri); ?>" width="470" height="356" alt="">
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