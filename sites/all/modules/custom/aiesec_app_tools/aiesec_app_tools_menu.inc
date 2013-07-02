<?php

function aiesec_app_tools_menu_default_menu_links() {
    $menu_links = array();
    // Exported menu link: main-menu:<front>
    $menu_links['main-menu:<front>'] = array(
        'menu_name' => 'main-menu',
        'link_path' => '<front>',
        'router_path' => '',
        'link_title' => 'Home',
        'options' => array(
            'attributes' => array(
                'title' => '',
            ),
        ),
        'module' => 'menu',
        'hidden' => '0',
        'external' => '1',
        'has_children' => '0',
        'expanded' => '1',
        'weight' => '1',
    );

    // Exported menu link: main-menu:contact
    $menu_links['main-menu:contact'] = array(
        'menu_name' => 'main-menu',
        'link_path' => 'contact',
        'router_path' => 'contact',
        'link_title' => 'Contact',
        'options' => array(
            'attributes' => array(
                'title' => '',
            ),
        ),
        'module' => 'menu',
        'hidden' => '0',
        'external' => '0',
        'has_children' => '0',
        'expanded' => '0',
        'weight' => '5',
    );
    // Exported menu link: main-menu:forum
    $menu_links['main-menu:forum'] = array(
        'menu_name' => 'main-menu',
        'link_path' => 'forum',
        'router_path' => 'forum',
        'link_title' => 'Forum',
        'options' => array(
            'attributes' => array(
                'title' => '',
            ),
        ),
        'module' => 'menu',
        'hidden' => '0',
        'external' => '0',
        'has_children' => '0',
        'expanded' => '0',
        'weight' => '-47',
        'parent_path' => 'services',
    );
    // Exported menu link: main-menu:Magazine
    $menu_links['main-menu:magazine'] = array(
        'menu_name' => 'main-menu',
        'link_path' => 'magazine',
        'router_path' => 'magazine',
        'link_title' => 'Magazine',
        'options' => array(
            'attributes' => array(
                'title' => '',
            ),
        ),
        'module' => 'menu',
        'hidden' => '0',
        'external' => '0',
        'has_children' => '0',
        'expanded' => '0',
        'weight' => '3',
    );
    // Exported menu link: main-menu:Events
    $menu_links['main-menu:events'] = array(
        'menu_name' => 'main-menu',
        'link_path' => 'events',
        'router_path' => 'events',
        'link_title' => 'Events',
        'options' => array(
            'attributes' => array(
                'title' => '',
            ),
        ),
        'module' => 'menu',
        'hidden' => '0',
        'external' => '0',
        'has_children' => '0',
        'expanded' => '0',
        'weight' => '4',
    );
    // Translatables
    // Included for use with string extractors like potx.
    t('Magazine');
    t('Contact');
    t('Events');
    t('Features');
    t('Forum');
    t('Home');
    return $menu_links;
}

?>