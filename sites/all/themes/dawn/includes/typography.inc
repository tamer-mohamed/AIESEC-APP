<?php

	$form['dawn_settings']['typography'] = array(
			'#type' => 'fieldset',
			'#title' => t('Typography'),
			'#description' => t('Configure the typography settings. For instructions on adding Google Web Fonts, please refer to the "Theme Settings" portion of the theme documentation.'),
	);
	
	$headings = array(1,2,3,4,5,6);
	$links = array('normal', 'hover', 'visited', 'active');
	
	$form['dawn_settings']['typography']['headings'] = array(
			'#type' => 'fieldset',
			'#title' => t('Headings'),
			'#description' => t('Configure the style settings for the heading elements. '),
			'#attributes' => array('class' => array('edit-font'), 'title' => t('')),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
	);
	foreach($headings as $item) {
	$form['dawn_settings']['typography']['headings']['heading-'.$item] = array(
			'#type' => 'fieldset',
			'#title' => t('Heading '.$item),
			'#attributes' => array('class' => array('edit-font'), 'title' => t('')),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['dawn_settings']['typography']['headings']['heading-'.$item]['h'.$item.'-font-type'] = array(
			'#type' => 'select',
			'#title' => t('Font Type:'),
			'#field_prefix' => t('<br/>'),
			'#default_value' => theme_get_setting('h'.$item.'-font-type'),
			'#description' => t('Select the font type.'),
			'#options' => array(
					'default-font' => t('Default Font'),
					'google-font' => t('Google Webfont'),
			),
	);
	
	$form['dawn_settings']['typography']['headings']['heading-'.$item]['h'.$item.'-default-font'] = array(
			'#type' => 'select',
			'#title' => t('Font Family:'),
			'#field_prefix' => t('<br/>'),
			'#default_value' => theme_get_setting('default-font'),
			'#options' => array(
					'"Helvetica Neue", Helvetica, Arial, sans-serif' => t('"Helvetica Neue", Helvetica, Arial, sans-serif'),
					'Calibri, Candara, "Helvetica Neue", "Trebuchet MS", Arial, Helvetica, sans-serif;' => t('Calibri, Candara, "Helvetica Neue", "Trebuchet MS", Arial, Helvetica, sans-serif;'),
					'Georgia, Baskerville, Palatino, "Palatino Linotype", "Book Antiqua", "Times New Roman", serif;' => t('Georgia, Baskerville, Palatino, "Palatino Linotype", "Book Antiqua", "Times New Roman", serif;'),
					'"Segoe UI", "Myriad Pro", Myriad, Arial, Helvetica, sans-serif' => t('"Segoe UI", "Myriad Pro", Myriad, Arial, Helvetica, sans-serif'),
					'"Lucida Sans Unicode", "Lucida Sans", "Lucida Grande", Verdana, Geneva, sans-serif;' => t('"Lucida Sans Unicode", "Lucida Sans", "Lucida Grande", Verdana, Geneva, sans-serif;'),
			),
			'#states' => array(
					'visible' => array(      // Action to take: check the checkbox.
							':input[name="h'.$item.'-font-type"]' => array('value' => 'default-font'),
					),
			),
	);
	
	$form['dawn_settings']['typography']['headings']['heading-'.$item]['h'.$item.'-webfont'] = array(
			'#type' => 'textfield',
			'#title' => t('Font Family:'),
			'#field_prefix' => t('<br/>'),
			'#default_value' => theme_get_setting('h'.$item.'-webfont'),
			'#attributes' => array('class' => array('webfont'), 'title' => t('')),
			'#states' => array(
					'visible' => array(      // Action to take: check the checkbox.
							':input[name="h'.$item.'-font-type"]' => array('value' => 'google-font'),
					),
			),
	);
	
	$form['dawn_settings']['typography']['headings']['heading-'.$item]['h'.$item.'-fontsize'] = array(
			'#type' => 'textfield',
			'#field_suffix' => 'px',
			'#title' => t('Font Size:'),
			'#maxlength' => 7,
			'#default_value' => theme_get_setting('h'.$item.'-fontsize'),
	);
	
	$form['dawn_settings']['typography']['headings']['heading-'.$item]['h'.$item.'-color'] = array(
			'#type' => 'textfield',
			'#field_prefix' => '#',
			'#field_suffix' => '<br/>',
			'#title' => t('Color:'),
			'#maxlength' => 7,
			'#default_value' => theme_get_setting('h'.$item.'-color'),
	);
	
	$form['dawn_settings']['typography']['headings']['heading-'.$item]['h'.$item.'-fontweight'] = array(
			'#type' => 'textfield',
			'#title' => t('Font Weight:'),
			'#maxlength' => 7,
			'#default_value' => theme_get_setting('h'.$item.'-fontweight'),
			'#states' => array(
					'visible' => array(      // Action to take: check the checkbox.
							':input[name="h'.$item.'-fontweight-toggle"]' =>  array('checked' => TRUE),
					),
			),
	);
	
	$form['dawn_settings']['typography']['headings']['heading-'.$item]['h'.$item.'-font-style'] = array(
			'#type' => 'select',
			'#title' => t('Font Style:'),
			'#default_value' => theme_get_setting('h'.$item.'-font-style'),
			'#options' => array(
					'normal' => t('Normal'),
					'italic' => t('Italic'),
					'oblique' => t('Oblique'),
			),
			'#states' => array(
					'visible' => array(      // Action to take: check the checkbox.
							':input[name="h'.$item.'-font-style-toggle"]' =>  array('checked' => TRUE),
					),
			),
	);
	
	}
	
	$form['dawn_settings']['typography']['links'] = array(
			'#type' => 'fieldset',
			'#title' => t('Hyperlinks'),
			'#description' => t('Configure the style settings for default, hover, active, and visited hyperlink states.'),
			'#attributes' => array('class' => array('edit-hyperlinks'), 'title' => t('')),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
	);
	
	/* Links */
	
	foreach($links as $item) {
		
		$form['dawn_settings']['typography']['links']['link-'.$item] = array(
				'#type' => 'fieldset',
				'#title' => $item,
				'#attributes' => array('class' => array('link-options'), 'title' => t('')),
				'#collapsible' => TRUE,
				'#collapsed' => TRUE,
				
		);
			
		$form['dawn_settings']['typography']['links']['link-'.$item]['link-'.$item.'-color'] = array(
				'#type' => 'textfield',
				'#field_prefix' => '#',
				'#field_suffix' => '<br/>',
				'#attributes' => array('class' => array('link-color'), 'title' => t('')),
				'#title' => t('Color:'),
				'#maxlength' => 7,
				'#default_value' => theme_get_setting('link-'.$item.'-color'),
		);
		
		$form['dawn_settings']['typography']['links']['link-'.$item]['link-'.$item.'-decoration'] = array(
				'#type' => 'select',
				'#title' => t('Text Decoration:'),
				'#default_value' => theme_get_setting('link-'.$item.'-decoration'),
				'#attributes' => array('class' => array('link-decoration'), 'title' => t('')),
				'#options' => array(
						'none' => t('None'),
						'underline' => t('Underline'),
						'overline' => t('Overline'),
				),
		);
		
		$form['dawn_settings']['typography']['links']['link-'.$item]['link-'.$item.'-fontweight'] = array(
				'#type' => 'textfield',
				'#attributes' => array('class' => array('link-weight'), 'title' => t('')),
				'#title' => t('Font Weight:'),
				'#maxlength' => 7,
				'#default_value' => theme_get_setting('link-'.$item.'-fontweight'),
		);
		
		
		$form['dawn_settings']['typography']['links']['link-'.$item]['link-'.$item.'-font-style'] = array(
				'#type' => 'select',
				'#attributes' => array('class' => array('link-style'), 'title' => t('')),
				'#title' => t('Font Style:'),
				'#default_value' => theme_get_setting('link-'.$item.'-font-style'),
				'#options' => array(
						'normal' => t('Normal'),
						'italic' => t('Italic'),
						'oblique' => t('Oblique'),
				),
		);
	
	}
	
	$form['dawn_settings']['typography']['base'] = array(
			'#type' => 'fieldset',
			'#title' => t('Base Font'),
			'#description' => t('Configure the style settings for the body font.'),
			'#attributes' => array('class' => array('edit-base-font'), 'title' => t('')),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
	);
	
	$form['dawn_settings']['typography']['base']['base-font-type'] = array(
			'#type' => 'select',
			'#title' => t('Font Type:'),
			'#default_value' => theme_get_setting('base-font-type'),
// 			'#description' => t('Select the font type. For instructions on adding Google Webfonts, please refer to the documentation.'),
			'#options' => array(
					'default-font' => t('Default Font'),
					'google-font' => t('Google Webfont'),
			),
	);
	
	$form['dawn_settings']['typography']['base']['base-default-font'] = array(
			'#type' => 'select',
			'#title' => t('Font Family:'),
			'#default_value' => theme_get_setting('base-default-font'),
			'#options' => array(
					'"Helvetica Neue", Helvetica, Arial, sans-serif' => t('"Helvetica Neue", Helvetica, Arial, sans-serif'),
					'Calibri, Candara, "Helvetica Neue", "Trebuchet MS", Arial, Helvetica, sans-serif;' => t('Calibri, Candara, "Helvetica Neue", "Trebuchet MS", Arial, Helvetica, sans-serif;'),
					'Georgia, Baskerville, Palatino, "Palatino Linotype", "Book Antiqua", "Times New Roman", serif;' => t('Georgia, Baskerville, Palatino, "Palatino Linotype", "Book Antiqua", "Times New Roman", serif;'),
					'"Segoe UI", "Myriad Pro", Myriad, Arial, Helvetica, sans-serif' => t('"Segoe UI", "Myriad Pro", Myriad, Arial, Helvetica, sans-serif'),
					'"Lucida Sans Unicode", "Lucida Sans", "Lucida Grande", Verdana, Geneva, sans-serif;' => t('"Lucida Sans Unicode", "Lucida Sans", "Lucida Grande", Verdana, Geneva, sans-serif;'),
			),
			'#states' => array(
					'visible' => array(      // Action to take: check the checkbox.
							':input[name="base-font-type"]' => array('value' => 'default-font'),
					),
			),
	);
	
	$form['dawn_settings']['typography']['base']['base-webfont'] = array(
			'#type' => 'textfield',
			'#title' => t('Font Family:'),
			'#default_value' => theme_get_setting('base-webfont'),
			'#states' => array(
					'visible' => array(      // Action to take: check the checkbox.
							':input[name="base-font-type"]' => array('value' => 'google-font'),
					),
			),
	);
	
	$form['dawn_settings']['typography']['base']['base-fontsize'] = array(
			'#type' => 'textfield',
			'#field_suffix' => 'px',
			'#title' => t('Font Size:'),
			'#maxlength' => 7,
			'#default_value' => theme_get_setting('base-fontsize'),
	);
	
	$form['dawn_settings']['typography']['base']['base-color'] = array(
			'#type' => 'textfield',
			'#field_prefix' => '#',
			'#field_suffix' => '<br/>',
			'#title' => t('Color:'),
			'#maxlength' => 7,
			'#default_value' => theme_get_setting('base-color'),
	);
	
	$form['dawn_settings']['typography']['base']['base-fontweight'] = array(
			'#type' => 'textfield',
			'#title' => t('Font Weight:'),
			'#maxlength' => 7,
			'#default_value' => theme_get_setting('base-fontweight'),
	);
	
	$form['dawn_settings']['typography']['base']['base-font-style'] = array(
			'#type' => 'select',
			'#title' => t('Font Style:'),
			'#default_value' => theme_get_setting('base-font-style'),
			'#options' => array(
					'normal' => t('Normal'),
					'italic' => t('Italic'),
					'oblique' => t('Oblique'),
			),
	);
	
?>