<?php

/**
 * @file
 * General theme settings elements.
 */

function dawn_settings_submit($form, &$form_state) {
	$types = node_type_get_names();
	$images = array($form_state['values']['theme-custom-background'],
					$form_state['values']['footer-background-image']);
	
	foreach ($types as $item) {
		$item_id = drupal_html_id($item);
		array_push($images, $form_state['values'][$item_id.'-background']);
	}
	
	foreach ($images as $item) {
		if (!empty($item)) {
			/* Permanently Save Managed Files */
			$fid = $item;
			$file = file_load($fid);
			$file->status = FILE_STATUS_PERMANENT;
			file_save($file);
			file_usage_add($file, 'dawn', 'dawn', $item);
		}
	}
}

function dawn_form_system_theme_settings_alter(&$form, &$form_state) {
	
	$theme = $GLOBALS['theme_key'];
	$themes = list_themes();
	$types = node_type_get_names();
	
	$form_state['build_info']['files'][] = str_replace("/$theme.info", '', $themes[$theme]->filename) . '/theme-settings.php';
	
	$form['dawn_settings'] = array(
			'#type' => 'vertical_tabs',
			'#weight' => -10,
			'#prefix' => t('<h3>Dawn: Theme Settings</h3>'),
	);

	$form['dawn_settings']['#attached']['js'] = array(
			drupal_get_path('theme', 'dawn') . '/js/plugins/colorpicker.js',
			drupal_get_path('theme', 'dawn') . '/js/admin.js',
	);

	$form['dawn_settings']['#attached']['css'] = array(
			drupal_get_path('theme', 'dawn') . '/css/admin.css',
	);

	/* Global Settings */
	
	dawn_settings_global_tab($form);
	
	/* General Settings */
	
	$form['dawn_settings']['general'] = array(
			'#type' => 'fieldset',
			'#title' => t('General'),
	);
	
	$form['dawn_settings']['general']['highlight-color'] = array(
			'#type' => 'textfield',
			'#field_prefix' => '#',
			'#title' => t('Highlight color:'),
			'#maxlength' => 7,
			'#description' => t('Select a highlight color to be used sitewide on navigation items, thumnails, and page elements.'),
			'#default_value' => theme_get_setting('highlight-color'),
	);
	
	$form['dawn_settings']['general']['google-maps']= array(
			'#type' => 'fieldset',
			'#title' => t('Google Maps'),
			'#description' => t('Enter the latitude/longitude coordinates of your address. To lookup a set of coordinates, visit 
					<a href="http://itouchmap.com/latlong.html" target="_blank">iTouchMap.com</a> and enter the street address.'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['dawn_settings']['general']['google-maps']['latitude'] = array(
			'#type' => 'textfield',
			'#title' => t('Longitude'),
			'#default_value' => theme_get_setting('latitude'),
	);
	
	$form['dawn_settings']['general']['google-maps']['longitude'] = array(
			'#type' => 'textfield',
			'#title' => t('Longitude'),
			'#default_value' => theme_get_setting('longitude'),
	);
	
	$form['dawn_settings']['general']['google-analytics']= array(
			'#type' => 'fieldset',
			'#title' => t('Google Analytics'),
			'#description' => t('Paste a javascript code snippet from Google Analytics in the header or footer region.'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['dawn_settings']['general']['google-analytics']['analytics-location'] = array(
			'#type'          => 'radios',
			'#default_value' => theme_get_setting('analytics-location'),
			'#description' => t('Where should the analytics code be loaded?'),
			'#options'       => array(
					'header' => t('Header'),
					'footer' => t('Footer'),
			),
	);
	
	$form['dawn_settings']['general']['twitter-feed']= array(
			'#type' => 'fieldset',
			'#title' => t('Twitter Feed'),
			'#description' => t('Enter the credentials for your Twitter Feed. If you have not done so, you will need to obtain these credentials by setting up an application at <a href="https://dev.twitter.com/apps" target="_blank">https://dev.twitter.com/apps</a>'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['dawn_settings']['general']['twitter-feed']['twitter-consumer-key'] = array(
			'#type'          => 'textfield',
			'#title' => t('Consumer Key'),
			'#default_value' => theme_get_setting('twitter-consumer-key'),
	);
	
	$form['dawn_settings']['general']['twitter-feed']['twitter-consumer-secret'] = array(
			'#type'          => 'textfield',
			'#title' => t('Consumer Secret'),
			'#default_value' => theme_get_setting('twitter-consumer-secret'),
	);
	
	$form['dawn_settings']['general']['twitter-feed']['twitter-access-token'] = array(
			'#type'          => 'textfield',
			'#title' => t('Access Token'),
			'#default_value' => theme_get_setting('twitter-access-token'),
	);
	
	$form['dawn_settings']['general']['twitter-feed']['twitter-access-secret'] = array(
			'#type'          => 'textfield',
			'#title' => t('Access Token Secret'),
			'#suffix' => '<p>Once these credentials are entered, head on over to Structure > Blocks and edit the "Footer: Twitter Feed" block. Enter your twitter username into the "data-twitter" attribute, and the Twitter feed configuration will be complete.</p>',
			'#default_value' => theme_get_setting('twitter-access-secret'),
	);
	
	$form['dawn_settings']['general']['google-analytics']['analytics-code'] = array(
			'#title' => t('Analytics Code:'),
			'#type' => 'textarea',
			'#description' => t('Post the code snippet for Google Analytics. Make sure the &lt;script&gt;&lt;/script&gt; tags are are included!'),
			'#default_value' => theme_get_setting('analytics-code'),
	);
	

	$social = array('Behance', 'Dribbble', 'Facebook', 'Google Plus', 'LinkedIn', 'MySpace', 'Pinterest', 'Tumblr', 'Twitter', 'Vimeo', "YouTube");
	
	$form['dawn_settings']['general']['social-icons'] = array(
			'#type' => 'fieldset',
			'#title' => t('Social Media Icons'),
			'#description' => t('Toggle social media icons. Icons will be displayed in both the header and footer regions.'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	foreach ($social as $item) {
		$item_id = drupal_html_id($item);
	
		$form['dawn_settings']['general']['social-icons'][$item_id . '-icon'] = array(
				'#type' => 'checkbox',
				'#prefix'=> '<div class="icon-wrap '.$item_id.'">',
				'#title' => t($item),
				'#default_value' => theme_get_setting($item_id . '-icon'),
		);
	
		$form['dawn_settings']['general']['social-icons'][$item_id . '-url'] = array(
				'#type' => 'textfield',
				'#suffix' => '</div>',
				'#description' => t('Enter the URL to your '.$item.' profile.'),
				'#default_value' => theme_get_setting($item_id . '-url'),
				'#states' => array(
						'disabled' => array(      // Action to take: check the checkbox.
								':input[name="'.$item_id.'-icon"]' =>  array('checked' => FALSE),
						),
				),
		);
	}
	
	$form['dawn_settings']['background'] = array(
			'#type' => 'fieldset',
			'#title' => t('Background'),
			'#description' => t('Set the background image and background color. If an alternate image is needed, <a href="http://www.subtlepatterns.com/" target="_blank">Subtle Patterns</a> offers 
					hundreds of options. Custom background images can be uploaded by selecting the "Upload Image" button. <br/><br/>'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['dawn_settings']['background']['background-color'] = array(
			'#type' => 'textfield',
			'#field_prefix' => '#',
			'#title' => t('Background color:'),
			'#maxlength' => 7,
			'#description' => t('Select a background color.'),
			'#default_value' => theme_get_setting('background-color'),
	);
	
	$form['dawn_settings']['background']['theme-background'] = array(
			'#type'          => 'radios',
			'#default_value' => theme_get_setting('theme-background'),
			'#options'       => array(
					'no-background' => t('No Background Image'),
					'tiny-grid' => t('Tiny Grid'),
					'squairy-light' => t('Squairy'),
					'corrigation' => t('Corrigation'),
					'debut-light' => t('Debut Light'),
					'grid-noise' => t('Grid Noise'),
					'fiber' => t('Fiber'),
					'dust' => t('Dust'),
					'striped-lens' => t('Striped Lens'),
					'freckles' => t('Freckles'),
					'subtle-net' => t('Subtle Net'),
					'white-wave' => t('White Wave'),
					'custom' => t('Upload Image'),
			),
	);
	
	
	$form['dawn_settings']['background']['theme-custom-background'] = array(
			'#title' => 'Upload Custom Background',
			'#type' => 'managed_file',
			'#upload_validators' => array(
					'file_validate_extensions' => array(0 => 'png jpg jpeg gif'),
			),
			'#upload_location' => 'public://default_images/',
			'#description' => t("Upload an image."),
			'#default_value' => theme_get_setting('theme-custom-background'),
			'#states' => array(
					'visible' => array(      // Action to take: check the checkbox.
							':input[name="theme-background"]' =>  array('value' => 'custom'),
					),
			),
	);
	
	/* Homepage Settings */
	$form['dawn_settings']['general']['variables'] = array(
			'#type' => 'fieldset',
			'#title' => t('Variables'),
			'#description' => t('If you are using the portfolio, service, or blog section on your site please enter the URL to the page below. 
					These variables will be used in the breadcrumb, for the homepage "view all" links, and on individual portfolio items.'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['dawn_settings']['general']['variables']['blog-view-all'] = array(
			'#type' => 'textfield',
			'#title' => t('Enter the path to the blog landing page:'),
			'#field_prefix' => $GLOBALS['base_url'].'/',
			'#field_suffix' => '<br/>',
			'#default_value' => theme_get_setting('blog-view-all'),
	);
	
	$form['dawn_settings']['general']['variables']['portfolio-view-all'] = array(
			'#type' => 'textfield',
			'#title' => t('Enter the path to the portfolio landing page:'),
			'#field_prefix' => $GLOBALS['base_url'].'/',
			'#field_suffix' => '<br/>',
			'#default_value' => theme_get_setting('portfolio-view-all'),
	);
	
	$form['dawn_settings']['general']['variables']['services-view-all'] = array(
			'#type' => 'textfield',
			'#title' => t('Enter the path to the services landing page:'),
			'#field_prefix' => $GLOBALS['base_url'].'/',
			'#field_suffix' => '<br/>',
			'#default_value' => theme_get_setting('services-view-all'),
	);

	/* Typography */
	
	require_once dirname(__FILE__) . '/includes/typography.inc';

	/* Region Settings */
	
	require_once dirname(__FILE__) . '/includes/regions.inc';

	/* Header Settings */
	
	$form['dawn_settings']['header'] = array(
			'#type' => 'fieldset',
			'#title' => t('Header'),
			'#description' => t('Configure the header settings.'),
	);
	
	$form['dawn_settings']['header']['navigation'] = array(
			'#type' => 'fieldset',
			'#title' => t('Navigation Bar'),
			'#description' => t('Configure the background settings for the navigation bar.'),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
	);
	
	$form['dawn_settings']['header']['navigation']['header-background'] = array(
			'#type' => 'textfield',
			'#prefix' => '<div class="header-bg">',
			'#field_prefix' => '#',
			'#title' => t('Background color:'),
			'#maxlength' => 7,
			'#description' => t('Select a background color for the navigation bar.'),
			'#default_value' => theme_get_setting('header-background'),
	);
	
	$form['dawn_settings']['header']['navigation']['header-opacity'] = array(
			'#type' => 'textfield',
			'#suffix' => '</div>',
			'#field_suffix' => '%',
			'#title' => t('Background opacity:'),
			'#maxlength' => 3,
			'#description' => t('Set the opacity of the navigation bar background.'),
			'#default_value' => theme_get_setting('header-opacity'),
	);
	
	$form['dawn_settings']['header']['masthead-images'] = array(
			'#type' => 'fieldset',
			'#title' => t('Masthead'),
			'#description' => t('Configure the default masthead image and title for each content type. The default settings can be overwritten
					for individual nodes on the node edit form.'),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
	);
	
	foreach ($types as $item) {
		$item_id = drupal_html_id($item);
		$form['dawn_settings']['header']['masthead-images'][$item] = array(
				'#type' => 'fieldset',
				'#title' => t($item),
				'#collapsible' => TRUE,
				'#collapsed' => TRUE,
		);
		$form['dawn_settings']['header']['masthead-images'][$item][$item_id.'-background'] = array(
				'#title' => 'Background Image:',
				'#type' => 'managed_file',
				'#description' => t('Recommended image dimensions (in pixels) is 1920x220.'),
				'#upload_validators' => array(
						'file_validate_extensions' => array(0 => 'png jpg jpeg gif'),
				),
				'#upload_location' => 'public://dawn/masthead/',
				'#default_value' => theme_get_setting($item_id.'-background'),
		);
		$form['dawn_settings']['header']['masthead-images'][$item][$item_id.'-title'] = array(
				'#type' => 'textfield',
				'#title' => t('Custom Title'),
				'#description' => t('Enter a value to override the header title for this content type. If left blank, the header title will default to the title of the node being viewed.'),
				'#default_value' => theme_get_setting($item_id.'-title'),
		);
	}

	/* Footer Settings */
	
	$form['dawn_settings']['footer'] = array(
			'#type' => 'fieldset',
			'#title' => t('Footer'),
			'#description' => t('Configure the footer settings.'),
	);
	
	$form['dawn_settings']['footer']['footer-background'] = array(
			'#type' => 'textfield',
			'#field_prefix' => '#',
			'#field_suffix' => '<br/>',
			'#title' => t('Background color:'),
			'#maxlength' => 7,
			'#description' => t('Select a background color for the footer section.'),
			'#default_value' => theme_get_setting('footer-background'),
	);
	
	$form['dawn_settings']['footer']['footer-background-image'] = array(
			'#name' => 'Upload Custom Background',
			'#type' => 'managed_file',
			'#title' => t('Background image:'),
			'#upload_validators' => array(
					'file_validate_extensions' => array(0 => 'png jpg jpeg gif'),
			),
			'#upload_location' => 'public://default_images/',
			'#description' => t("Upload an image."),
			'#default_value' => theme_get_setting('footer-background-image'),
	);
	
	$form['dawn_settings']['footer']['footer-toggle-rss'] = array(
			'#type' => 'checkbox',
			'#title' => t('RSS Feed'),
			'#default_value' => theme_get_setting('footer-toggle-rss'),
			'#description' => t('Add RSS to Social Links'),
	);
	
	$form['dawn_settings']['footer']['footer-rss-url'] = array(
			'#type' => 'textfield',
			'#title' => t('Feed URL:'),
			'#description' => t('Enter the URL to the RSS feed.'),
			'#default_value' => theme_get_setting('footer-rss-url'),
			'#states' => array(
					'visible' => array(      // Action to take: check the checkbox.
							':input[name="footer-toggle-rss"]' =>  array('checked' => TRUE),
					),
			),
	);
	
	$form['dawn_settings']['footer']['copyright'] = array(
			'#type' => 'textfield',
			'#title' => t('Copyright Text'),
			'#description' => t('Configure the copyright text at the bottom of the page.'),
			'#default_value' => theme_get_setting('copyright'),
	);
	
		
	$form['#submit'][] = 'dawn_settings_submit';
}

function dawn_settings_global_tab(&$form) {
	// Toggles
	$form['theme_settings']['toggle_logo']['#default_value'] = theme_get_setting('toggle_logo');
	$form['theme_settings']['toggle_name']['#default_value'] = theme_get_setting('toggle_name');
	$form['theme_settings']['toggle_slogan']['#default_value'] = theme_get_setting('toggle_slogan');
	$form['theme_settings']['toggle_node_user_picture']['#default_value'] = theme_get_setting('toggle_node_user_picture');
	$form['theme_settings']['toggle_comment_user_picture']['#default_value'] = theme_get_setting('toggle_comment_user_picture');
	$form['theme_settings']['toggle_comment_user_verification']['#default_value'] = theme_get_setting('toggle_comment_user_verification');
	$form['theme_settings']['toggle_favicon']['#default_value'] = theme_get_setting('toggle_favicon');
	$form['theme_settings']['breadcrumb_display'] = array(
			'#type' => 'checkbox',
			'#title' => t('Display breadcrumb'),
			'#default_value' => theme_get_setting('breadcrumb_display'),
	);
	
	$form['theme_settings']['toggle_main_menu'] = array(
			'#type' => 'hidden',
			'#default_value' => theme_get_setting('toggle_main_menu'),
	);
	$form['theme_settings']['toggle_secondary_menu'] = array(
			'#type' => 'hidden',
			'#default_value' => theme_get_setting('toggle_secondary_menu'),
	);

	$form['logo']['default_logo']['#default_value'] = theme_get_setting('default_logo');
	$form['logo']['settings']['logo_path']['#default_value'] = theme_get_setting('logo_path');
	$form['favicon']['default_favicon']['#default_value'] = theme_get_setting('default_favicon');
	$form['favicon']['settings']['favicon_path']['#default_value'] = theme_get_setting('favicon_path');

	$form['dawn_settings']['global_settings'] = array(
			'#type' => 'fieldset',
			'#title' => t('Global'),
			'#weight' => -1,
	);
	
	$form['theme_settings']['#collapsible'] = TRUE;
	$form['theme_settings']['#collapsed'] = TRUE;
	$form['logo']['#collapsible'] = TRUE;
	$form['logo']['#collapsed'] = TRUE;
	$form['favicon']['#collapsible'] = TRUE;
	$form['favicon']['#collapsed'] = TRUE;
	$form['dawn_settings']['global_settings']['theme_settings'] = $form['theme_settings'];
	$form['dawn_settings']['global_settings']['logo'] = $form['logo'];
	$form['dawn_settings']['global_settings']['favicon'] = $form['favicon'];
	

	unset($form['theme_settings']);
	unset($form['logo']);
	unset($form['favicon']);
}

?>