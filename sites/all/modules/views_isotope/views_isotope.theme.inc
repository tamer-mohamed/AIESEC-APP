<?php
// $Id:

/**
 * Preprocess function to build the isotope grid
 */
function template_preprocess_views_isotope(&$vars) {
  template_preprocess_views_view_list($vars);

  $view = $vars['view'];
  $options = $view->style_plugin->options;
  $handler = $view->style_plugin;
  $fields = &$view->field;
  $rows = &$vars['rows'];
  $vars['attributes'] = array();

  $vars['isotope_id'] = 'views-isotope-' . $view->name . '-' . $view->style_plugin->display->id;

  drupal_add_css(drupal_get_path('module', 'views_isotope') . '/views_isotope.css');
  drupal_add_js(drupal_get_path('module', 'views_isotope') . '/jquery.isotope.min.js');
  drupal_add_js(drupal_get_path('module', 'views_isotope') . '/views_isotope.js');
}

/**
 * Preprocess function to build the isotope filter block
 */
function template_preprocess_views_isotope_filter_block(&$vars) {
  template_preprocess_views_view_list($vars);
  $view = $vars['view'];
  $options = $view->style_plugin->options;
  $handler = $view->style_plugin;
  $fields = &$view->field;
  $rows = &$vars['rows'];
  $vars['attributes'] = array();
}