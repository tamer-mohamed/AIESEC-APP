<?php

function _university_management_admin() {
    return _university_management_get_universitys();
}

/**
 * Form add university
 * 
 * @param type $form
 * @param type $form_submit
 * @return string
 */
function _university_management_admin_add($form, &$form_submit) {
    $form['name'] = array(
        '#title' => t('university Name'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('Name of the university.'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

/**
 * Form add university submit
 * 
 * @param type $form
 * @param type $form_state
 */
function _university_management_admin_add_submit($form, &$form_state) {
    $name = $form_state['values']['name'];
    db_insert('university')
            ->fields(array(
                'name' => $name,
                'created' => REQUEST_TIME,
            ))
            ->execute();
    drupal_set_message('The university has been added succesfully');
    drupal_goto("admin/config/universitys/manage");
}

function _university_management_admin_edit($form, &$form_submit,$id){
    $university = _university_management_get_universitys($id);
    $form['name'] = array(
        '#title' => t('university Name'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('Name of the university.'),
        '#default_value' => $university['name'],
    );
    $form['id'] = array(
        '#type' => 'hidden',
        '#value' => $id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

function _university_management_admin_edit_submit($form, &$form_state) {
    $name = $form_state['values']['name'];
    db_update('university')
            ->fields(array(
                'name' => $name,
                'created' => REQUEST_TIME,
            ))
            ->condition('id', $form_state['values']['id'])
            ->execute();
    drupal_set_message('The university has been edited succesfully');
    drupal_goto("admin/config/universitys/manage");
}
/**
 * confirm delete university form
 * 
 * @param type $form
 * @param type $form_state
 * @param type $id
 * @return type
 */
function _university_management_admin_delete_confirm($form, &$form_state, $id) {
    $form['id'] = array('#type' => 'value', '#value' => $id);
    return confirm_form($form, t('Are you sure you want to delete this record?'), 'admin/config/universitys/manage/', t('This action cannot be undone.'), t('Delete'), t('Cancel')
    );
}

/**
 * Confirm delete university form submit
 * @param type $form
 * @param type $form_state
 */
function _university_management_admin_delete_confirm_submit($form, &$form_state) {
    if ($form_state['values']['confirm']) {
        _university_management_admin_delete($form_state['values']['id']);
        drupal_set_message('university has been deleted succesfully');
        $form_values = $form_state['values'];
    }

    drupal_goto("admin/config/universitys/manage");
}

/**
 * Delete university query 
 * 
 * @param type $id
 */
function _university_management_admin_delete($id) {
    db_delete('university')
            ->condition('id', $id)
            ->execute();
}


/**
 * Get universitys or single university by id query
 * 
 * @return type
 */
function _university_management_get_universitys($id = '') {
    if($id != '')
    {
        $result = db_query('SELECT university.id, university.name, university.created FROM university where id = :id',array(':id' => $id));
        return $result->fetchAssoc();
    }
    $result = db_query('SELECT university.id, university.name, university.created FROM university');
    $rows = array();
    $i = 0;
    while ($record = $result->fetchAssoc()) {
        $rows[$i]['name'] = $record['name'];
        $rows[$i]['created'] = date('Y-M-D h:m', $record['created']);
        $rows[$i]['edit'] = l('Edit', 'admin/config/universitys/edit/' . $record['id']);
        $rows[$i]['delete'] = l('Delete', 'admin/config/universitys/delete/' . $record['id']);

        $i++;
    }
    $header = array(t('Name'), t('Created'), t('Edit'), t('Delete'));
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output;
}

?>
