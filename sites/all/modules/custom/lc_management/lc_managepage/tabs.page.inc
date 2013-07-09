<?php

/**
 * Form add Lc
 * 
 * @param type $form
 * @param type $form_submit
 * @return string
 */
function _tabs_admin_add($form, &$form_submit) {
    $form['title'] = array(
        '#title' => t('tabs Title'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('title of the tabs.'),
    );
    $form['description'] = array(
        '#title' => t('Description'),
        '#type' => 'text_format',
        '#description' => t('Description of tabs.'),
    );
    
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

/**
 * Form add tabs submit
 * 
 * @param type $form
 * @param type $form_state
 */
function _tabs_admin_add_submit($form, &$form_state) {

    global $user;
    $user = user_load($user->uid);
    $lc = $user->lc_field['und'][0]['value'];

    $title = $form_state['values']['title'];
    $desc = $form_state['values']['description']['value'];
    db_insert('tab')
            ->fields(array(
                'title' => $title,
                'description' => $desc,
                'created' => REQUEST_TIME,
                'lc_id' => $lc,
            ))
            ->execute();
    drupal_set_message('The tabs has been added succesfully');
    drupal_goto("user/$user->uid/page/manage-tab");
}

function _tabs_admin_edit($form, &$form_submit, $id) {
    $tabs = _tabs_get_data($id);
    $form['title'] = array(
        '#title' => t('tabs Title'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#default_value' => $tabs['title'] != '' ? $tabs['title'] : '',
        '#description' => t('title of the tabs.'),
    );
    $form['id'] = array(
        '#title' => t('id'),
        '#type' => 'hidden',
        '#default_value' => $id,
        '#description' => t('id of tabs.'),
    );
    $form['description'] = array(
        '#title' => t('Description'),
        '#type' => 'text_format',
        '#default_value' => $tabs['description'] != '' ? $tabs['description'] : '',
        '#description' => t('Description of tabs.'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

function _tabs_admin_edit_submit($form, &$form_state) {
    global $user;

    $title = $form_state['values']['title'];
    $desc = $form_state['values']['description']['value'];
    db_update('tab')
            ->fields(array(
                'title' => $title,
                'description' => $desc,
                'created' => REQUEST_TIME,
            ))
            ->condition('id', $form_state['values']['id'])
            ->execute();


    drupal_set_message('The tabs has been edited succesfully');
    drupal_goto("user/$user->uid/page/manage-tab");
}

/**
 * confirm delete tabs form
 * 
 * @param type $form
 * @param type $form_state
 * @param type $id
 * @return type
 */
function _tabs_admin_delete_confirm($form, &$form_state, $id) {
    $form['id'] = array('#type' => 'value', '#value' => $id);
    return confirm_form($form, t('Are you sure you want to delete this record?'), 'admin/config/tabs/manage/', t('This action cannot be undone.'), t('Delete'), t('Cancel')
    );
}

/**
 * Confirm delete tabs form submit
 * @param type $form
 * @param type $form_state
 */
function _tabs_admin_delete_confirm_submit($form, &$form_state) {
    global $user;
    if ($form_state['values']['confirm']) {
        _tabs_admin_delete($form_state['values']['id']);
        drupal_set_message('tabs has been deleted succesfully');
        $form_values = $form_state['values'];
    }

    drupal_goto("user/$user->uid/page/manage-tab");
}

/**
 * Delete tabs query 
 * 
 * @param type $id
 */
function _tabs_admin_delete($id) {
    db_delete('tab')
            ->condition('id', $id)
            ->execute();
}

/**
 * Get Lcs or single tabs by id query
 * 
 * @return type
 */
function _tabs_get_data($id = '') {
    global $user;
    $user = user_load($user->uid);
    $lc = $user->lc_field['und'][0]['value'];
    if ($id != '') {
        $result = db_select('tab', 't')
                ->fields('t', array('id', 'title', 'created', 'description'))
                ->condition('id', $id)
                ->execute();
        return $result->fetchAssoc();
    }

    $result = db_select('tab', 't')
            ->fields('t', array('id', 'title', 'created', 'description'))
            ->condition('lc_id', $lc)
            ->execute();
    
    $rows = array();
    $i = 0;
    while ($record = $result->fetchAssoc()) {
        $rows[$i]['title'] = $record['title'];
        $rows[$i]['description'] = mb_substr($record['description'], 0, 50) . "....";
        $rows[$i]['created'] = date('Y-M-D h:m', $record['created']);
        $rows[$i]['edit'] = l('Edit', 'manage-tab/edit/' . $record['id']);
        $rows[$i]['delete'] = l('Delete', 'manage-tab/delete/' . $record['id'], array('attributes' => array('class' => 'btn-danger btn')));

        $i++;
    }
    $header = array(t('title'), t('description'), t('Created'), t('Edit'), t('Delete'));
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output;
}

?>
