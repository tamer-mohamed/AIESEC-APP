<?php

/**
 * @file
 * Default theme implementation to display a region.
 */
?>

<header id="header" class="navbar navbar-static-top">
  <div class="navbar-inner">
  <div class="container">
    <?php if ($linked_logo_img || $site_slogan): ?>
    
      <?php if ($linked_logo_img): ?>
      <div class="logo">
        <?php print $linked_logo_img; ?>
      </div>
      <?php endif; ?>

      <?php if ($site_slogan): ?>
        <h6 class="site-slogan"><?php print $site_slogan; ?></h6>
      <?php endif; ?>
    <?php endif; ?>
    
    <?php if ($main_menu || $secondary_menu): ?>
    <div class="navigation">
      <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => array('text' => t('Main menu'),'level' => 'h2','class' => array('element-invisible')))); ?>
      <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => array('text' => t('Secondary menu'),'level' => 'h2','class' => array('element-invisible')))); ?>
    </div>
    <?php endif; ?>
    
    <ul class="toolbar">
	    <?php foreach ($social as $item): ?>
	    	<?php $item_id = drupal_html_id($item); ?>
	    	<?php if (theme_get_setting($item_id . '-icon') == 1): ?>
	    	<li><a href="<?php print theme_get_setting($item_id . '-url'); ?>" target="_blank">
	    		<span class="<?php print $item_id; ?>"></span>
	    	</a></li>
	    	<?php endif; ?>
	    <?php endforeach ?>
	    
	    <?php if (!user_is_logged_in()): ?>
	    	<li><a href="user#user-login" data-toggle="modal" title="Login/Register"><span class="login"></span></a></li>
	    <?php endif; ?>
	    
	    <?php if (user_is_logged_in()): ?>
	    	<li><a href="<?php print $profile; ?>#account-options" data-toggle="modal" title="My Account"><span class="login"></span></a></li>
	    <?php endif; ?>
	    
	    <li class="dropdown search-box">
			<a class="dropdown-toggle" id="dLabel" role="button" data-toggle="dropdown" data-target="#" href="search" title="Search">
				<span class="search"></span>
			</a>
			<div class="dropdown-menu" role="button" aria-labelledby="dLabel">
			  <?php print $search_box; ?>
			</div>
	    </li>
    </ul>
    
    <div class="mobile-navigation">Select a Page</div>
    
    <?php print $content; ?>
  </div>
  </div>
</header><!-- /#header -->