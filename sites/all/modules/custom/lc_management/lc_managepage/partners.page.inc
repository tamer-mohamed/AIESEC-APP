<?php

/**
 * Form add Lc
 * 
 * @param type $form
 * @param type $form_submit
 * @return string
 */
function _partners_admin_add($form, &$form_submit) {
    $form['title'] = array(
        '#title' => t('partners Title'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('title of the partners.'),
    );
    $form['url'] = array(
        '#title' => t('partners url'),
        '#type' => 'textfield',
        '#required' => FALSE,
        '#description' => t('url of the partners.'),
    );
    $form['img'] = array(
        '#title' => t('Image'),
        '#type' => 'managed_file',
        '#description' => t('Image of partners.'),
        '#upload_location' => 'public://lc_partners_images/',
        '#theme' => 'image_multifield_multitype'
    );
    $form['description'] = array(
        '#title' => t('Description'),
        '#type' => 'text_format',
        '#description' => t('Description of partners.'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

/**
 * Form add partners submit
 * 
 * @param type $form
 * @param type $form_state
 */
function _partners_admin_add_submit($form, &$form_state) {

    global $user;
    $user = user_load($user->uid);
    $lc = $user->lc_field['und'][0]['value'];

    $validators = array(
        'file_validate_extensions' => array('jpg png gif'),
    );
    $url = $form_state['values']['url'];
    $img = $form_state['values']['img'];
    $title = $form_state['values']['title'];
    $desc = $form_state['values']['description']['value'];
    db_insert('partner')
            ->fields(array(
                'title' => $title,
                'img' => $img,
                'description' => $desc,
                'created' => REQUEST_TIME,
                'url' => $url,
                'lc_id' => $lc
            ))
            ->execute();
    drupal_set_message('The partners has been added succesfully');
    drupal_goto("user/$user->uid/page/manage-partner");
}

function _partners_admin_edit($form, &$form_submit, $id) {
    $partners = _partners_get_data($id);
    $form['title'] = array(
        '#title' => t('partners Title'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#default_value' => $partners['title'] != '' ? $partners['title'] : '',
        '#description' => t('title of the partners.'),
    );
    $form['url'] = array(
        '#title' => t('partners url'),
        '#type' => 'textfield',
        '#required' => FALSE,
        '#description' => t('url of the partners.'),
        '#default_value' => $partners['url'] != '' ? $partners['url'] : ''
    );
    $form['id'] = array(
        '#title' => t('id'),
        '#type' => 'hidden',
        '#default_value' => $id,
        '#description' => t('id of partners.'),
    );
    $form['img'] = array(
        '#title' => t('Image'),
        '#type' => 'managed_file',
        '#description' => t('Image of partners.'),
        '#default_value' => isset($partners['img']) ? $partners['img'] : '',
        '#upload_location' => 'public://lc_partners_images/',
        '#theme' => 'image_multifield_multitype'
    );

    $form['description'] = array(
        '#title' => t('Description'),
        '#type' => 'text_format',
        '#default_value' => $partners['description'] != '' ? $partners['description'] : '',
        '#description' => t('Description of partners.'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

function _partners_admin_edit_submit($form, &$form_state) {
    global $user;
    $validators = array(
        'file_validate_extensions' => array('jpg png gif'),
    );
    $url = $form_state['values']['url'];
    $title = $form_state['values']['title'];
    $desc = $form_state['values']['description']['value'];
    $img = $form_state['values']['img'];
    db_update('partner')
            ->fields(array(
                'title' => $title,
                'img' => $img,
                'url' => $url,
                'description' => $desc,
                'created' => REQUEST_TIME,
            ))
            ->condition('id', $form_state['values']['id'])
            ->execute();


    drupal_set_message('The partners has been edited succesfully');
    drupal_goto("user/$user->uid/page/manage-partner");
}

/**
 * confirm delete partners form
 * 
 * @param type $form
 * @param type $form_state
 * @param type $id
 * @return type
 */
function _partners_admin_delete_confirm($form, &$form_state, $id) {
    $form['id'] = array('#type' => 'value', '#value' => $id);
    return confirm_form($form, t('Are you sure you want to delete this record?'), 'admin/config/partnerss/manage/', t('This action cannot be undone.'), t('Delete'), t('Cancel')
    );
}

/**
 * Confirm delete partners form submit
 * @param type $form
 * @param type $form_state
 */
function _partners_admin_delete_confirm_submit($form, &$form_state) {
    global $user;
    if ($form_state['values']['confirm']) {
        _partners_admin_delete($form_state['values']['id']);
        drupal_set_message('partners has been deleted succesfully');
        $form_values = $form_state['values'];
    }

    drupal_goto("user/$user->uid/page/manage-partner");
}

/**
 * Delete partners query 
 * 
 * @param type $id
 */
function _partners_admin_delete($id) {
    db_delete('partner')
            ->condition('id', $id)
            ->execute();
}

/**
 * Get Lcs or single partners by id query
 * 
 * @return type
 */
function _partners_get_data($id = '') {
    global $user;
    $user = user_load($user->uid);
    $lc = $user->lc_field['und'][0]['value'];
    if ($id != '') {
        $result = db_select('partner', 'p')
                ->fields('p', array('id', 'title', 'created', 'img', 'description','url'))
                ->condition('id', $id)
                ->execute();
        return $result->fetchAssoc();
    }
     $result = db_select('partner', 'p')
                ->fields('p', array('id', 'title', 'created', 'img', 'description','url'))
                ->condition('lc_id', $lc)
                ->execute();
    $rows = array();
    $i = 0;
    while ($record = $result->fetchAssoc()) {
        $rows[$i]['title'] = $record['title'];
        $rows[$i]['url'] = $record['url'];
        $rows[$i]['img'] = "<img width='50' src='" . file_create_url(file_load($record['img'])->uri) . "' />";
        $rows[$i]['description'] = mb_substr($record['description'], 0, 50) . "....";
        $rows[$i]['created'] = date('Y-M-D h:m', $record['created']);
        $rows[$i]['edit'] = l('Edit', 'manage-partner/edit/' . $record['id']);
        $rows[$i]['delete'] = l('Delete', 'manage-partner/delete/' . $record['id'], array('attributes' => array('class' => 'btn-danger btn')));

        $i++;
    }
    $header = array(t('title'),t('url'), t('img'), t('description'), t('Created'), t('Edit'), t('Delete'));
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output;
}

?>
