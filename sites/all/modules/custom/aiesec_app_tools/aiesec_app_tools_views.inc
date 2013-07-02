<?php

/**
 * @file
 * aiesec_app_tools_views.inc
 */

/**
 * Implements hook_views_default_views().
 */
function aiesec_app_tools_views_default_views() {
    $export = array();

    $view = new view();
    $view->name = 'aiesec_magazine';
    $view->description = 'The blog landing page and the "popular posts" block used with the Dawn theme.';
    $view->tag = 'aiesec';
    $view->base_table = 'node';
    $view->human_name = 'AIESEC: magazine';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Magazine';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['quantity'] = '9';
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['style_options']['default_row_class'] = FALSE;
    $handler->display->display_options['style_options']['row_class_special'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
    /* No results behavior: Global: Unfiltered text */
    $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
    $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
    $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
    $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
    $handler->display->display_options['empty']['area_text_custom']['content'] = '<p>There are no Magazine posts.</p>';
    /* Relationship: Content: Author */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'node';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    $handler->display->display_options['fields']['title']['element_type'] = 'h2';
    $handler->display->display_options['fields']['title']['element_class'] = 'post-title';
    $handler->display->display_options['fields']['title']['element_label_type'] = '0';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
    $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'heading';
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: User: Name */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['exclude'] = TRUE;
    $handler->display->display_options['fields']['name']['element_type'] = '0';
    $handler->display->display_options['fields']['name']['element_label_type'] = '0';
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
    /* Field: Content: Post date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['exclude'] = TRUE;
    $handler->display->display_options['fields']['created']['element_type'] = '0';
    $handler->display->display_options['fields']['created']['element_label_type'] = '0';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'custom';
    $handler->display->display_options['fields']['created']['custom_date_format'] = 'F jS, Y';
    /* Field: Content: All taxonomy terms */
    $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
    $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
    $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
    $handler->display->display_options['fields']['term_node_tid']['label'] = '';
    $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
    $handler->display->display_options['fields']['term_node_tid']['element_type'] = '0';
    $handler->display->display_options['fields']['term_node_tid']['element_label_type'] = '0';
    $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['term_node_tid']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
        'forums' => 0,
        'categories' => 0,
        'portfolio' => 0,
        'tags' => 0,
    );
    /* Field: Content: Comment count */
    $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
    $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
    $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
    $handler->display->display_options['fields']['comment_count']['label'] = '';
    $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['comment_count']['alter']['text'] = '		<ul class="post-meta clearfix">
			<li><span class="icon-pencil"></span> [name]</li>
			<li><span class="icon-calendar"></span> [created]</li>
			<li><span class="icon-comment"></span> [comment_count]</li>
			<li><span class="icon-tags"></span> [term_node_tid]</li>
		</ul>';
    $handler->display->display_options['fields']['comment_count']['element_type'] = '0';
    $handler->display->display_options['fields']['comment_count']['element_label_type'] = '0';
    $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['comment_count']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['comment_count']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['comment_count']['suffix'] = ' comments ';
    /* Field: Content: Image */
    $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
    $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['label'] = '';
    $handler->display->display_options['fields']['field_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_image']['element_class'] = 'img-polaroid';
    $handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
    $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_image']['settings'] = array(
        'image_style' => 'blog_post',
        'image_link' => '',
    );
    /* Field: Content: Body */
    $handler->display->display_options['fields']['body']['id'] = 'body';
    $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
    $handler->display->display_options['fields']['body']['field'] = 'body';
    $handler->display->display_options['fields']['body']['label'] = '';
    $handler->display->display_options['fields']['body']['element_type'] = 'div';
    $handler->display->display_options['fields']['body']['element_class'] = 'post-summary';
    $handler->display->display_options['fields']['body']['element_label_type'] = '0';
    $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
    $handler->display->display_options['fields']['body']['settings'] = array(
        'trim_length' => '600',
    );
    /* Sort criterion: Content: Post date */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'node';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Content: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
        'magazine' => 'magazine',
    );

    /* Display: Blog Home */
    $handler = $view->new_display('page', 'Magazine Home', 'page_1');
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Content: Path */
    $handler->display->display_options['fields']['path']['id'] = 'path';
    $handler->display->display_options['fields']['path']['table'] = 'node';
    $handler->display->display_options['fields']['path']['field'] = 'path';
    $handler->display->display_options['fields']['path']['label'] = '';
    $handler->display->display_options['fields']['path']['exclude'] = TRUE;
    $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;

    /* Field: Content: user_types */
    $handler->display->display_options['fields']['field_user_category']['id'] = 'field_user_category';
    $handler->display->display_options['fields']['field_user_category']['table'] = 'field_data_field_user_category';
    $handler->display->display_options['fields']['field_user_category']['field'] = 'field_user_category';
    $handler->display->display_options['fields']['field_user_category']['label'] = '';
    $handler->display->display_options['fields']['field_user_category']['type'] = 'taxonomy_term_reference_plain';
    $handler->display->display_options['fields']['field_user_category']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_user_category']['element_label_colon'] = FALSE;
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    $handler->display->display_options['fields']['title']['element_type'] = '0';
    $handler->display->display_options['fields']['title']['element_class'] = 'post-title';
    $handler->display->display_options['fields']['title']['element_label_type'] = '0';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
    $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'heading';
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;

    $handler->display->display_options['fields']['title']['alter']['text'] = '
