<?php

$sections = array('header', 'prescript', 'main', 'postscript', 'footer');

$form['dawn_settings']['regions'] = array(
		'#type' => 'fieldset',
		'#title' => t('Regions'),
		'#description' => t('Configure the region settings. The grid width setting for each region corresponds to the 12-column grid used with the Twitter Bootstrap framework. Refer to the <a href="http://twitter.github.io/bootstrap/scaffolding.html#gridSystem" target="_blank">Twitter Bootstrap documentation</a> for more information.'),
		'#attributes' => array('class' => array('region-item'), 'title' => t('')),
);

foreach($sections as $item) {
	switch($item) {
		case 'main':
		$form['dawn_settings']['regions'][$item] = array(
				'#type' => 'fieldset',
				'#title' => $item,
				'#description' => t('Configure the region settings for the '.$item.' section. It is highly recommended that the grid width of
				the <em>content region</em> is set to "none" -- the width of this region will be dictated by the width of the sidebars.'),
				'#collapsible' => FALSE,
				'#collapsed' => FALSE,
		);			
		break;
			
		default:
		$form['dawn_settings']['regions'][$item] = array(
				'#type' => 'fieldset',
				'#title' => $item,
				'#description' => t('Configure the region settings for the '.$item.' section.'),
				'#collapsible' => FALSE,
				'#collapsed' => FALSE,
		);
		break;
	}
}

foreach (system_region_list('dawn') as $region => $title) {
	if (($region !== 'dashboard_main') && ($region !== 'dashboard_sidebar') && ($region !== 'dashboard_inactive')) {
		switch($region) {
			case 'navigation': case 'header': case 'user_login': case 'user_menu':
				
				$form['dawn_settings']['regions']['header'][$region] = array(
						'#type' => 'fieldset',
						'#title' => $title,
						'#collapsible' => TRUE,
						'#collapsed' => TRUE,
				);

				$form['dawn_settings']['regions']['header'][$region][$region . '_grid'] = array(
					'#type'          => 'select',
					'#title'         => t('Grid Width:'),
					'#default_value' => theme_get_setting($region . '_grid'),
					'#options'       => array(
						'none' => t('None'),
						'1' => t('span1'),
						'2' => t('span2'),
						'3' => t('span3'),
						'4' => t('span4'),
						'5' => t('span5'),
						'6' => t('span6'),
						'7' => t('span7'),
						'8' => t('span8'),
						'9' => t('span9'),
						'10' => t('span10'),
						'11' => t('span11'),
						'12' => t('span12'),
					),
				);
				$form['dawn_settings']['regions']['header'][$region][$region . '_offset'] = array(
						'#type'          => 'textfield',
						'#title'         => t('CSS Classes:'),
						'#description' => t('Attach additional CSS classes to this region.'),
						'#default_value' => theme_get_setting($region . '_offset'),
				);
				
			break;
			
			case 'prescript_first': case 'prescript_second': case 'prescript_third': case 'prescript_fourth': 
				
				$form['dawn_settings']['regions']['prescript'][$region] = array(
						'#type' => 'fieldset',
						'#title' => $title,
						'#collapsible' => TRUE,
						'#collapsed' => TRUE,
				);

				$form['dawn_settings']['regions']['prescript'][$region][$region . '_grid'] = array(
					'#type'          => 'select',
					'#title'         => t('Grid Width:'),
					'#default_value' => theme_get_setting($region . '_grid'),
					'#options'       => array(
						'none' => t('None'),
						'1' => t('span1'),
						'2' => t('span2'),
						'3' => t('span3'),
						'4' => t('span4'),
						'5' => t('span5'),
						'6' => t('span6'),
						'7' => t('span7'),
						'8' => t('span8'),
						'9' => t('span9'),
						'10' => t('span10'),
						'11' => t('span11'),
						'12' => t('span12'),
					),
				);
				$form['dawn_settings']['regions']['prescript'][$region][$region . '_offset'] = array(
						'#type'          => 'textfield',
						'#title'         => t('CSS Classes:'),
						'#description' => t('Attach additional CSS classes to this region.'),
						'#default_value' => theme_get_setting($region . '_offset'),
				);
				
			break;
			
			case 'sidebar_first': case 'content': case 'sidebar_second':
				
				$form['dawn_settings']['regions']['main'][$region] = array(
						'#type' => 'fieldset',
						'#title' => $title,
						'#collapsible' => TRUE,
						'#collapsed' => TRUE,
				);

				$form['dawn_settings']['regions']['main'][$region][$region . '_grid'] = array(
					'#type'          => 'select',
					'#title'         => t('Grid Width:'),
					'#default_value' => theme_get_setting($region . '_grid'),
					'#options'       => array(
						'none' => t('None'),
						'1' => t('span1'),
						'2' => t('span2'),
						'3' => t('span3'),
						'4' => t('span4'),
						'5' => t('span5'),
						'6' => t('span6'),
						'7' => t('span7'),
						'8' => t('span8'),
						'9' => t('span9'),
						'10' => t('span10'),
						'11' => t('span11'),
						'12' => t('span12'),
					),
				);
				$form['dawn_settings']['regions']['main'][$region][$region . '_offset'] = array(
						'#type'          => 'textfield',
						'#title'         => t('CSS Classes:'),
						'#description' => t('Attach additional CSS classes to this region.'),
						'#default_value' => theme_get_setting($region . '_offset'),
				);
				
			break;
			
				
			case 'postscript_first': case 'postscript_second': case 'postscript_third': case 'postscript_fourth':
					
				$form['dawn_settings']['regions']['postscript'][$region] = array(
				'#type' => 'fieldset',
				'#title' => $title,
				'#collapsible' => TRUE,
				'#collapsed' => TRUE,
				);
					
				$form['dawn_settings']['regions']['postscript'][$region][$region . '_grid'] = array(
						'#type'          => 'select',
						'#title'         => t('Prefix'),
						'#default_value' => theme_get_setting($region . '_grid'),
						'#options'       => array(
								'none' => t('None'),
								'1' => t('span1'),
								'2' => t('span2'),
								'3' => t('span3'),
								'4' => t('span4'),
								'5' => t('span5'),
								'6' => t('span6'),
								'7' => t('span7'),
								'8' => t('span8'),
								'9' => t('span9'),
								'10' => t('span10'),
								'11' => t('span11'),
								'12' => t('span12'),
						),
				);
				$form['dawn_settings']['regions']['postscript'][$region][$region . '_offset'] = array(
						'#type'          => 'textfield',
						'#title'         => t('Add CSS Class:'),
						'#description' => t('Attach additional CSS classes to this region.'),
						'#default_value' => theme_get_setting($region . '_offset'),
				);
					
				break;
					
			case 'footer_first': case 'footer_second': case 'footer_third': case 'footer_fourth':
					
				$form['dawn_settings']['regions']['footer'][$region] = array(
				'#type' => 'fieldset',
				'#title' => $title,
				'#collapsible' => TRUE,
				'#collapsed' => TRUE,
				);
					
				$form['dawn_settings']['regions']['footer'][$region][$region . '_grid'] = array(
						'#type'          => 'select',
						'#title'         => t('Prefix'),
						'#default_value' => theme_get_setting($region . '_grid'),
						'#options'       => array(
								'none' => t('None'),
								'1' => t('span1'),
								'2' => t('span2'),
								'3' => t('span3'),
								'4' => t('span4'),
								'5' => t('span5'),
								'6' => t('span6'),
								'7' => t('span7'),
								'8' => t('span8'),
								'9' => t('span9'),
								'10' => t('span10'),
								'11' => t('span11'),
								'12' => t('span12'),
						),
				);
				$form['dawn_settings']['regions']['footer'][$region][$region . '_offset'] = array(
						'#type'          => 'textfield',
						'#title'         => t('CSS Classes:'),
						'#description' => t('Attach additional CSS classes to this region.'),
						'#default_value' => theme_get_setting($region . '_offset'),
				);
					
				break;

				default:
					
				$form['dawn_settings']['regions'][$region] = array(
					'#type' => 'fieldset',
					'#title' => $title,
					'#description' => t('Configure the ' . $title . ' region settings.'),
					'#collapsible' => TRUE,
					'#collapsed' => TRUE,
				);
				
				$form['dawn_settings']['regions'][$region][$region . '_grid'] = array(
						'#type'          => 'select',
						'#title'         => t('Prefix'),
						'#default_value' => theme_get_setting($region . '_grid'),
						'#options'       => array(
								'none' => t('None'),
								'1' => t('span1'),
								'2' => t('span2'),
								'3' => t('span3'),
								'4' => t('span4'),
								'5' => t('span5'),
								'6' => t('span6'),
								'7' => t('span7'),
								'8' => t('span8'),
								'9' => t('span9'),
								'10' => t('span10'),
								'11' => t('span11'),
								'12' => t('span12'),
						),
				);
				$form['dawn_settings']['regions'][$region][$region . '_offset'] = array(
						'#type'          => 'textfield',
						'#title'         => t('Add CSS Class:'),
						'#description' => t('Attach additional CSS classes to this region.'),
						'#default_value' => theme_get_setting($region . '_offset'),
				);
				break;
		}
	}
}
	
?>