<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function _lc_managepage_form($form, &$form_submit) {
    global $user;
    $user = user_load($user->uid);

    $data = db_select('lc_page', 'lc')
            ->fields('lc')
            ->condition('lc_id', $user->lc_field['und'][0]['value'])
            ->execute();
    $exist = FALSE;
    if ($data->rowCount() > 0) {
        $data = $data->fetchAssoc();
        $exist = TRUE;
    }
    else
        $data = array();
    $form['bg'] = array(
        '#title' => t('Background Image'),
        '#type' => 'managed_file',
        '#description' => t('The background image of the lc page.'),
        '#upload_location' => 'public://lc_image/',
        '#theme' => 'image_multifield_multitype',
        '#default_value' => isset($data['bg_img']) ? $data['bg_img'] : ''
    );
    $form['exist'] = array(
        '#type' => 'hidden',
        '#value' => $exist,
    );
    $form['logo'] = array(
        '#title' => t('Logo Image'),
        '#type' => 'managed_file',
        '#description' => t('The Logo image of the lc page.'),
        '#upload_location' => 'public://lc_image/',
        '#theme' => 'image_multifield_multitype',
        '#default_value' => isset($data['logo']) ? $data['logo'] : ''
    );
    $form['desc'] = array(
        '#title' => t('About Lc'),
        '#type' => 'text_format',
        '#format' => 'full_html',
        '#description' => t('Information about the lc.'),
        '#default_value' => isset($data['description']) ? $data['description'] : ''
    );
    $form['advertisment'] = array(
        '#title' => t('Lc Ads.'),
        '#type' => 'text_format',
        '#format' => 'full_html',
        '#description' => t('Ads for the lc.'),
        '#default_value' => isset($data['advertisment']) ? $data['advertisment'] : ''
    );
    $form['facebook'] = array(
        '#title' => t('Facebook url'),
        '#type' => 'textfield',
        '#maxlength' => 250, 
        '#description' => t('The url to facebook account. 250 char max.'),
        '#default_value' => isset($data['facebook']) ? $data['facebook'] : ''
    );
    $form['twitter'] = array(
        '#title' => t('Twitter url'),
        '#type' => 'textfield',
        '#maxlength' => 250, 
        '#description' => t('The url to Twitter account. 250 char max.'),
        '#default_value' => isset($data['twitter']) ? $data['twitter'] : ''
    );
    $form['youtube'] = array(
        '#title' => t('Youtube url'),
        '#type' => 'textfield', 
        '#maxlength' => 250, 
        '#description' => t('The url to Youtube account. 250 char max.'),
        '#default_value' => isset($data['youtube']) ? $data['youtube'] : ''
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Save',
    );
    return $form;
}

function _lc_managepage_form_validate($form, &$form_state) {
    $data = array(
        'bg_img' => $form_state['values']['bg'],
        'logo' => $form_state['values']['logo'],
        'description' => $form_state['values']['desc']['value'],
    );
}

function _lc_managepage_form_submit($form, &$form_state) {
    global $user;
    $user = user_load($user->uid);
    $data = array(
        'lc_id' => $user->lc_field['und'][0]['value'],
        'created' => time(),
        'bg_img' => $form_state['values']['bg'],
        'logo' => $form_state['values']['logo'],
        'description' => $form_state['values']['desc']['value'],
        'facebook' => $form_state['values']['facebook'],
        'twitter' => $form_state['values']['twitter'],
        'youtube' => $form_state['values']['youtube'],
        'advertisment' => $form_state['values']['advertisment']['value']
    );
    
    if ($form_state['values']['bg'] > 0) {
        $file = file_load($form_state['values']['bg']);
        $file->status = FILE_STATUS_PERMANENT;
        file_save($file);
        file_usage_add($file, 'lc_managepage', 'background', $file->fid);
    }

    if ($form_state['values']['logo'] > 0) {
        $file = file_load($form_state['values']['logo']);
        $file->status = FILE_STATUS_PERMANENT;
        file_save($file);
        file_usage_add($file, 'lc_managepage', 'logo', $file->fid);
    }

    if ($form_state['values']['exist']) {
        unset($data['created']);
        db_update('lc_page')
                ->fields($data)
                ->condition('lc_id', $data['lc_id'])
                ->execute();
    } else {
        $lc_id_from_q = db_insert('lc_page')
                ->fields($data)
                ->execute();
        
        $data = db_select('lc', 'lc')
            ->fields('name')
            ->condition('id', $user->lc_field['und'][0]['value'])
            ->execute();
        $data = $data->fetchAssoc();
        
        $default_node_path = "lc/".$lc_id_from_q;
        $alternate_url = "lc/".$data['name'];
        path_set_alias($default_node_path, $alternate_url, 0, '');
    }
    drupal_set_message('Settings has been saved succesfully');
}

/*
 * Page call function for lcs analytic
 */

function _lc_stats_call() {
    drupal_add_js('https://www.google.com/jsapi', 'external');
    drupal_add_js(drupal_get_path('module', 'lc_managepage') . '/js/chart.js', 'file');
    return '<div id="chart_div"></div>';
}

?>