<h2 class="post-title"><a href="[path]">[title]</a></h2>
<div class="title-suffix"><span class="label label-[field_user_category]">[field_user_category]</span></div>';
    /* Field: User: Name */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['exclude'] = TRUE;
    $handler->display->display_options['fields']['name']['element_type'] = '0';
    $handler->display->display_options['fields']['name']['element_label_type'] = '0';
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
    /* Field: Content: Post date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['exclude'] = TRUE;
    $handler->display->display_options['fields']['created']['element_type'] = '0';
    $handler->display->display_options['fields']['created']['element_label_type'] = '0';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'custom';
    $handler->display->display_options['fields']['created']['custom_date_format'] = 'F jS, Y';
    /* Field: Content: Tags */
    $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
    $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
    $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
    $handler->display->display_options['fields']['field_tags']['label'] = '';
    $handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_tags']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_tags']['hide_empty'] = TRUE;
    $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
    $handler->display->display_options['fields']['field_tags']['separator'] = ' / ';
    /* Field: Content: Comment count */
    $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
    $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
    $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
    $handler->display->display_options['fields']['comment_count']['label'] = '';
    $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['comment_count']['alter']['text'] = '		<ul class="post-meta clearfix">
			<li><span class="icon-pencil"></span> [name]</li>
			<li><span class="icon-calendar"></span> [created]</li>
			<li><span class="icon-comment"></span> [comment_count]</li>
			<li><span class="icon-tags"></span> [field_tags]</li>
		</ul>';
    $handler->display->display_options['fields']['comment_count']['element_type'] = '0';
    $handler->display->display_options['fields']['comment_count']['element_label_type'] = '0';
    $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['comment_count']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['comment_count']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['comment_count']['suffix'] = ' comments ';
    /* Field: Content: Image */
    $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
    $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['label'] = '';
    $handler->display->display_options['fields']['field_image']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['field_image']['alter']['text'] = '<a href="[path]"><span class="view-more"></span><span class="hover"></span></a>[field_image]';
    $handler->display->display_options['fields']['field_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_image']['element_class'] = 'img-polaroid blog';
    $handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
    $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_image']['settings'] = array(
        'image_style' => 'blog_post',
        'image_link' => '',
    );
    /* Field: Content: Body */
    $handler->display->display_options['fields']['body']['id'] = 'body';
    $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
    $handler->display->display_options['fields']['body']['field'] = 'body';
    $handler->display->display_options['fields']['body']['label'] = '';
    $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['body']['alter']['text'] = '<p>[body]</p>
<a href="[path]" class="btn btn-small">Read More</a>';
    $handler->display->display_options['fields']['body']['element_type'] = 'div';
    $handler->display->display_options['fields']['body']['element_class'] = 'post-summary';
    $handler->display->display_options['fields']['body']['element_label_type'] = '0';
    $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
    $handler->display->display_options['fields']['body']['settings'] = array(
        'trim_length' => '600',
    );
    $handler->display->display_options['path'] = 'magazine';

    /* Display: Popular Posts */
    $handler = $view->new_display('block', 'Popular Posts', 'block_1');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Popular Posts';
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['css_class'] = 'popular-posts';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '3';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Content: Image */
    $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
    $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['label'] = '';
    $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_image']['element_class'] = 'img-polaroid';
    $handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
    $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_image']['settings'] = array(
        'image_style' => 'popular_post',
        'image_link' => 'content',
    );
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['exclude'] = TRUE;
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    $handler->display->display_options['fields']['title']['element_type'] = '0';
    $handler->display->display_options['fields']['title']['element_label_type'] = '0';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Content: Post date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['created']['alter']['text'] = '<div class="img-polaroid">[field_image]</div>
