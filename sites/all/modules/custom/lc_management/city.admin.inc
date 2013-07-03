<?php

function _city_management_admin() {
    return _city_management_get_citys();
}

/**
 * Form add city
 * 
 * @param type $form
 * @param type $form_submit
 * @return string
 */
function _city_management_admin_add($form, &$form_submit) {
    $form['name'] = array(
        '#title' => t('city Name'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('Name of the city.'),
    );
    $form['long'] = array(
        '#title' => t('city longitude'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('long of the city.'),
    );
    $form['lat'] = array(
        '#title' => t('city latidude'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('lat of the city.'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

/**
 * Form add city submit
 * 
 * @param type $form
 * @param type $form_state
 */
function _city_management_admin_add_submit($form, &$form_state) {
    $name = $form_state['values']['name'];
    $long = $form_state['values']['long'];
    $lat = $form_state['values']['lat'];
    db_insert('city')
            ->fields(array(
                'name' => $name,
                'long' => $long,
                'lat' => $lat,
                'created' => REQUEST_TIME,
            ))
            ->execute();
    drupal_set_message('The city has been added succesfully');
    drupal_goto("admin/config/citys/manage");
}

function _city_management_admin_edit($form, &$form_submit, $id) {
    $city = _city_management_get_citys($id);
    $form['name'] = array(
        '#title' => t('city Name'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('Name of the city.'),
        '#default_value' => $city['name'],
    );
    $form['long'] = array(
        '#title' => t('city longitude'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('long of the city.'),
        '#default_value' => $city['long'],
    );
    $form['lat'] = array(
        '#title' => t('city latidude'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('lat of the city.'),
        '#default_value' => $city['lat'],
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

function _city_management_admin_edit_submit($form, &$form_state) {
    $name = $form_state['values']['name'];
    $long = $form_state['values']['long'];
    $lat = $form_state['values']['lat'];
    db_update('city')
            ->fields(array(
                'name' => $name,
                'long' => $long,
                'lat' => $lat,
                'created' => REQUEST_TIME,
            ))
            ->condition('id', $form_state['values']['id'])
            ->execute();
    drupal_set_message('The city has been edited succesfully');
    drupal_goto("admin/config/citys/manage");
}

/**
 * confirm delete city form
 * 
 * @param type $form
 * @param type $form_state
 * @param type $id
 * @return type
 */
function _city_management_admin_delete_confirm($form, &$form_state, $id) {
    $form['id'] = array('#type' => 'value', '#value' => $id);
    return confirm_form($form, t('Are you sure you want to delete this record?'), 'admin/config/citys/manage/', t('This action cannot be undone.'), t('Delete'), t('Cancel')
    );
}

/**
 * Confirm delete city form submit
 * @param type $form
 * @param type $form_state
 */
function _city_management_admin_delete_confirm_submit($form, &$form_state) {
    if ($form_state['values']['confirm']) {
        _city_management_admin_delete($form_state['values']['id']);
        drupal_set_message('city has been deleted succesfully');
        $form_values = $form_state['values'];
    }

    drupal_goto("admin/config/citys/manage");
}

/**
 * Delete city query 
 * 
 * @param type $id
 */
function _city_management_admin_delete($id) {
    db_delete('city')
            ->condition('id', $id)
            ->execute();
}

/**
 * Get citys or single city by id query
 * 
 * @return type
 */
function _city_management_get_citys($id = '') {
    if ($id != '') {
        $result = db_query('SELECT city.id, city.name, city.created, city.long,city.lat FROM city where id = :id', array(':id' => $id));
        return $result->fetchAssoc();
    }
    $result = db_query('SELECT city.id, city.name, city.created, city.long, city.lat FROM city');
    $rows = array();
    $i = 0;
    while ($record = $result->fetchAssoc()) {
        $rows[$i]['name'] = $record['name'];
        $rows[$i]['created'] = date('Y-M-D h:m', $record['created']);
        $rows[$i]['long'] = $record['long'];
        $rows[$i]['lat'] = $record['lat'];
        $rows[$i]['edit'] = l('Edit', 'admin/config/citys/edit/' . $record['id']);
        $rows[$i]['delete'] = l('Delete', 'admin/config/citys/delete/' . $record['id']);

        $i++;
    }
    $header = array(t('Name'), t('Created'), t('Long'), t('Lat'), t('Edit'), t('Delete'));
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    return $output;
}

?>
