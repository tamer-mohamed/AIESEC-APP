<?php

function _lc_management_admin() {
    return _lc_management_get_lcs();
}

/**
 * Form add Lc
 * 
 * @param type $form
 * @param type $form_submit
 * @return string
 */
function _lc_management_admin_add($form, &$form_submit) {
    $form['name'] = array(
        '#title' => t('Lc Name'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('Name of the lc.'),
    );
    $form['activated'] = array(
        '#title' => t('Activation'),
        '#type' => 'select',
        '#options' => array('0' => 'Deacivated', '1' => 'Activated'),
        '#description' => t('Select status of lc.'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

/**
 * Form add lc submit
 * 
 * @param type $form
 * @param type $form_state
 */
function _lc_management_admin_add_submit($form, &$form_state) {
    $name = $form_state['values']['name'];
    $activated = $form_state['values']['activated'];
    db_insert('lc')
            ->fields(array(
                'name' => $name,
                'activated' => $activated,
                'created' => REQUEST_TIME,
            ))
            ->execute();
    drupal_set_message('The lc has been added succesfully');
    drupal_goto("admin/config/lcs/manage");
}

function _lc_management_admin_edit($form, &$form_submit,$id){
    $lc = _lc_management_get_lcs($id);
    $form['name'] = array(
        '#title' => t('Lc Name'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('Name of the lc.'),
        '#default_value' => $lc['name'],
    );
    $form['activated'] = array(
        '#title' => t('Activation'),
        '#type' => 'select',
        '#options' => array('0' => 'Deacivated', '1' => 'Activated'),
        '#description' => t('Select status of lc.'),
        '#default_value' => $lc['activated'],
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

function _lc_management_admin_edit_submit($form, &$form_state) {
    $name = $form_state['values']['name'];
    $activated = $form_state['values']['activated'];
    db_update('lc')
            ->fields(array(
                'name' => $name,
                'activated' => $activated,
                'created' => REQUEST_TIME,
            ))
            ->condition('id', $form_state['values']['id'])
            ->execute();
    drupal_set_message('The lc has been edited succesfully');
    drupal_goto("admin/config/lcs/manage");
}
/**
 * confirm delete lc form
 * 
 * @param type $form
 * @param type $form_state
 * @param type $id
 * @return type
 */
function _lc_management_admin_delete_confirm($form, &$form_state, $id) {
    $form['id'] = array('#type' => 'value', '#value' => $id);
    return confirm_form($form, t('Are you sure you want to delete this record?'), 'admin/config/lcs/manage/', t('This action cannot be undone.'), t('Delete'), t('Cancel')
    );
}

/**
 * Confirm delete lc form submit
 * @param type $form
 * @param type $form_state
 */
function _lc_management_admin_delete_confirm_submit($form, &$form_state) {
    if ($form_state['values']['confirm']) {
        _lc_management_admin_delete($form_state['values']['id']);
        drupal_set_message('Lc has been deleted succesfully');
        $form_values = $form_state['values'];
    }

    drupal_goto("admin/config/lcs/manage");
}

/**
 * Delete lc query 
 * 
 * @param type $id
 */
function _lc_management_admin_delete($id) {
    db_delete('lc')
            ->condition('id', $id)
            ->execute();
}


/**
 * Get Lcs or single lc by id query
 * 
 * @return type
 */
function _lc_management_get_lcs($id = '') {
    if($id != '')
    {
        $result = db_query('SELECT lc.id, lc.name, lc.created, lc.activated FROM lc where id = :id',array(':id' => $id));
        return $result->fetchAssoc();
    }
    $result = db_query('SELECT lc.id, lc.name, lc.created, lc.activated FROM lc');
    $rows = array();
    $i = 0;
    while ($record = $result->fetchAssoc()) {
        $rows[$i]['name'] = $record['name'];
        $rows[$i]['created'] = date('Y-M-D h:m', $record['created']);
        $rows[$i]['activated'] = $record['activated'] == 0 ? 'Deacivated' : 'Activated';
        $rows[$i]['edit'] = l('Edit', 'admin/config/lcs/edit/' . $record['id']);
        $rows[$i]['delete'] = l('Delete', 'admin/config/lcs/delete/' . $record['id']);

        $i++;
    }
    $header = array(t('Name'), t('Created'), t('Active'), t('Edit'), t('Delete'));
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output;
}

?>
