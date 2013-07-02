<?php
    header("Content-type: text/css; charset: UTF-8");
	define('DRUPAL_ROOT', realpath(getcwd() . '/../../../../'));
	require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
	drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
	
	$headings = array('h1', 'h2', 'h3', 'h4', 'h5', 'h6');
	$links = array('a' => 'link-normal', 'a:hover' => 'link-hover', 'a:active' => 'link-active', 'a:visited' => 'link-visited');
	
	$headerbg = HexToRGB(theme_get_setting('header-background'));
	$highlight = HexToRGB(theme_get_setting('highlight-color'));
	
	
	function HexToRGB($hex) {
		$hex = preg_replace("[#]", "", $hex);
		$color = array();
	
		if(strlen($hex) == 3) {
			$color['r'] = hexdec(substr($hex, 0, 1) . $r);
			$color['g'] = hexdec(substr($hex, 1, 1) . $g);
			$color['b'] = hexdec(substr($hex, 2, 1) . $b);
		}
		else if(strlen($hex) == 6) {
			$color['r'] = hexdec(substr($hex, 0, 2));
			$color['g'] = hexdec(substr($hex, 2, 2));
			$color['b'] = hexdec(substr($hex, 4, 2));
		}
	
		return $color;
	}
			
?>

body { <?php if(!(theme_get_setting('background-color') == NULL)): ?>
 <?php print 'background-color: #'.theme_get_setting('background-color').';' ?>
<?php endif; ?>
<?php if(theme_get_setting('base-font-type') == 'default-font'): ?>
 <?php print 'font-family: '.theme_get_setting('base-default-font').';' ?>
 <?php else: ?>
 <?php print 'font-family: '.theme_get_setting('base-webfont').';' ?>
<?php endif; ?> }

#page {<?php if(!(theme_get_setting('base-fontsize') == NULL)): ?>
 <?php print 'font-size:'.theme_get_setting('base-fontsize').'px;' ?>
<?php else: ?>
 <?php print 'font-size: 14px;' ?>
<?php endif; ?>
<?php if(!(theme_get_setting('base-color') == NULL)): ?>
 <?php print 'color: #'.theme_get_setting('base-color').';' ?>
<?php endif; ?>
<?php if(!(theme_get_setting('base-fontweight') == NULL)): ?>
 <?php print 'font-weight:'.theme_get_setting('base-fontweight').';' ?>
<?php endif; ?>
<?php if(!(theme_get_setting('base-font-style') == 'normal')): ?>
 <?php print 'font-style: '.theme_get_setting('base-font-style').';' ?>
<?php endif; ?> }

#header { background: #<?php print theme_get_setting('header-background'); ?>; background: rgba(<?php foreach($headerbg as $item): print $item.','; ?>
<?php endforeach; if(theme_get_setting('header-opacity') != 100): print (theme_get_setting('header-opacity') / 100).'); }'; else: print '1.0); }'; endif; ?>

<?php if(!(theme_get_setting('footer-background') == NULL)): ?>
#footer { background-color: #<?php print theme_get_setting('footer-background'); ?>; }
<?php endif; ?>

/* Links */
<?php foreach($links as $item => $value): ?>

<?php print $item.' {'; ?>
<?php if(!(theme_get_setting($value.'-fontweight') == NULL)): ?>
 <?php print 'font-weight:'.theme_get_setting($value.'-fontweight').';' ?>
<?php endif; ?>
<?php if(!(theme_get_setting($value.'-font-style') == 'normal')): ?>
 <?php print 'font-style:'.theme_get_setting($value.'-font-style').';' ?>
<?php endif; ?>
 <?php print 'text-decoration: '.theme_get_setting($value.'-decoration').';' ?>
<?php if(!(theme_get_setting($value.'-color') == NULL)): ?>
 <?php print 'color: #'.theme_get_setting($value.'-color').';' ?>
<?php endif; ?>
<?php print ' }'; ?>
<?php endforeach; ?>


/* Headings */
<?php foreach($headings as $item): ?>