<div class="post-info">
<h2 class="post-title">[title]</h2>
<span class="icon-calendar"></span> [created]
</div>';
    $handler->display->display_options['fields']['created']['element_type'] = 'div';
    $handler->display->display_options['fields']['created']['element_class'] = 'post';
    $handler->display->display_options['fields']['created']['element_label_type'] = '0';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'custom';
    $handler->display->display_options['fields']['created']['custom_date_format'] = 'F jS, Y';
    $handler->display->display_options['defaults']['sorts'] = FALSE;
    /* Sort criterion: Content statistics: Total views */
    $handler->display->display_options['sorts']['totalcount']['id'] = 'totalcount';
    $handler->display->display_options['sorts']['totalcount']['table'] = 'node_counter';
    $handler->display->display_options['sorts']['totalcount']['field'] = 'totalcount';
    $handler->display->display_options['sorts']['totalcount']['order'] = 'DESC';
    $export['aiesec_magazine'] = $view;


    // EVENTS VIEW 
    $view = new view();
    $view->name = 'aiesec_events';
    $view->description = 'The blog landing page and the "popular posts" block used with the Dawn theme.';
    $view->tag = 'aiesec';
    $view->base_table = 'node';
    $view->human_name = 'AIESEC: Events';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Events';
    $handler->display->display_options['use_more'] = TRUE;
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'See all';
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['quantity'] = '9';
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['style_options']['default_row_class'] = FALSE;
    $handler->display->display_options['style_options']['row_class_special'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
    /* No results behavior: Global: Unfiltered text */
    $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
    $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
    $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
    $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
    $handler->display->display_options['empty']['area_text_custom']['content'] = '<p>There are no Magazine posts.</p>';
    /* Relationship: Content: Author */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'node';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    $handler->display->display_options['fields']['title']['element_type'] = 'h2';
    $handler->display->display_options['fields']['title']['element_class'] = 'post-title';
    $handler->display->display_options['fields']['title']['element_label_type'] = '0';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
    $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'heading';
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Content: Date */
    $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
    $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
    $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
    $handler->display->display_options['fields']['field_date']['label'] = '';
    $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['field_date']['alter']['text'] = '<div class="img-polaroid">[field_image]</div>
<div class="post-info">
<h2 class="post-title">[title]</h2>
<span class="icon-calendar"></span> [field_date]
</div>';
    $handler->display->display_options['fields']['field_date']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_date']['element_class'] = 'post';
    $handler->display->display_options['fields']['field_date']['element_label_type'] = '0';
    $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_date']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_date']['settings'] = array(
        'show_repeat_rule' => 'hide',
    );
    /* Field: Content: Post date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['exclude'] = TRUE;
    $handler->display->display_options['fields']['created']['element_type'] = '0';
    $handler->display->display_options['fields']['created']['element_label_type'] = '0';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'custom';
    $handler->display->display_options['fields']['created']['custom_date_format'] = 'F jS, Y';
    /* Field: Content: All taxonomy terms */
    $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
    $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
    $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
    $handler->display->display_options['fields']['term_node_tid']['label'] = '';
    $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
    $handler->display->display_options['fields']['term_node_tid']['element_type'] = '0';
    $handler->display->display_options['fields']['term_node_tid']['element_label_type'] = '0';
    $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['term_node_tid']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
        'forums' => 0,
        'categories' => 0,
        'portfolio' => 0,
        'tags' => 0,
    );
    /* Field: Content: Comment count */
    $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
    $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
    $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
    $handler->display->display_options['fields']['comment_count']['label'] = '';
    $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['comment_count']['alter']['text'] = '		<ul class="post-meta clearfix">
			<li><span class="icon-pencil"></span> [name]</li>
			<li><span class="icon-calendar"></span> [created]</li>
			<li><span class="icon-comment"></span> [comment_count]</li>
			<li><span class="icon-tags"></span> [term_node_tid]</li>
		</ul>';
    $handler->display->display_options['fields']['comment_count']['element_type'] = '0';
    $handler->display->display_options['fields']['comment_count']['element_label_type'] = '0';
    $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['comment_count']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['comment_count']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['comment_count']['suffix'] = ' comments ';
    /* Field: Content: Image */
    $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
    $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['label'] = '';
    $handler->display->display_options['fields']['field_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_image']['element_class'] = 'img-polaroid';
    $handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
    $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_image']['settings'] = array(
        'image_style' => 'blog_post',
        'image_link' => '',
    );
    /* Field: Content: Body */
    $handler->display->display_options['fields']['body']['id'] = 'body';
    $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
    $handler->display->display_options['fields']['body']['field'] = 'body';
    $handler->display->display_options['fields']['body']['label'] = '';
    $handler->display->display_options['fields']['body']['element_type'] = 'div';
    $handler->display->display_options['fields']['body']['element_class'] = 'post-summary';
    $handler->display->display_options['fields']['body']['element_label_type'] = '0';
    $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
    $handler->display->display_options['fields']['body']['settings'] = array(
        'trim_length' => '600',
    );
    /* Sort criterion: Content: Date (field_date) */
    $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
    $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
    $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
    $handler->display->display_options['sorts']['field_date_value']['expose']['label'] = 'Date (field_date)';
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Content: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
        'events' => 'events',
    );

    /* Display: Upcoming Events */
    $handler = $view->new_display('block', 'Upcoming Events', 'block_upcoming');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Upcoming Events';
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['css_class'] = 'popular-posts';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '5';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Content: Image */
    $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
    $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['label'] = '';
    $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_image']['element_class'] = 'img-polaroid';
    $handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
    $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_image']['settings'] = array(
        'image_style' => 'popular_post',
        'image_link' => 'content',
    );
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['exclude'] = TRUE;
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    $handler->display->display_options['fields']['title']['element_type'] = '0';
    $handler->display->display_options['fields']['title']['element_label_type'] = '0';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Content: Date */
    $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
    $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
    $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
    $handler->display->display_options['fields']['field_date']['label'] = '';
    $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['field_date']['alter']['text'] = '<div class="img-polaroid">[field_image]</div>
