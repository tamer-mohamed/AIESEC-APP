<?php

/**
 * Form add Lc
 * 
 * @param type $form
 * @param type $form_submit
 * @return string
 */
function _teams_admin_add($form, &$form_submit) {
    $form['title'] = array(
        '#title' => t('teams Title'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('title of the teams.'),
    );
    $form['img'] = array(
        '#title' => t('Image'),
        '#type' => 'managed_file',
        '#description' => t('Image of teams.'),
        '#upload_location' => 'public://lc_teams_images/',
        '#theme' => 'image_multifield_multitype'
    );
    $form['description'] = array(
        '#title' => t('Description'),
        '#type' => 'text_format',
        '#description' => t('Description of teams.'),
    );
    
    $form['facebook'] = array(
        '#title' => t('teams facebook'),
        '#type' => 'textfield',
        '#required' => FALSE,
        '#description' => t('facebook of the teams.'),
    );
    $form['twitter'] = array(
        '#title' => t('teams twitter'),
        '#type' => 'textfield',
        '#required' => FALSE,
        '#description' => t('twitter of the teams.'),
    );
    $form['linkedin'] = array(
        '#title' => t('teams linkedin'),
        '#type' => 'textfield',
        '#required' => FALSE,
        '#description' => t('linkedin of the teams.'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

/**
 * Form add teams submit
 * 
 * @param type $form
 * @param type $form_state
 */
function _teams_admin_add_submit($form, &$form_state) {

    global $user;
    $user = user_load($user->uid);
    $lc = $user->lc_field['und'][0]['value'];

    $validators = array(
        'file_validate_extensions' => array('jpg png gif'),
    );
    $img = $form_state['values']['img'];
    $title = $form_state['values']['title'];
    $desc = $form_state['values']['description']['value'];
    $facebook = $form_state['values']['facebook'];
    $twitter = $form_state['values']['twitter'];
    $linkedin = $form_state['values']['linkedin'];
    db_insert('team')
            ->fields(array(
                'title' => $title,
                'img' => $img,
                'description' => $desc,
                'created' => REQUEST_TIME,
                'lc_id' => $lc,
                'facebook' => $facebook,
                'twitter' => $twitter,
                'linkedin' => $linkedin
            ))
            ->execute();
    drupal_set_message('The teams has been added succesfully');
    drupal_goto("user/$user->uid/page/manage-team");
}

function _teams_admin_edit($form, &$form_submit, $id) {
    $teams = _teams_get_data($id);
    $form['title'] = array(
        '#title' => t('teams Title'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#default_value' => $teams['title'] != '' ? $teams['title'] : '',
        '#description' => t('title of the teams.'),
    );
    $form['id'] = array(
        '#title' => t('id'),
        '#type' => 'hidden',
        '#default_value' => $id,
        '#description' => t('id of teams.'),
    );
    $form['img'] = array(
        '#title' => t('Image'),
        '#type' => 'managed_file',
        '#description' => t('Image of teams.'),
        '#default_value' => isset($teams['img']) ? $teams['img'] : '',
        '#upload_location' => 'public://lc_teams_images/',
        '#theme' => 'image_multifield_multitype'
    );

    $form['description'] = array(
        '#title' => t('Description'),
        '#type' => 'text_format',
        '#default_value' => $teams['description'] != '' ? $teams['description'] : '',
        '#description' => t('Description of teams.'),
    );
    $form['facebook'] = array(
        '#title' => t('teams facebook'),
        '#type' => 'textfield',
        '#required' => FALSE,
        '#description' => t('facebook of the teams.'),
        '#default_value' => $teams['facebook'] != '' ? $teams['facebook'] : '',
    );
    $form['twitter'] = array(
        '#title' => t('teams twitter'),
        '#type' => 'textfield',
        '#required' => FALSE,
        '#description' => t('twitter of the teams.'),
        '#default_value' => $teams['twitter'] != '' ? $teams['twitter'] : '',
    );
    $form['linkedin'] = array(
        '#title' => t('teams linkedin'),
        '#type' => 'textfield',
        '#required' => FALSE,
        '#description' => t('linkedin of the teams.'),
        '#default_value' => $teams['linkedin'] != '' ? $teams['linkedin'] : '',
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

function _teams_admin_edit_submit($form, &$form_state) {
    global $user;
    $validators = array(
        'file_validate_extensions' => array('jpg png gif'),
    );

    $title = $form_state['values']['title'];
    $desc = $form_state['values']['description']['value'];
    $img = $form_state['values']['img'];
    $facebook = $form_state['values']['facebook'];
    $twitter = $form_state['values']['twitter'];
    $linkedin = $form_state['values']['linkedin'];
    db_update('team')
            ->fields(array(
                'title' => $title,
                'img' => $img,
                'description' => $desc,
                'created' => REQUEST_TIME,
                'facebook' => $facebook,
                'twitter' => $twitter,
                'linkedin' => $linkedin
            ))
            ->condition('id', $form_state['values']['id'])
            ->execute();


    drupal_set_message('The teams has been edited succesfully');
    drupal_goto("user/$user->uid/page/manage-team");
}

/**
 * confirm delete teams form
 * 
 * @param type $form
 * @param type $form_state
 * @param type $id
 * @return type
 */
function _teams_admin_delete_confirm($form, &$form_state, $id) {
    $form['id'] = array('#type' => 'value', '#value' => $id);
    return confirm_form($form, t('Are you sure you want to delete this record?'), 'admin/config/teamss/manage/', t('This action cannot be undone.'), t('Delete'), t('Cancel')
    );
}

/**
 * Confirm delete teams form submit
 * @param type $form
 * @param type $form_state
 */
function _teams_admin_delete_confirm_submit($form, &$form_state) {
    global $user;
    if ($form_state['values']['confirm']) {
        _teams_admin_delete($form_state['values']['id']);
        drupal_set_message('teams has been deleted succesfully');
        $form_values = $form_state['values'];
    }

    drupal_goto("user/$user->uid/page/manage-team");
}

/**
 * Delete teams query 
 * 
 * @param type $id
 */
function _teams_admin_delete($id) {
    db_delete('team')
            ->condition('id', $id)
            ->execute();
}

/**
 * Get Lcs or single teams by id query
 * 
 * @return type
 */
function _teams_get_data($id = '') {
    global $user;
    $user = user_load($user->uid);
    $lc = $user->lc_field['und'][0]['value'];
    if ($id != '') {
        $result = db_select('team', 't')
                ->fields('t', array('id', 'title', 'created', 'img', 'description','facebook','twitter','linkedin'))
                ->condition('id', $id)
                ->execute();
        return $result->fetchAssoc();
    }

    $result = db_select('team', 't')
            ->fields('t', array('id', 'title', 'created', 'img', 'description','facebook','twitter','linkedin'))
            ->condition('lc_id', $lc)
            ->execute();
    
    $rows = array();
    $i = 0;
    while ($record = $result->fetchAssoc()) {
        $rows[$i]['title'] = $record['title'];
        $rows[$i]['img'] = "<img width='50' src='" . file_create_url(file_load($record['img'])->uri) . "' />";
        $rows[$i]['description'] = mb_substr($record['description'], 0, 50) . "....";
        $rows[$i]['facebook'] = $record['facebook'];
        $rows[$i]['twitter'] = $record['twitter'];
        $rows[$i]['linkedin'] = $record['linkedin'];
        $rows[$i]['created'] = date('Y-M-D h:m', $record['created']);
        $rows[$i]['edit'] = l('Edit', 'manage-team/edit/' . $record['id']);
        $rows[$i]['delete'] = l('Delete', 'manage-team/delete/' . $record['id'], array('attributes' => array('class' => 'btn-danger btn')));

        $i++;
    }
    $header = array(t('title'), t('img'), t('description'),t('facebook'),t('twitter'),t('linkedin'), t('Created'), t('Edit'), t('Delete'));
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output;
}

?>
