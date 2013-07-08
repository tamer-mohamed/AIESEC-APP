<?php

//	require_once dirname(__FILE__) . '/includes/dawn.inc';
//function dawn_preprocess_user_picture(&$variables) {
//
//  $variables['user_picture'] = '';
//  if (variable_get('user_pictures', 0)) {
//    $account = $variables['account'];
//    if (!empty($account->picture)) {
//      if (is_numeric($account->picture)) {
//        $account->picture = file_load($account->picture);
//      }
//      if (!empty($account->picture->uri)) {
//        $filepath = $account->picture->uri;
//      }
//    }
//    elseif (variable_get('user_picture_default', '')) {
//      $filepath = variable_get('user_picture_default', '');
//    }
//    if (isset($filepath)) {
//      $alt = t('YOUR CUSTOM ALT TEXT');
//      $title = t('YOUR CUSTOM TITLE TEXT');
//
//      if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
//        $variables['user_picture'] = theme('image_style', array('style_name' => $style, 'path' => $filepath, 'alt' => $alt, 'title' => $title));
//      }
//      else {
//        $variables['user_picture'] = theme('image', array('path' => $filepath, 'alt' => $alt, 'title' => $title));
//      }
//      if (!empty($account->uid) && user_access('access user profiles')) {
//        $attributes = array(
//          'attributes' => array('title' => t('View user profile.')),
//          'html' => TRUE,
//        );
//        $variables['user_picture'] = l($variables['user_picture'], "user/$account->uid", $attributes);
//      }
//    }
//  }
//}
	function dawn_js_alter(&$javascript) {
		/* Unset old version of jQuery on non-administration pages */
		if (!path_is_admin(current_path())) { 
			unset($javascript['misc/jquery.js']); 
		}
		
		/* Unset module js files */
		if (isset($javascript['sites/all/modules/views_isotope/views_isotope.js'])) {
			unset($javascript['sites/all/modules/views_isotope/views_isotope.js']);
		}
	}

 	function dawn_css_alter(&$css) {
 		// Unset system css files
 		unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
 		unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);
 		
 		// Unset module css files
 		if (isset($css['sites/all/modules/views_isotope/views_isotope.css'])) {
 			unset($css['sites/all/modules/views_isotope/views_isotope.css']);
 		}
 		
 		if (isset($css['sites/all/modules/revolution_slider/theme/settings.css'])) {
 			unset($css['sites/all/modules/revolution_slider/theme/settings.css']);
 		}
 	}
 	
 	function dawn_preprocess_views_isotope(&$vars) {
 		drupal_add_css(path_to_theme() . '/css/isotope.css');
 	}
 	
 	function dawn_preprocess_revolution_slider(&$vars) {
 		drupal_add_css(path_to_theme() . '/css/slider.css');
 	}
 	
 	/* Buttons Styles */
 	function dawn_button($vars) {
 		$element = $vars['element'];
 		$element['#attributes']['type'] = 'submit';
 		element_set_attributes($element, array('id', 'name', 'value'));
 	
 		$element['#attributes']['class'][] = 'btn form-' . $element['#button_type'];
 		if (!empty($element['#attributes']['disabled'])) {
 			$element['#attributes']['class'][] = 'form-button-disabled';
 		}
 	
 		return '<input' . drupal_attributes($element['#attributes']) . ' />';
 	}
	
 	/* Flippy Module */
 	function dawn_preprocess_flippy(&$vars) {
 		$options = array('absolute' => TRUE);
 		$first = $vars['first']['nid'];
 		$last = $vars['last']['nid'];
 		$prev = $vars['prev']['nid'];
 		$next = $vars['next']['nid'];
 		$vars['first_url'] = url('node/' . $last, $options);
 		$vars['last_url'] = url('node/' . $first, $options);
 		$vars['prev_url'] = url('node/' . $prev, $options);
 		$vars['next_url'] = url('node/' . $next, $options);
 		$vars['portfolio'] = (theme_get_setting('portfolio-view-all') != '') ? $GLOBALS['base_url'].'/'.theme_get_setting('portfolio-view-all') : '';
 	}
 	
	/* Breadcrumbs */
	function dawn_breadcrumb($vars) {
		if (!(drupal_is_front_page())) {
			$theme = dawn_get_theme();
			$trail        = menu_get_active_trail();
			$lastInTrail  = current($trail);
			if (isset($lastInTrail['menu_name'])) {
				$menu_name = $lastInTrail['menu_name'];
			}
			$breadcrumb = $vars['breadcrumb'];
			$crumbs = '';
			$blog = (theme_get_setting('blog-view-all') != '') ? '<a href="'.$GLOBALS['base_url'].'/'.theme_get_setting('blog-view-all').'">Blog</a>' : 'Blog';
			$services = (theme_get_setting('services-view-all') != '') ? '<a href="'.$GLOBALS['base_url'].'/'.theme_get_setting('services-view-all').'">Services</a>' : 'Services';
			
			if (!empty($breadcrumb)) {
				$crumbs = '<ul class="breadcrumb"><li><i class="icon-home"></i></li>';
				foreach($breadcrumb as $value) {
					$crumbs .= '<li>' . $value . ' / </li>';
				}
				if (isset($menu_name) && isset($GLOBALS['node'])) {
					if ($menu_name != 'main-menu') {
						$type = node_type_get_name($GLOBALS['node']->type);
						switch($type) {
							case 'Blog Post': $crumbs .= '<li>'.$blog.' / </li>'; break;
							case 'Services': $crumbs .= '<li>'.$services.' / </li>'; break;
							default: $crumbs .= '<li>'.$type.' / </li>';
						}
					}
				}
				$crumbs .= '<li class="current">' . drupal_get_title() . '</li></ul>';
			}
			return $crumbs;
		}
	}
	
	/* Menu Links */
	function dawn_menu_link(&$vars) {
		$element = &$vars['element'];
		$sub_menu = '';
	
		if ($element['#href'] == '<front>' && drupal_is_front_page()) {
			$element['#attributes']['class'][] = 'active-trail';
		}
		
		if ($element['#below']) {
			$sub_menu = drupal_render($element['#below']);
		}
		
		$output = l($element['#title'], $element['#href'], $element['#localized_options']);
		return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
	}

	function dawn_menu_tree($vars) {
	  return '<ul class="menu clearfix">' . $vars['tree'] . '</ul>';
	}
	
	/* HTML Preprocessing */
	function dawn_preprocess_html(&$vars) {
		$theme = dawn_get_theme();
		$vars['classes_array'][] = 'no-js';
		$vars['custom_css'] = '<link href="'.$GLOBALS['base_url'].'/'.path_to_theme().'/dawn.php" rel="stylesheet" type="text/css" />';
		$vars['jquery'] = '<script type="text/javascript" src="'.$GLOBALS['base_url'].'/'.path_to_theme().'/js/jquery.min.js"></script>';
		$image_url = '';
		
		if (!theme_get_setting('footer-background-image') == NULL) {
			$footer_url = '#footer { background-image: url(' . file_create_url(file_load(theme_get_setting('footer-background-image'))->uri) . ');}';
			drupal_add_css($footer_url, 'inline', array('every_page' => TRUE, 'preprocess' => TRUE));
		}
		
		if (theme_get_setting('theme-background') == 'custom') {
			$image_url = '#page { background: url(' . file_create_url(file_load(theme_get_setting('theme-custom-background'))->uri) . ');}';
		} else {
			$image_url = '#page { background: url('.$GLOBALS['base_url'].'/'.path_to_theme().'/img/background/'.theme_get_setting('theme-background').'.png); }';
		}
		
		if ((!theme_get_setting('theme-background') == NULL) || (!theme_get_setting('theme-custom-background') == NULL)) {
			drupal_add_css($image_url, 'inline', array('every_page' => TRUE, 'preprocess' => TRUE));
		}
	}
	
	/* Page Preprocessing */
	function dawn_preprocess_page(&$vars) {
		$theme = dawn_get_theme();
		$theme->page = &$vars;
		$sidebar_left = 12 - theme_get_setting('sidebar_first_grid');
		$sidebar_right = 12 - theme_get_setting('sidebar_second_grid');
		$sidebar_both = 12 - (theme_get_setting('sidebar_first_grid') + theme_get_setting('sidebar_second_grid'));
		$vars['front'] = drupal_is_front_page();
		$vars['blog-link'] = $GLOBALS['base_url'].'/'.theme_get_setting('blog-view-all');
		$vars['portfolio-link'] = $GLOBALS['base_url'].'/'.theme_get_setting('portfolio-view-all');
		$vars['services-link'] = $GLOBALS['base_url'].'/'.theme_get_setting('services-view-all');
		$vars['social'] = array('Behance', 'Dribbble', 'Facebook', 'Flickr', 'Google Plus', 'LinkedIn', 'MySpace', 'Pinterest', 'Tumblr', 'Twitter', 'Vimeo', 'YouTube');
		
		if (!empty($vars['page']['sidebar_first']) && !empty($vars['page']['sidebar_second'])) {
			$vars['content_settings'] = 'span' . $sidebar_both;
		}
		else if (!empty($vars['page']['sidebar_first']) && empty($vars['page']['sidebar_second'])) {
			$vars['content_settings'] = 'span' . $sidebar_left;
		}
		else if (empty($vars['page']['sidebar_first']) && !empty($vars['page']['sidebar_second'])) {
			$vars['content_settings'] = 'span' . $sidebar_right;
		} else {
			$vars['content_settings'] = (theme_get_setting('content_grid') !== 'none') ? 'span'. theme_get_setting('content_grid') : 'span12';
		}
			
		if ($vars['front']) { unset($vars['page']['content']['system_main']); }
		
		if (!drupal_is_front_page()) {
			$vars['title_prefix'] = '<header id="masthead" class="masthead">';
			$vars['title_suffix'] = '<div class="divider"></div></header>';
		}
		
		if (isset($vars['node'])) {
			global $node;
			$node = $vars['node'];
			
			$id = drupal_html_id($vars['node']->type);
			$masthead = '';
			
			if ((empty($vars['node']->field_custom_header)) && (theme_get_setting($id.'-background') != '')) {
				$masthead = '#masthead { background: url(' . file_create_url(file_load(theme_get_setting($id.'-background'))->uri) . ');}';
			} else if(!(empty($vars['node']->field_custom_header))) {
				$masthead = '#masthead { background: url(' . file_create_url($vars['node']->field_custom_header['und'][0]['uri']) . ');}';
			}
			
			drupal_add_css($masthead, 'inline', array('every_page' => TRUE, 'preprocess' => TRUE));
			
			if (!(theme_get_setting($id.'-title') == NULL)) {
				$vars['title'] = theme_get_setting($id.'-title');
			}
		}
		
	}
	
	/* Contact Us Page */
	function dawn_preprocess_page_contact(&$vars) {
		$theme = dawn_get_theme();
		$vars['title_prefix'] = '<header id="header" class="map">';
		$vars['title_suffix'] = '</header>';
	}
	
	/* Node Preprocessing */
	function dawn_preprocess_node(&$vars) {
		if (module_exists('statistics')) {
			unset($vars['content']['links']['statistics']['#links']['statistics_counter']['title']);
		}
	}
	
	/* Region Preprocessing */	 			
	 function dawn_preprocess_region(&$vars) {
	 	$theme = dawn_get_theme();
	 	$vars['classes_array'] = array(drupal_html_id($vars['region']));
	 	$span = theme_get_setting($vars['region'] . '_grid');
	 	$offset = theme_get_setting($vars['region'] . '_offset');
	 	$vars['front'] = drupal_is_front_page();
	 	
	 	switch ($vars['region']) {
	 		case 'content': $vars['classes_array'][] = $theme->page['content_settings'];
                            if(arg(0) == 'lc')
                                $vars['classes_array'][1] = 'lcPage';
                            break;
	 		case 'footer': $vars['classes_array'][] = 'container'; break;
	 		default: if ($span != 'none') { $vars['classes_array'][] = ('span'.$span); } break;
	 	}
	 	
	 	if (($offset != 'none')) { $vars['classes_array'][] = $offset; }
	 }
	 
	 /* Block Preprocessing */
	 function dawn_preprocess_block(&$vars) {
	 	$theme = dawn_get_theme();
	 	$block = $vars['block']->module . '-' . $vars['block']->delta;
	 	$classes = &$vars['classes_array'];
	 	$title_classes = &$vars['title_attributes_array']['class'];
	 	$vars['front'] = drupal_is_front_page();
	 
	 	switch ($block) {
	 		case 'system-main-menu':
	 			$classes[] = 'main-menu';
				$title_classes[] = 'element-invisible';
			break;
	 		case 'views-dawn_homepage-services':
	 			$vars['title_suffix'] = '<div class="title-suffix">
	 			<a href="'.$theme->page['services-link'].'">view all services &rarr;</a></div>';
			break;
	 		case 'views-dawn_homepage-portfolio':
	 			$vars['title_suffix'] = '<div class="title-suffix">
	 			<a href="'.$theme->page['portfolio-link'].'">view full portfolio &rarr;</a></div>';
			break;
	 		case 'views-dawn_homepage-blog':
	 			$vars['title_suffix'] = '<div class="title-suffix">
	 			<a href="'.$theme->page['blog-link'].'">view all posts &rarr;</a></div>';
			break;
	 	}
	 	
		 	switch ($vars['block']->title) {
		 		case 'Copyright Text': $title_classes[] = 'element-invisible'; break;
		 	}
	 	}
	 
	 /* View Preprocessing */
	 function dawn_preprocess_views_view(&$vars) {
	 	if (!theme_get_setting('portfolio-background') == NULL) {
	 		$portfolio = '#masthead { background: url(' . file_create_url(file_load(theme_get_setting('portfolio-background'))->uri) . ');}';
	 	}
	 	if (!theme_get_setting('blog-post-background') == NULL) {
	 		$blog = '#masthead { background: url(' . file_create_url(file_load(theme_get_setting('blog-post-background'))->uri) . ');}';
	 	}
	 	if (!theme_get_setting('services-background') == NULL) {
	 		$services = '#masthead { background: url(' . file_create_url(file_load(theme_get_setting('services-background'))->uri) . ');}';
	 	}
	 	switch ($vars['name']) {
	 		case 'dawn_portfolio': 
			if (!theme_get_setting('portfolio-background') == NULL) { 
				drupal_add_css($portfolio, 'inline', array('preprocess' => TRUE)); 
			}
			break;
	 		case 'dawn_blog': 
			if (!theme_get_setting('blog-post-background')  == NULL) {
				drupal_add_css($blog, 'inline', array('preprocess' => TRUE));
			}
			break;
	 		case 'dawn_services': 
			if (!theme_get_setting('services-background') == NULL) {
				drupal_add_css($services, 'inline', array('preprocess' => TRUE)); 
			}
			break;
	 	}
	 }
	 
	 /* Forum Preprocessing */
	 function dawn_preprocess_forums(&$vars) {
	 	if (!theme_get_setting('forum-topic-background') == NULL) {
	 		$masthead = '#masthead { background: url(' . file_create_url(file_load(theme_get_setting('forum-topic-background'))->uri) . ');}';
	 		drupal_add_css($masthead, 'inline', array('preprocess' => TRUE));
	 	}
	 }
	 
	 /* Region Processing */
	 function dawn_process_region(&$vars) {
	 	$theme = dawn_get_theme();
	 	$get_form = drupal_get_form('search_form');
	 	
	 	switch ($vars['elements']['#region']) {
	 		case 'navigation':
 			$vars['main_menu'] = $theme->page['main_menu'];
 			$vars['secondary_menu'] = $theme->page['secondary_menu'];
 			$vars['site_name'] = $theme->page['site_name'];
 			$vars['linked_site_name'] = l($vars['site_name'], '<front>', array('attributes' => array('title' => t('Home')), 'html' => TRUE));
 			$vars['site_slogan'] = $theme->page['site_slogan'];
 			$vars['logo'] = $theme->page['logo'];
 			$vars['logo_img'] = $vars['logo'] ? '<img src="' . $vars['logo'] . '" alt="' . check_plain($vars['site_name']) . '" id="logo" />' : '';
 			$vars['linked_logo_img'] = $vars['logo'] ? l($vars['logo_img'], '<front>', array('attributes' => array('rel' => 'home', 'title' => check_plain($vars['site_name'])), 'html' => TRUE)) : '';
 			$vars['social'] = $theme->page['social']; 
			$vars['search_box'] = drupal_render($get_form);
 			$vars['profile'] = $GLOBALS['base_url'].'/user';
 			break;
	 		
	 		case 'content':
		 	$vars['messages'] = $theme->page['messages'];
		 	$vars['breadcrumb'] = $theme->page['breadcrumb'];
		 	$vars['title_prefix'] = $theme->page['title_prefix'];
		 	$vars['title'] = $theme->page['title'];
		 	$vars['title_suffix'] = $theme->page['title_suffix'];
		 	$vars['tabs'] = $theme->page['tabs'];
		 	$vars['action_links'] = $theme->page['action_links'];
		 	$vars['feed_icons'] = $theme->page['feed_icons'];
		 	break; 	
	 	}
	 }
	 
?>