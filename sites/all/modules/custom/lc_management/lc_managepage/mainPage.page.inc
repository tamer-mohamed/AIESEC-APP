<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function _get_lc_by_id($id) {
    $data = db_select('lc_page', 'lc')
            ->fields('lc')
            ->condition('lc_id', $id)
            ->execute();

    if ($data->rowCount() > 0) {
        //$fbWall = _get_fb_wall('AIESECglobal');
        
        $lc = array(
            'information' => $data->fetchAssoc(),
            'fbWall' => null
        );
        return theme('theming_lc_page', $lc);
    }
    else
        drupal_not_found();
}

function _get_fb_wall($pageId) {
    ini_set('user_agent', 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.9) Gecko/20071025 Firefox/2.0.0.9');
    
    $url = 'https://www.facebook.com/feeds/page.php?format=rss20&id='.$pageId;

    $fbWall = simplexml_load_file($url);
    $fbWall = json_encode($fbWall);
    $fbWall = json_decode($fbWall, true);
    
    return $fbWall;
}

?>
