<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */
?>
<div id="page">
<?php if ($page['navigation']): ?>
        <?php print render($page['navigation']); ?>
        <?php if ($page['user_login']): ?>
            <div id="user-login" class="modal fade hide">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">×</button>
                    <h3 id="title">User Login</h3>
                </div>
        <?php print render($page['user_login']); ?>
            </div>
            <?php endif; ?>
        <?php if ($page['user_menu']): ?>
            <div id="account-options" class="modal hide fade">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">×</button>
                    <h3 id="title">User Menu</h3>
                </div>
        <?php print render($page['user_menu']); ?>
            </div>
            <?php endif; ?>
    <?php endif; ?>

    <a id="main-content"></a>

    <section id="main" class="container">

<?php print $messages;  ?>

        <?php if ((!empty($tabs['#primary'])) || $action_links): ?>
            <div class="row">
                <div class="span12">
    <?php if ($tabs): ?>
                        <div class="tabs">
                        <?php print render($tabs); ?>
                        </div>
                        <?php endif; ?>

                    <?php if ($action_links): ?>
                        <ul class="action-links">
                        <?php print render($action_links); ?>
                        </ul>
                        <?php endif; ?>
                </div>
            </div>
<?php endif; ?>
        
    </section>
        <?php if ($page['content']): ?>
            <?php print render($page['content']); ?>
        <?php endif; ?>
    <!-- /#main -->

</div><!-- /#page -->

<footer id="footer" class="footer">

    <div class="container">
        <div class="row">
<?php if ($page['footer_first']): ?>
                <?php print render($page['footer_first']); ?>
            <?php endif; ?>
            <?php if ($page['footer_second']): ?>
                <?php print render($page['footer_second']); ?>
            <?php endif; ?>
            <?php if ($page['footer_third']): ?>
                <?php print render($page['footer_third']); ?>
            <?php endif; ?>
            <?php if ($page['footer_fourth']): ?>
                <?php print render($page['footer_fourth']); ?>
            <?php endif; ?>
        </div><!-- /.row -->
    </div><!-- /.container -->

    <div class="copyright">
        <div class="container">
            <div class="row">
<?php if (!(theme_get_setting('copyright') == NULL)): ?>
                    <p>
                    <?php print theme_get_setting('copyright'); ?>
                    </p>
                    <?php endif; ?>
                <div class="social">
                    <ul class="toolbar">
<?php foreach ($social as $item): ?>
                            <?php $item_id = drupal_html_class($item); ?>
                            <?php if (theme_get_setting($item_id . '-icon') == 1): ?>
                                <li><a href="<?php print theme_get_setting($item_id . '-url'); ?>" target="_blank">
                                        <span class="<?php print $item_id; ?>"></span>
                                    </a></li>
    <?php endif; ?>
                        <?php endforeach ?>
                        <?php if (theme_get_setting('footer-toggle-rss') == 1): ?>
                            <li><a href="<?php print theme_get_setting('footer-rss-url'); ?>" target="_blank">
                                    <span class="rss"></span>
                                </a></li>
<?php endif; ?>
                    </ul>
                </div>
            </div><!-- /.row -->
        </div><!-- /.container-->
    </div><!-- /.copyright -->

</footer><!-- /#footer -->
<div id="toTop"><a class="top" href="#top"></a></div>