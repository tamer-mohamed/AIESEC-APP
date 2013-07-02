<div class="siteContainer">
    <header id="navbar" role="banner" class="navbar navbar-inverse "> 
        <div class="navbar-inner">
            <div class="container">
                <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
                <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </a>

                <?php if (!empty($logo)): ?>
                    <a class="logo span3" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                    </a>
                <?php endif; ?>

                <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
                    <div class="span9">

                        <div class="pull-right">
                            <?php if (empty($GLOBALS['user'])): ?>                        
                                <?php print l(t('Login'), 'user') ?> | <?php print l(t('Register'), 'user/reigster') ?> 
                            <?php else : ?>
                                Welcome , <?php print l($GLOBALS['user']->name, 'user'); ?> - <?php print l(t('Logout'), 'user/logout'); ?>
                            <?php endif; ?>
                        </div>
                    </div>    
                    <div class="nav-collapse collapse span9">
                        <div class="row">

                            <div class="span9">
                                <nav role="navigation" class="pull-right">
                                    <?php if (!empty($primary_nav)): ?>
                                        <?php print render($primary_nav); ?>
                                    <?php endif; ?>

                                    <?php if (!empty($page['navigation'])): ?>
                                        <?php print render($page['navigation']); ?>
                                    <?php endif; ?>
                                </nav>
                            </div>
                        </div>

                    </div>
                <?php endif; ?>
            </div>
        </div>
    </header>
    <div class="highlighted_slider">
        <?php if (!empty($page['highlighted'])): ?>
            <div class="highlighted_container"><?php print render($page['highlighted']); ?></div>
        <?php endif; ?>
    </div>
    <div class="main-container container">

        <header role="banner" id="page-header">
            <?php if (!empty($site_slogan)): ?>
                <p class="lead"><?php print $site_slogan; ?></p>
            <?php endif; ?>

            <?php print render($page['header']); ?>
        </header> <!-- /#header -->

        <div class="row-fluid">



            <section class="<?php print _bootstrap_content_span($columns); ?>">  

                <a id="main-content"></a>

                <?php print $messages; ?>
                <?php if (!empty($tabs)): ?>
                    <?php print render($tabs); ?>
                <?php endif; ?>
                <?php if (!empty($page['help'])): ?>
                    <div class="well"><?php print render($page['help']); ?></div>
                <?php endif; ?>
                <?php if (!empty($action_links)): ?>
                    <ul class="action-links"><?php print render($action_links); ?></ul>
                <?php endif; ?>
                <div class="row-fluid">
                    <div class="span8">
                        <div class="row-fluid">
                            <div class="span6">
                                <h2><?php print $site_name; ?></h2>
                                <p><?php print theme_get_setting('site_desc'); ?></p>
                                
                            </div>
                            <div class="span6">
                                <h2><?php print $site_name; ?></h2>
                                <p><?php print theme_get_setting('site_desc'); ?></p>
                            </div>
                        </div>
                        <div class="row-fluid">
                            <div class="span12">
                                <ul class="nav nav-pills" id="homeTabs">
                                    <li class="active">
                                        <a href="#student">Student</a>
                                    </li>
                                    <li><a href="#company">Company</a></li>
                                    <li><a href="#alumni">Alumni</a></li>
                                </ul>

                                <div class="tab-content">
                                    <div class="tab-pane active" id="student">
                                        <div class="row-fluid">
                                            <div class="span6">
                                                <?php
                                                $latest_programs_students = module_invoke('programs', 'block_view', 'latest_programs_students');
                                                print $latest_programs_students['content'];
                                                ?>
                                            </div>
                                            <div class="span6">
                                                <?php
                                                $latest_magazine_students = module_invoke('magazine', 'block_view', 'latest_magazine_students');
                                                print $latest_magazine_students['content'];
                                                ?>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="tab-pane" id="company">
                                        <div class="span6">
                                            <?php
                                            $latest_programs_company = module_invoke('programs', 'block_view', 'latest_programs_company');
                                            print $latest_programs_company['content'];
                                            ?> 
                                        </div>


                                        <div class="span6">
                                            <?php
                                            $latest_magazine_company = module_invoke('magazine', 'block_view', 'latest_magazine_company');
                                            print $latest_magazine_company['content'];
                                            ?>
                                        </div>
                                    </div>
                                    <div class="tab-pane" id="alumni"> 
                                        <div class="span6">
                                            <?php
                                            $latest_programs_alumni = module_invoke('programs', 'block_view', 'latest_programs_alumni');
                                            print $latest_programs_alumni['content'];
                                            ?>
                                        </div>
                                        <div class="span6">
                                            <?php
                                            $latest_magazine_alumni = module_invoke('magazine', 'block_view', 'latest_magazine_alumni');
                                            print $latest_magazine_alumni['content'];
                                            ?>
                                        </div>
                                    </div>

                                </div>
                                <div>


                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="span4">
                        <?php
                        $upcoming_events = module_invoke('events', 'block_view', 'events_upcoming');
                        print $upcoming_events['content'];
                        ?>
                    </div>
                </div>

                <div class="row-fluid">
                    <div class="span12">

                        <?php
                        $partners_block = module_invoke('partners', 'block_view', 'partners_block');
                        print $partners_block['content'];
                        ?>
                    </div>
                </div>
            </section>

            <?php if (!empty($page['sidebar_second'])): ?>
                <aside class="span3" role="complementary">
                    <?php print render($page['sidebar_second']); ?>
                </aside>  <!-- /#sidebar-second -->
            <?php endif; ?>

        </div>

    </div>
</div>

<div class="row-fluid">
    <div class="span12">

    </div>
</div>
<footer class="footer container">
    <?php print render($page['footer']); ?>
</footer>
