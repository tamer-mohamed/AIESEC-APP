<?php

/**
 * Form add Lc
 * 
 * @param type $form
 * @param type $form_submit
 * @return string
 */
function _news_admin_add($form, &$form_submit) {
    $form['title'] = array(
        '#title' => t('News Title'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('title of the news.'),
    );
    $form['img'] = array(
        '#title' => t('Image'),
        '#type' => 'file',
        '#description' => t('Image of news.'),
    );
    $form['description'] = array(
        '#title' => t('Description'),
        '#type' => 'text_format',
        '#description' => t('Description of news.'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

/**
 * Form add news submit
 * 
 * @param type $form
 * @param type $form_state
 */
function _news_admin_add_submit($form, &$form_state) {

    global $user;
    $user = user_load($user->uid);
    $lc = $user->lc_field['und'][0]['value'];

    $validators = array(
        'file_validate_extensions' => array('jpg png gif'),
    );

    if ($file = file_save_upload('img', $validators, 'public://lc_news_images/')) {
        $file_content = file_get_contents($file->uri);
        $img = $file->uri;
        $title = $form_state['values']['title'];
        $desc = $form_state['values']['description']['value'];
        db_insert('news')
                ->fields(array(
                    'title' => $title,
                    'img' => $img,
                    'description' => $desc,
                    'created' => REQUEST_TIME,
                    'lc_id' => $lc
                ))
                ->execute();
        drupal_set_message('The news has been added succesfully');
        drupal_goto("user/$user->uid/page/manage-news");
    } else {
        form_set_error('Image', 'Could not upload file.');
    }
}

function _news_admin_edit($form, &$form_submit, $id) {
    $news = _news_get_data($id);
    $form['title'] = array(
        '#title' => t('News Title'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#default_value' => $news['title'] != '' ? $news['title'] : '',
        '#description' => t('title of the news.'),
    );
    $form['id'] = array(
        '#title' => t('id'),
        '#type' => 'hidden',
        '#default_value' => $id,
        '#description' => t('id of news.'),
    );
    $form['img'] = array(
        '#title' => t('Image'),
        '#type' => 'file',
        '#description' => t('Image of news.'),
    );
    if ($form['img'] != '')
        $form['img']['#suffix'] = '<div class="imagePreviewLc"><img src="' . file_create_url($news['img']) . '" width="50" class="imagePreviewLc"/></div>';

    $form['description'] = array(
        '#title' => t('Description'),
        '#type' => 'text_format',
        '#default_value' => $news['description'] != '' ? $news['description'] : '',
        '#description' => t('Description of news.'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

function _news_admin_edit_submit($form, &$form_state) {
    global $user;
    $validators = array(
        'file_validate_extensions' => array('jpg png gif'),
    );

    $title = $form_state['values']['title'];
    $desc = $form_state['values']['description']['value'];
    if ($file = file_save_upload('img', $validators, 'public://lc_news_images/')) {
        $file_content = file_get_contents($file->uri);
        $img = $file->uri;
        db_update('news')
                ->fields(array(
                    'title' => $title,
                    'img' => $img,
                    'description' => $desc,
                    'created' => REQUEST_TIME,
                ))
                ->condition('id', $form_state['values']['id'])
                ->execute();
    } else {
        db_update('news')
                ->fields(array(
                    'title' => $title,
                    'description' => $desc,
                    'created' => REQUEST_TIME,
                ))
                ->condition('id', $form_state['values']['id'])
                ->execute();
    }

    drupal_set_message('The news has been edited succesfully');
    drupal_goto("user/$user->uid/page/manage-news");
}

/**
 * confirm delete news form
 * 
 * @param type $form
 * @param type $form_state
 * @param type $id
 * @return type
 */
function _news_admin_delete_confirm($form, &$form_state, $id) {
    $form['id'] = array('#type' => 'value', '#value' => $id);
    return confirm_form($form, t('Are you sure you want to delete this record?'), 'admin/config/newss/manage/', t('This action cannot be undone.'), t('Delete'), t('Cancel')
    );
}

/**
 * Confirm delete news form submit
 * @param type $form
 * @param type $form_state
 */
function _news_admin_delete_confirm_submit($form, &$form_state) {
    global $user;
    if ($form_state['values']['confirm']) {
        _news_admin_delete($form_state['values']['id']);
        drupal_set_message('News has been deleted succesfully');
        $form_values = $form_state['values'];
    }

    drupal_goto("user/$user->uid/page/manage-news");
}

/**
 * Delete news query 
 * 
 * @param type $id
 */
function _news_admin_delete($id) {
    db_delete('news')
            ->condition('id', $id)
            ->execute();
}

/**
 * Get Lcs or single news by id query
 * 
 * @return type
 */
function _news_get_data($id = '') {
    global $user;
    $user = user_load($user->uid);
    $lc = $user->lc_field['und'][0]['value'];
    if ($id != '') {
        $result = db_query('SELECT news.id, news.title, news.created, news.img,news.description FROM news where id = :id', array(':id' => $id));
        return $result->fetchAssoc();
    }
    $result = db_query('SELECT news.id, news.title, news.created, news.img,news.description FROM news where lc_id = :lc',array(':lc' => $lc));
    $rows = array();
    $i = 0;
    while ($record = $result->fetchAssoc()) {
        $rows[$i]['title'] = $record['title'];
        $rows[$i]['img'] = "<img width='50' src='" . file_create_url($record['img']) . "' />";
        $rows[$i]['description'] = mb_substr($record['description'], 0, 50) . "....";
        $rows[$i]['created'] = date('Y-M-D h:m', $record['created']);
        $rows[$i]['edit'] = l('Edit', 'manage-news/edit/' . $record['id']);
        $rows[$i]['delete'] = l('Delete', 'manage-news/delete/' . $record['id'], array('attributes' => array('class' => 'btn-danger btn')));

        $i++;
    }
    $header = array(t('title'), t('img'), t('description'), t('Created'), t('Edit'), t('Delete'));
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output;
}

?>
