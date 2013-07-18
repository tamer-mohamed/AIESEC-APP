<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function get_data_for_lc_by_table_name($tbl, $id,$limit = 2,$pager = false) {
    $query = db_select($tbl, $tbl);
    $query->fields($tbl);
    $query->condition('lc_id', $id);
    
    if($pager)
         $query = $query->extend('PagerDefault')->limit(1);
    else
         $query = $query->range(0,$limit);
    return $query->execute();
}

function _get_lc_by_id($id) {
    $data = db_select('lc_page', 'lc');
    $data->join('lc', 'l', 'lc.lc_id = l.id');

    $data = $data->fields('lc')
            ->fields('l')
            ->condition('lc_id', $id)
            ->execute();

    if ($data->rowCount() > 0) {
        $tabs = get_data_for_lc_by_table_name('tab', $id);
        $tabs = $tabs->rowCount() > 0 ? $tabs->fetchAll(PDO::FETCH_ASSOC) : array();

        $news = get_data_for_lc_by_table_name('news', $id);
        $news = $news->rowCount() > 0 ? $news->fetchAll(PDO::FETCH_ASSOC) : array();

        $allNews = get_data_for_lc_by_table_name('news', $id,2,true);
        $allNews = $allNews->rowCount() > 0 ? $allNews->fetchAll(PDO::FETCH_ASSOC) : array();
        
        $teams = get_data_for_lc_by_table_name('team', $id);
        $teams = $teams->rowCount() > 0 ? $teams->fetchAll(PDO::FETCH_ASSOC) : array();

        $partners = get_data_for_lc_by_table_name('partner', $id);
        $partners = $partners->rowCount() > 0 ? $partners->fetchAll(PDO::FETCH_ASSOC) : array();

        $lc = array(
            'information' => $data->fetchAssoc(),
            'tabs' => $tabs,
            'fbWall' => null,
            'news' => array(
                'teasers' => $news,
                'all' => $allNews,
                'pager' => theme('pager')
            ),
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
