<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 */
?>
<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">

<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $custom_css; ?>
  <?php print $styles; ?>
  <link href='http://fonts.googleapis.com/css?family=Open+Sans:400italic,400,300,700,600' rel='stylesheet' type='text/css'>
  <?php print $jquery; ?>
  <?php print $scripts; ?>
  <?php if(!(theme_get_setting('analytics-code') == NULL) && (theme_get_setting('analytics-location') == 'header')): ?>
  	<?php print theme_get_setting('analytics-code'); ?>
  <?php endif; ?>
	<!--[if IE 7]>
		<link rel="stylesheet" type="text/css" href="<?php print $GLOBALS['base_url'].'/'.path_to_theme(); ?>/css/ie7.css">
		<script src="<?php print $GLOBALS['base_url'].'/'.path_to_theme(); ?>/js/ie7.js"></script>
	<![endif]-->
    <!--[if lt IE 9]>
    	<script src="//html5shim.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]--> 
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <?php if(!(theme_get_setting('analytics-code') == NULL) && (theme_get_setting('analytics-location') == 'footer')): ?>
  	<?php print theme_get_setting('analytics-code'); ?>
  <?php endif; ?>
</body>
  
</html>