<?php print $item.' {'; ?>
<?php if(theme_get_setting($item.'-font-type') == 'default-font'): ?>
 <?php print 'font-family: '.theme_get_setting($item.'-default-font').';' ?>
 <?php else: ?>
 <?php print 'font-family: '.theme_get_setting($item.'-webfont').';' ?>
<?php endif; ?>
<?php if(!(theme_get_setting($item.'-fontweight') == '')): ?>
 <?php print 'font-weight:'.theme_get_setting($item.'-fontweight').';' ?>
<?php endif; ?>
<?php if(!(theme_get_setting($item.'-font-style') == 'normal')): ?>
 <?php print 'font-style:'.theme_get_setting($item.'-font-style').';' ?>
<?php endif; ?>
<?php if(!(theme_get_setting($item.'-fontsize') == NULL)): ?>
 <?php print 'font-size:'.theme_get_setting($item.'-fontsize').'px;' ?>
<?php endif; ?>
<?php if(!(theme_get_setting($item.'-color') == NULL)): ?>
 <?php print 'color: #'.theme_get_setting($item.'-color').';' ?>
<?php endif; ?>
<?php print ' }'; ?>
<?php endforeach; ?>


/* Highlight Color */

<?php if(!(theme_get_setting('highlight-color') == NULL)): ?>
.main-menu ul > li> a.active-trail,
.main-menu ul > li> a.active-trail:hover,
.main-menu ul > li > a.active,
.main-menu ul > li > a.active:hover,
.mobile-navigation { 
	background: #<?php print theme_get_setting('highlight-color'); ?>;
	background: rgba(<?php foreach($highlight as $item): print $item.','; endforeach; print '0.95' ?>);
}

.day { 
	background: #<?php print theme_get_setting('highlight-color'); ?>;
	background: rgba(<?php foreach($highlight as $item): print $item.','; endforeach; print '0.80' ?>);
}

.btn { 
	background: #<?php print theme_get_setting('highlight-color'); ?>;
	background: rgba(<?php foreach($highlight as $item): print $item.','; endforeach; print '0.85' ?>);
}

#forum .container,
#user-login .modal-header,
#simplenews-wrap .modal-header,
#account-options .modal-header, 
.highlight-bg,
.pricing .active .price, 
.pricing .active h3.pricing {
	background: #<?php print theme_get_setting('highlight-color'); ?>;
}

ul.toolbar li span.login:hover,
ul.toolbar li span.search:hover,
li.search-box .form-submit,
.search-form .form-submit,
.dropdown-menu li > a:hover,
.dropdown-menu li > a:focus,
.dropdown-submenu:hover > a,
.dropdown-menu .active > a,
.dropdown-menu .active > a:hover,
#footer .tag-cloud ul li a:hover {
	background-color: #<?php print theme_get_setting('highlight-color'); ?>;
	background-color: rgba(<?php foreach($highlight as $item): print $item.','; endforeach; print '0.95' ?>);
}

.thumbnail,
.navbar-static-top {
	border-color: #<?php print theme_get_setting('highlight-color'); ?>;
}

.accordion-heading.active,
.snippet.open,
.tabs-left > .nav-tabs > .active > a,
.tabs-left > .nav-tabs > .active > a:hover {
	border-left-color: #<?php print theme_get_setting('highlight-color'); ?>;
}

.tabs-right > .nav-tabs > .active > a,
.tabs-right > .nav-tabs > .active > a:hover {
	border-right-color: #<?php print theme_get_setting('highlight-color'); ?>;
}

.nav-pills > .active > a, 
.nav-pills > .active > a:hover,
.nav-tabs > .active > a, 
.nav-tabs > .active > a:hover, 
.tabs > .active > a, 
.tabs > .active > a:hover,
.pager > .pager-current,
.pager > .pager-current:hover,
#main .tag-cloud ul li a:hover {
	border-top-color: #<?php print theme_get_setting('highlight-color'); ?>;
}

.main-menu ul ul {
	border-bottom-color: #<?php print theme_get_setting('highlight-color'); ?>;
}
<?php endif; ?>

@media (max-width: 767px) {
	#header {
	background: #<?php print theme_get_setting('highlight-color'); ?>;
	background: rgba(<?php foreach($headerbg as $item): print $item.','; endforeach; print '1.0)'; ?>;
	}
}