<div class="post-info">
<h2 class="post-title">[title]</h2>
<span class="icon-calendar"></span> [field_date]
</div>';
    $handler->display->display_options['fields']['field_date']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_date']['element_class'] = 'post';
    $handler->display->display_options['fields']['field_date']['element_label_type'] = '0';
    $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_date']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_date']['settings'] = array(
        'show_repeat_rule' => 'hide',
    );

    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page_1');
    $handler->display->display_options['path'] = 'Events';
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = 'Events';
    $handler->display->display_options['menu']['description'] = 'AIESEC Events';
    $handler->display->display_options['menu']['weight'] = '0';
    $handler->display->display_options['menu']['name'] = 'main-menu';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;

    $export['aiesec_events'] = $view;
    /// SLIDER 


    $view = new view();
    $view->name = 'revolution_slider';
    $view->description = 'View blocks used in conjunction with the Revolution Slider module.';
    $view->tag = 'revolution_slider';
    $view->base_table = 'node';
    $view->human_name = 'Revolution Slider';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '5';
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['style_options']['default_row_class'] = FALSE;
    $handler->display->display_options['style_options']['row_class_special'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['row_options']['hide_empty'] = TRUE;
    $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
    /* Footer: Global: Unfiltered text */
    $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
    $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
    $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
    $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="tp-bannertimer"></div>';
    /* No results behavior: Global: Unfiltered text */
    $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
    $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
    $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
    $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
    $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="empty-slider">
<p class="empty">The slider is empty. To build a slide, navigate to Add Content > Slide Builder.</p>
<p class="empty-homepage">If you would like to disable this block, please edit the Dawn homepage context.<p>
<div class="tp-bannertimer"></div>
</div>';
    /* Field: Content: Image */
    $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
    $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['label'] = '';
    $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_image']['settings'] = array(
        'image_style' => '',
        'image_link' => '',
    );
    /* Sort criterion: Content: Post date */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'node';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Content: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
        'slide_builder' => 'slide_builder',
    );

    /* Display: Block */
    $handler = $view->new_display('block', 'Block', 'block');
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['css_class'] = 'fullwidthbanner-container';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'revolution_slider';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['row_options']['hide_empty'] = TRUE;
    $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Content: Image */
    $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
    $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['label'] = '';
    $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_image']['settings'] = array(
        'image_style' => '',
        'image_link' => '',
    );
    /* Field: Content: Layer Settings */
    $handler->display->display_options['fields']['field_layer_settings']['id'] = 'field_layer_settings';
    $handler->display->display_options['fields']['field_layer_settings']['table'] = 'field_data_field_layer_settings';
    $handler->display->display_options['fields']['field_layer_settings']['field'] = 'field_layer_settings';
    $handler->display->display_options['fields']['field_layer_settings']['label'] = '';
    $handler->display->display_options['fields']['field_layer_settings']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_layer_settings']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_layer_settings']['click_sort_column'] = 'layer';
    $handler->display->display_options['fields']['field_layer_settings']['delta_offset'] = '0';
    $handler->display->display_options['fields']['field_layer_settings']['separator'] = '';
    /* Field: Content: Slide Settings */
    $handler->display->display_options['fields']['field_slide_settings']['id'] = 'field_slide_settings';
    $handler->display->display_options['fields']['field_slide_settings']['table'] = 'field_data_field_slide_settings';
    $handler->display->display_options['fields']['field_slide_settings']['field'] = 'field_slide_settings';
    $handler->display->display_options['fields']['field_slide_settings']['label'] = '';
    $handler->display->display_options['fields']['field_slide_settings']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['field_slide_settings']['alter']['text'] = '[field_slide_settings][field_image][field_layer_settings]';
    $handler->display->display_options['fields']['field_slide_settings']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_slide_settings']['click_sort_column'] = 'image';
    $export['revolution_slider'] = $view;


    return $export;
}
