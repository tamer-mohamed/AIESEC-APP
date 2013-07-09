<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function get_data_for_lc_by_table_name($tbl, $id) {
    return db_select($tbl, $tbl)
                    ->fields($tbl)
                    ->condition('lc_id', $id)
                    ->execute();
}

function _get_lc_by_id($id) {
    $data = db_select('lc_page', 'lc')
            ->fields('lc')
            ->condition('lc_id', $id)
            ->execute();

    if ($data->rowCount() > 0) {
        $tabs = get_data_for_lc_by_table_name('tab', $id);
        $tabs = $tabs->rowCount() > 0 ? $tabs->fetchAll(PDO::FETCH_ASSOC) : array();

        $news = get_data_for_lc_by_table_name('news', $id);
        $news = $news->rowCount() > 0 ? $news->fetchAll(PDO::FETCH_ASSOC) : array();

        $teams = get_data_for_lc_by_table_name('team', $id);
        $teams = $teams->rowCount() > 0 ? $teams->fetchAll(PDO::FETCH_ASSOC) : array();

        $partners = get_data_for_lc_by_table_name('partner', $id);
        $partners = $partners->rowCount() > 0 ? $partners->fetchAll(PDO::FETCH_ASSOC) : array();

        $lc = array(
            'information' => $data->fetchAssoc(),
            'tabs' => $tabs,
            'fbWall' => null,
            'news' => $news,
            'teams' => $teams,
            'partners' => $partners,
            'email' => get_lcp_email($id), 
        );
        drupal_add_css(drupal_get_path('module', 'lc_managepage') . '/css/lc.css');
        drupal_add_js(drupal_get_path('module', 'lc_managepage') . '/js/lc.js', 'file');
        return theme('theming_lc_page', $lc);
    }
    else
        drupal_not_found();
}

function _get_fb_wall($pageId) {
    ini_set('user_agent', 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.9) Gecko/20071025 Firefox/2.0.0.9');

    $url = 'https://www.facebook.com/feeds/page.php?format=rss20&id=' . $pageId;

    $fbWall = simplexml_load_file($url);
    $fbWall = json_encode($fbWall);
    $fbWall = json_decode($fbWall, true);

    return $fbWall;
}

function get_lcp_email($id) {
    $rid = array_search('lcp', user_roles());
    if ($rid) {
        $query = db_select('users_roles', 'u_r');
        $query->join('users', 'u', 'u.uid = u_r.uid');
        $query->join('field_data_lc_field', 'lc', 'lc.lc_field_value = ' . $id);
        $result = $query
                ->fields('u', array('uid'))
                ->execute();
        return $result->fetchAssoc();
    }
    return false;
}

?>
