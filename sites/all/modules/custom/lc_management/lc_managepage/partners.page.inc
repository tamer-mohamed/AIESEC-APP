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
        '#title' => t('News Title'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('title of the partners.'),
    );
    $form['img'] = array(
        '#title' => t('Image'),
        '#type' => 'file',
        '#description' => t('Image of partners.'),
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
    $validators = array(
        'file_validate_extensions' => array('jpg png gif'),
    );

    if ($file = file_save_upload('img', $validators, 'public://lc_partners_images/')) {
        $file_content = file_get_contents($file->uri);
        $img = $file->uri;
        $title = $form_state['values']['title'];
        $desc = $form_state['values']['description']['value'];
        db_insert('partners')
                ->fields(array(
                    'title' => $title,
                    'img' => $img,
                    'description' => $desc,
                    'created' => REQUEST_TIME,
                ))
                ->execute();
        drupal_set_message('The partners has been added succesfully');
        drupal_goto("user/$user->uid/page/manage-partners");
    } else {
        form_set_error('Image', 'Could not upload file.');
    }
}

function _partners_admin_edit($form, &$form_submit, $id) {
    $partners = _partners_get_data($id);
    $form['title'] = array(
        '#title' => t('News Title'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#default_value' => $partners['title'] != '' ? $partners['title'] : '',
        '#description' => t('title of the partners.'),
    );
    $form['id'] = array(
        '#title' => t('id'),
        '#type' => 'hidden',
        '#default_value' => $id,
        '#description' => t('id of partners.'),
    );
    $form['img'] = array(
        '#title' => t('Image'),
        '#type' => 'file',
        '#description' => t('Image of partners.'),
    );
    if ($form['img'] != '')
        $form['img']['#suffix'] = '<div class="imagePreviewLc"><img src="' . file_create_url($partners['img']) . '" width="50" class="imagePreviewLc"/></div>';

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

    $title = $form_state['values']['title'];
    $desc = $form_state['values']['description']['value'];
    if ($file = file_save_upload('img', $validators, 'public://lc_partners_images/')) {
        $file_content = file_get_contents($file->uri);
        $img = $file->uri;
        db_update('partners')
                ->fields(array(
                    'title' => $title,
                    'img' => $img,
                    'description' => $desc,
                    'created' => REQUEST_TIME,
                ))
                ->condition('id', $form_state['values']['id'])
                ->execute();
    } else {
        db_update('partners')
                ->fields(array(
                    'title' => $title,
                    'description' => $desc,
                    'created' => REQUEST_TIME,
                ))
                ->condition('id', $form_state['values']['id'])
                ->execute();
    }

    drupal_set_message('The partners has been edited succesfully');
    drupal_goto("user/$user->uid/page/manage-partners");
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
        drupal_set_message('News has been deleted succesfully');
        $form_values = $form_state['values'];
    }

    drupal_goto("user/$user->uid/page/manage-partners");
}

/**
 * Delete partners query 
 * 
 * @param type $id
 */
function _partners_admin_delete($id) {
    db_delete('partners')
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
    if ($id != '') {
        $result = db_query('SELECT partners.id, partners.title, partners.created, partners.img,partners.description FROM partner where id = :id', array(':id' => $id));    
        return $result->fetchAssoc();
    }
    $result = db_query('SELECT partners.id, partners.title, partners.created, partners.img,partners.description FROM partner');
    $rows = array();
    $i = 0;
    while ($record = $result->fetchAssoc()) {
        $rows[$i]['title'] = $record['title'];
        $rows[$i]['img'] = "<img width='50' src='" . file_create_url($record['img']) . "' />";
        $rows[$i]['description'] = mb_substr($record['description'], 0, 50) . "....";
        $rows[$i]['created'] = date('Y-M-D h:m', $record['created']);
        $rows[$i]['edit'] = l('Edit', 'manage-partners/edit/' . $record['id']);
        $rows[$i]['delete'] = l('Delete', 'manage-partners/delete/' . $record['id']);

        $i++;
    }
    $header = array(t('title'), t('img'), t('description'), t('Created'), t('Edit'), t('Delete'));
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output;
}

?>
