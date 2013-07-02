<?php

// MAGAZINE
function _create_magazine_fields() {
    if (!field_info_field('body')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(
                0 => 'node',
            ),
            'field_name' => 'body',
            'foreign keys' => array(
                'format' => array(
                    'columns' => array(
                        'format' => 'format',
                    ),
                    'table' => 'filter_format',
                ),
            ),
            'indexes' => array(
                'format' => array(
                    0 => 'format',
                ),
            ),
            'locked' => '0',
            'module' => 'text',
            'settings' => array(),
            'translatable' => '0',
            'type' => 'text_with_summary',
        );
        field_create_field($field);
    }
    if (!field_info_field('field_image')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_image',
            'foreign keys' => array(
                'fid' => array(
                    'columns' => array(
                        'fid' => 'fid',
                    ),
                    'table' => 'file_managed',
                ),
            ),
            'indexes' => array(
                'fid' => array(
                    0 => 'fid',
                ),
            ),
            'locked' => '0',
            'module' => 'image',
            'settings' => array(
                'default_image' => FALSE,
                'uri_scheme' => 'public',
            ),
            'translatable' => '0',
            'type' => 'image',
        );
        field_create_field($field);
    }
    if (!field_info_field('field_tags')) {
        $field = array(
            'active' => '1',
            'cardinality' => '-1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_tags',
            'foreign keys' => array(
                'tid' => array(
                    'columns' => array(
                        'tid' => 'tid',
                    ),
                    'table' => 'taxonomy_term_data',
                ),
            ),
            'indexes' => array(
                'tid' => array(
                    0 => 'tid',
                ),
            ),
            'locked' => '0',
            'module' => 'taxonomy',
            'settings' => array(
                'allowed_values' => array(
                    0 => array(
                        'vocabulary' => 'tags',
                        'parent' => 0,
                    ),
                ),
            ),
            'translatable' => '0',
            'type' => 'taxonomy_term_reference',
        );
        field_create_field($field);
    }
    if (!field_info_field('field_user_category')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_user_category',
            'foreign keys' => array(
                'tid' => array(
                    'columns' => array(
                        'tid' => 'tid',
                    ),
                    'table' => 'taxonomy_term_data',
                ),
            ),
            'indexes' => array(
                'tid' => array(
                    0 => 'tid',
                ),
            ),
            'locked' => '0',
            'module' => 'taxonomy',
            'settings' => array(
                'allowed_values' => array(
                    0 => array(
                        'vocabulary' => 'user_types',
                        'parent' => '0',
                    ),
                ),
            ),
            'translatable' => '0',
            'type' => 'taxonomy_term_reference',
        );
        field_create_field($field);
    }
}

function _delete_magazine_fields() {
    field_delete_field('body');
    field_delete_field('field_image');
    field_delete_field('field_tags');
    field_delete_field('field_user_category');
}

function _magazine_create_instances() {
    $instance = array(
        'bundle' => 'magazine',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(),
                'type' => 'text_default',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(
                    'trim_length' => 600,
                ),
                'type' => 'text_summary_or_trimmed',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'body',
        'label' => 'Body',
        'required' => FALSE,
        'settings' => array(
            'display_summary' => TRUE,
            'text_processing' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'module' => 'text',
            'settings' => array(
                'rows' => 20,
                'summary_rows' => 5,
            ),
            'type' => 'text_textarea_with_summary',
            'weight' => '3',
        )
    );

    field_create_instance($instance);


    // user Category
    $instance = array(
        'bundle' => 'magazine',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_user_category',
        'label' => 'Category',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'options',
            'settings' => array(),
            'type' => 'options_select',
            'weight' => '5',
        )
    );

    field_create_instance($instance);

    // Image
    $instance = array(
        'bundle' => 'magazine',
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'image',
                'weight' => '1',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_image',
        'label' => 'Image',
        'required' => 0,
        'settings' => array(
            'alt_field' => 1,
            'default_image' => 0,
            'file_directory' => '',
            'file_extensions' => 'png gif jpg jpeg',
            'max_filesize' => '',
            'max_resolution' => '',
            'min_resolution' => '',
            'title_field' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'image',
            'settings' => array(
                'preview_image_style' => 'thumbnail',
                'progress_indicator' => 'throbber',
            ),
            'type' => 'image_image',
            'weight' => '1',
        )
    );

    field_create_instance($instance);


    // TAGS
    $instance = array(
        'bundle' => 'magazine',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'taxonomy',
                'settings' => array(),
                'type' => 'taxonomy_term_reference_link',
                'weight' => '3',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_tags',
        'label' => 'Tags',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 0,
            'module' => 'options',
            'settings' => array(
                'autocomplete_path' => 'taxonomy/autocomplete',
                'size' => 60,
            ),
            'type' => 'options_buttons',
            'weight' => '4',
        )
    );

    field_create_instance($instance);
}

function _magazine_delete_instances() {
    $instance = array(
        'bundle' => 'magazine',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(),
                'type' => 'text_default',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(
                    'trim_length' => 600,
                ),
                'type' => 'text_summary_or_trimmed',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'body',
        'label' => 'Body',
        'required' => FALSE,
        'settings' => array(
            'display_summary' => TRUE,
            'text_processing' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'module' => 'text',
            'settings' => array(
                'rows' => 20,
                'summary_rows' => 5,
            ),
            'type' => 'text_textarea_with_summary',
            'weight' => '3',
        )
    );

    field_delete_instance($instance);


    // user Category
    $instance = array(
        'bundle' => 'magazine',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_user_category',
        'label' => 'Category',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'options',
            'settings' => array(),
            'type' => 'options_select',
            'weight' => '5',
        )
    );

    field_delete_instance($instance);

    // Image
    $instance = array(
        'bundle' => 'magazine',
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '1',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_image',
        'label' => 'Image',
        'required' => 0,
        'settings' => array(
            'alt_field' => 1,
            'default_image' => 0,
            'file_directory' => '',
            'file_extensions' => 'png gif jpg jpeg',
            'max_filesize' => '',
            'max_resolution' => '',
            'min_resolution' => '',
            'title_field' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'image',
            'settings' => array(
                'preview_image_style' => 'thumbnail',
                'progress_indicator' => 'throbber',
            ),
            'type' => 'image_image',
            'weight' => '1',
        )
    );

    field_delete_instance($instance);


    // TAGS
    $instance = array(
        'bundle' => 'magazine',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'taxonomy',
                'settings' => array(),
                'type' => 'taxonomy_term_reference_link',
                'weight' => '3',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_tags',
        'label' => 'Tags',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 0,
            'module' => 'options',
            'settings' => array(
                'autocomplete_path' => 'taxonomy/autocomplete',
                'size' => 60,
            ),
            'type' => 'options_buttons',
            'weight' => '4',
        )
    );

    field_delete_instance($instance);
}

// Events
function _create_events_fields() {
    if (!field_info_field('body')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(
                0 => 'node',
            ),
            'field_name' => 'body',
            'foreign keys' => array(
                'format' => array(
                    'columns' => array(
                        'format' => 'format',
                    ),
                    'table' => 'filter_format',
                ),
            ),
            'indexes' => array(
                'format' => array(
                    0 => 'format',
                ),
            ),
            'locked' => '0',
            'module' => 'text',
            'settings' => array(),
            'translatable' => '0',
            'type' => 'text_with_summary',
        );
        field_create_field($field);
    }
    if (!field_info_field('field_image')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_image',
            'foreign keys' => array(
                'fid' => array(
                    'columns' => array(
                        'fid' => 'fid',
                    ),
                    'table' => 'file_managed',
                ),
            ),
            'indexes' => array(
                'fid' => array(
                    0 => 'fid',
                ),
            ),
            'locked' => '0',
            'module' => 'image',
            'settings' => array(
                'default_image' => FALSE,
                'uri_scheme' => 'public',
            ),
            'translatable' => '0',
            'type' => 'image',
        );
        field_create_field($field);
    }if (!field_info_field('field_date')) {
        $tz_handling= 'site';
        $field = array(
            'field_name' => 'field_date',
            'type' => 'date',
            'cardinality' => FIELD_CARDINALITY_UNLIMITED,
            'settings' => array(
                'granularity' => array('year','month','day','hour','minute'),
                'tz_handling' => $tz_handling,
                'timezone_db' => date_get_timezone_db($tz_handling),
                'repeat' => 1,
                'todate' => !empty($todate) ? $todate : 'optional',
            ),
        );
        field_create_field($field);
    }
    if (!field_info_field('field_tags')) {
        $field = array(
            'active' => '1',
            'cardinality' => '-1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_tags',
            'foreign keys' => array(
                'tid' => array(
                    'columns' => array(
                        'tid' => 'tid',
                    ),
                    'table' => 'taxonomy_term_data',
                ),
            ),
            'indexes' => array(
                'tid' => array(
                    0 => 'tid',
                ),
            ),
            'locked' => '0',
            'module' => 'taxonomy',
            'settings' => array(
                'allowed_values' => array(
                    0 => array(
                        'vocabulary' => 'tags',
                        'parent' => 0,
                    ),
                ),
            ),
            'translatable' => '0',
            'type' => 'taxonomy_term_reference',
        );
        field_create_field($field);
    }
    if (!field_info_field('field_user_category')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_user_category',
            'foreign keys' => array(
                'tid' => array(
                    'columns' => array(
                        'tid' => 'tid',
                    ),
                    'table' => 'taxonomy_term_data',
                ),
            ),
            'indexes' => array(
                'tid' => array(
                    0 => 'tid',
                ),
            ),
            'locked' => '0',
            'module' => 'taxonomy',
            'settings' => array(
                'allowed_values' => array(
                    0 => array(
                        'vocabulary' => 'user_types',
                        'parent' => '0',
                    ),
                ),
            ),
            'translatable' => '0',
            'type' => 'taxonomy_term_reference',
        );
        field_create_field($field);
    }
    if (!field_info_field('field_event_types')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_event_types',
            'foreign keys' => array(
                'tid' => array(
                    'columns' => array(
                        'tid' => 'tid',
                    ),
                    'table' => 'taxonomy_term_data',
                ),
            ),
            'indexes' => array(
                'tid' => array(
                    0 => 'tid',
                ),
            ),
            'locked' => '0',
            'module' => 'taxonomy',
            'settings' => array(
                'allowed_values' => array(
                    0 => array(
                        'vocabulary' => 'event_types',
                        'parent' => '0',
                    ),
                ),
            ),
            'translatable' => '0',
            'type' => 'taxonomy_term_reference',
        );
        field_create_field($field);
    }
}

function _delete_events_fields() {
    field_delete_field('body');
    field_delete_field('field_image');
    field_delete_field('field_tags');
    field_delete_field('field_user_category');
}

function _events_create_instances() {
    $instance = array(
        'bundle' => 'events',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(),
                'type' => 'text_default',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(
                    'trim_length' => 600,
                ),
                'type' => 'text_summary_or_trimmed',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'body',
        'label' => 'Body',
        'required' => FALSE,
        'settings' => array(
            'display_summary' => TRUE,
            'text_processing' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'module' => 'text',
            'settings' => array(
                'rows' => 20,
                'summary_rows' => 5,
            ),
            'type' => 'text_textarea_with_summary',
            'weight' => '3',
        )
    );

    field_create_instance($instance);


    // user Category
    $instance = array(
        'bundle' => 'events',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_user_category',
        'label' => 'Category',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'options',
            'settings' => array(),
            'type' => 'options_select',
            'weight' => '5',
        )
    );

    field_create_instance($instance);

    // Image
    $instance = array(
        'bundle' => 'events',
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'image',
                'weight' => '1',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_image',
        'label' => 'Image',
        'required' => 0,
        'settings' => array(
            'alt_field' => 1,
            'default_image' => 0,
            'file_directory' => '',
            'file_extensions' => 'png gif jpg jpeg',
            'max_filesize' => '',
            'max_resolution' => '',
            'min_resolution' => '',
            'title_field' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'image',
            'settings' => array(
                'preview_image_style' => 'thumbnail',
                'progress_indicator' => 'throbber',
            ),
            'type' => 'image_image',
            'weight' => '1',
        )
    );

    field_create_instance($instance);


    // TAGS
    $instance = array(
        'bundle' => 'events',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'taxonomy',
                'settings' => array(),
                'type' => 'taxonomy_term_reference_link',
                'weight' => '3',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_tags',
        'label' => 'Tags',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 0,
            'module' => 'options',
            'settings' => array(
                'autocomplete_path' => 'taxonomy/autocomplete',
                'size' => 60,
            ),
            'type' => 'taxonomy_autocomplete',
            'weight' => '4',
        )
    );

    field_create_instance($instance);

    // EVENTS TYPES
    $instance = array(
        'bundle' => 'events',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_event_types',
        'label' => 'Category',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'options',
            'settings' => array(),
            'type' => 'options_select',
            'weight' => '5',
        )
    );

    field_create_instance($instance);
    
    // DATE
    $instance = array(
    'entity_type' => 'node',
    'field_name' => 'field_date',
    'label' => 'Date',
    'bundle' => 'events',
    // Move the date right below the title.
    'weight' => -4,
    'widget' => array(
      'type' => 'date_select',
      // Increment for minutes and seconds, can be 1, 5, 10, 15, or 30.
      'settings' => array(
        'increment' => 15,
        // The number of years to go back and forward in drop-down year
        // selectors.
        'year_range' => '-0:+1',
        'input_format' => date_default_format('date_select'),
        'text_parts' => array(),
        'label_position' => 'above',
        'repeat_collapsed' => 0,
      ),
      'weight' => -4,
    ),
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'blank',
    ),
  );

  $instance['display'] = array(
    'default' => array(
      'label' => 'above',
      'type' => 'date_default',
      'settings' => array(
        'format_type' => 'long',
        'show_repeat_rule' => 'show',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'module' => 'date',
      'weight' => 0 ,
    ),
    'teaser' => array(
      'label' => 'above',
      'type' => 'date_default',
      'weight' => 0,
      'settings' => array(
        'format_type' => 'long',
        'show_repeat_rule' => 'show',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'module' => 'date',
    ),
  );
   field_create_instance($instance);
}

function _events_delete_instances() {
    $instance = array(
        'bundle' => 'events',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(),
                'type' => 'text_default',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(
                    'trim_length' => 600,
                ),
                'type' => 'text_summary_or_trimmed',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'body',
        'label' => 'Body',
        'required' => FALSE,
        'settings' => array(
            'display_summary' => TRUE,
            'text_processing' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'module' => 'text',
            'settings' => array(
                'rows' => 20,
                'summary_rows' => 5,
            ),
            'type' => 'text_textarea_with_summary',
            'weight' => '3',
        )
    );

    field_delete_instance($instance);


    // user Category
    $instance = array(
        'bundle' => 'events',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_user_category',
        'label' => 'Category',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'options',
            'settings' => array(),
            'type' => 'options_select',
            'weight' => '5',
        )
    );

    field_delete_instance($instance);
// user Category
    $instance = array(
        'bundle' => 'events',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_event_types',
        'label' => 'Category',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'options',
            'settings' => array(),
            'type' => 'options_select',
            'weight' => '5',
        )
    );

    field_delete_instance($instance);
    // Image
    $instance = array(
        'bundle' => 'events',
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '1',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_image',
        'label' => 'Image',
        'required' => 0,
        'settings' => array(
            'alt_field' => 1,
            'default_image' => 0,
            'file_directory' => '',
            'file_extensions' => 'png gif jpg jpeg',
            'max_filesize' => '',
            'max_resolution' => '',
            'min_resolution' => '',
            'title_field' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'image',
            'settings' => array(
                'preview_image_style' => 'thumbnail',
                'progress_indicator' => 'throbber',
            ),
            'type' => 'image_image',
            'weight' => '1',
        )
    );

    field_delete_instance($instance);


    // TAGS
    $instance = array(
        'bundle' => 'events',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'taxonomy',
                'settings' => array(),
                'type' => 'taxonomy_term_reference_link',
                'weight' => '3',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_tags',
        'label' => 'Tags',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 0,
            'module' => 'options',
            'settings' => array(
                'autocomplete_path' => 'taxonomy/autocomplete',
                'size' => 60,
            ),
            'type' => 'taxonomy_autocomplete',
            'weight' => '4',
        )
    );

    field_delete_instance($instance);
     // DATE
    $instance = array(
    'entity_type' => 'node',
    'field_name' => 'field_date',
    'label' => 'Date',
    'bundle' => 'events',
    // Move the date right below the title.
    'weight' => -4,
    'widget' => array(
      'type' => 'date_select',
      // Increment for minutes and seconds, can be 1, 5, 10, 15, or 30.
      'settings' => array(
        'increment' => 15,
        // The number of years to go back and forward in drop-down year
        // selectors.
        'year_range' => '-0:+1',
        'input_format' => date_default_format('date_select'),
        'text_parts' => array(),
        'label_position' => 'above',
        'repeat_collapsed' => 0,
      ),
      'weight' => -4,
    ),
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'blank',
    ),
  );

  $instance['display'] = array(
    'default' => array(
      'label' => 'above',
      'type' => 'date_default',
      'settings' => array(
        'format_type' => 'long',
        'show_repeat_rule' => 'show',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'module' => 'date',
      'weight' => 0 ,
    ),
    'teaser' => array(
      'label' => 'above',
      'type' => 'date_default',
      'weight' => 0,
      'settings' => array(
        'format_type' => 'long',
        'show_repeat_rule' => 'show',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'module' => 'date',
    ),
  );
   field_delete_instance($instance);
}

// Programs
function _create_programs_fields() {
    if (!field_info_field('body')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(
                0 => 'node',
            ),
            'field_name' => 'body',
            'foreign keys' => array(
                'format' => array(
                    'columns' => array(
                        'format' => 'format',
                    ),
                    'table' => 'filter_format',
                ),
            ),
            'indexes' => array(
                'format' => array(
                    0 => 'format',
                ),
            ),
            'locked' => '0',
            'module' => 'text',
            'settings' => array(),
            'translatable' => '0',
            'type' => 'text_with_summary',
        );
        field_create_field($field);
    }
    if (!field_info_field('field_image')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_image',
            'foreign keys' => array(
                'fid' => array(
                    'columns' => array(
                        'fid' => 'fid',
                    ),
                    'table' => 'file_managed',
                ),
            ),
            'indexes' => array(
                'fid' => array(
                    0 => 'fid',
                ),
            ),
            'locked' => '0',
            'module' => 'image',
            'settings' => array(
                'default_image' => FALSE,
                'uri_scheme' => 'public',
            ),
            'translatable' => '0',
            'type' => 'image',
        );
        field_create_field($field);
    }
    if (!field_info_field('field_tags')) {
        $field = array(
            'active' => '1',
            'cardinality' => '-1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_tags',
            'foreign keys' => array(
                'tid' => array(
                    'columns' => array(
                        'tid' => 'tid',
                    ),
                    'table' => 'taxonomy_term_data',
                ),
            ),
            'indexes' => array(
                'tid' => array(
                    0 => 'tid',
                ),
            ),
            'locked' => '0',
            'module' => 'taxonomy',
            'settings' => array(
                'allowed_values' => array(
                    0 => array(
                        'vocabulary' => 'tags',
                        'parent' => 0,
                    ),
                ),
            ),
            'translatable' => '0',
            'type' => 'taxonomy_term_reference',
        );
        field_create_field($field);
    }
    if (!field_info_field('field_user_category')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_user_category',
            'foreign keys' => array(
                'tid' => array(
                    'columns' => array(
                        'tid' => 'tid',
                    ),
                    'table' => 'taxonomy_term_data',
                ),
            ),
            'indexes' => array(
                'tid' => array(
                    0 => 'tid',
                ),
            ),
            'locked' => '0',
            'module' => 'taxonomy',
            'settings' => array(
                'allowed_values' => array(
                    0 => array(
                        'vocabulary' => 'user_types',
                        'parent' => '0',
                    ),
                ),
            ),
            'translatable' => '0',
            'type' => 'taxonomy_term_reference',
        );
        field_create_field($field);
    }

    if (!field_info_field('field_event_types')) {
        $field = array(
            'active' => '1',
            'cardinality' => '1',
            'deleted' => '0',
            'entity_types' => array(),
            'field_name' => 'field_event_types',
            'foreign keys' => array(
                'tid' => array(
                    'columns' => array(
                        'tid' => 'tid',
                    ),
                    'table' => 'taxonomy_term_data',
                ),
            ),
            'indexes' => array(
                'tid' => array(
                    0 => 'tid',
                ),
            ),
            'locked' => '0',
            'module' => 'taxonomy',
            'settings' => array(
                'allowed_values' => array(
                    0 => array(
                        'vocabulary' => 'event_types',
                        'parent' => '0',
                    ),
                ),
            ),
            'translatable' => '0',
            'type' => 'taxonomy_term_reference',
        );
        field_create_field($field);
    }
}

function _delete_programs_fields() {
    field_delete_field('body');
    field_delete_field('field_image');
    field_delete_field('field_tags');
    field_delete_field('field_user_category');
}

function _programs_create_instances() {
    $instance = array(
        'bundle' => 'programs',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(),
                'type' => 'text_default',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(
                    'trim_length' => 600,
                ),
                'type' => 'text_summary_or_trimmed',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'body',
        'label' => 'Body',
        'required' => FALSE,
        'settings' => array(
            'display_summary' => TRUE,
            'text_processing' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'module' => 'text',
            'settings' => array(
                'rows' => 20,
                'summary_rows' => 5,
            ),
            'type' => 'text_textarea_with_summary',
            'weight' => '3',
        )
    );

    field_create_instance($instance);


    // user Category
    $instance = array(
        'bundle' => 'programs',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_user_category',
        'label' => 'Category',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'options',
            'settings' => array(),
            'type' => 'options_select',
            'weight' => '5',
        )
    );

    field_create_instance($instance);

    // Image
    $instance = array(
        'bundle' => 'programs',
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '1',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_image',
        'label' => 'Image',
        'required' => 0,
        'settings' => array(
            'alt_field' => 1,
            'default_image' => 0,
            'file_directory' => '',
            'file_extensions' => 'png gif jpg jpeg',
            'max_filesize' => '',
            'max_resolution' => '',
            'min_resolution' => '',
            'title_field' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'image',
            'settings' => array(
                'preview_image_style' => 'thumbnail',
                'progress_indicator' => 'throbber',
            ),
            'type' => 'image_image',
            'weight' => '1',
        )
    );

    field_create_instance($instance);


    // TAGS
    $instance = array(
        'bundle' => 'programs',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'taxonomy',
                'settings' => array(),
                'type' => 'taxonomy_term_reference_link',
                'weight' => '3',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_tags',
        'label' => 'Tags',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 0,
            'module' => 'options',
            'settings' => array(
                'autocomplete_path' => 'taxonomy/autocomplete',
                'size' => 60,
            ),
            'type' => 'taxonomy_autocomplete',
            'weight' => '4',
        )
    );

    field_create_instance($instance);
}

function _programs_delete_instances() {
    $instance = array(
        'bundle' => 'programs',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(),
                'type' => 'text_default',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'hidden',
                'module' => 'text',
                'settings' => array(
                    'trim_length' => 600,
                ),
                'type' => 'text_summary_or_trimmed',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'body',
        'label' => 'Body',
        'required' => FALSE,
        'settings' => array(
            'display_summary' => TRUE,
            'text_processing' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'module' => 'text',
            'settings' => array(
                'rows' => 20,
                'summary_rows' => 5,
            ),
            'type' => 'text_textarea_with_summary',
            'weight' => '3',
        )
    );

    field_delete_instance($instance);


    // user Category
    $instance = array(
        'bundle' => 'programs',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '2',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_user_category',
        'label' => 'Category',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'options',
            'settings' => array(),
            'type' => 'options_select',
            'weight' => '5',
        )
    );

    field_delete_instance($instance);
    // Image
    $instance = array(
        'bundle' => 'programs',
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => '1',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_image',
        'label' => 'Image',
        'required' => 0,
        'settings' => array(
            'alt_field' => 1,
            'default_image' => 0,
            'file_directory' => '',
            'file_extensions' => 'png gif jpg jpeg',
            'max_filesize' => '',
            'max_resolution' => '',
            'min_resolution' => '',
            'title_field' => 1,
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 1,
            'module' => 'image',
            'settings' => array(
                'preview_image_style' => 'thumbnail',
                'progress_indicator' => 'throbber',
            ),
            'type' => 'image_image',
            'weight' => '1',
        )
    );

    field_delete_instance($instance);


    // TAGS
    $instance = array(
        'bundle' => 'programs',
        'default_value' => NULL,
        'deleted' => '0',
        'description' => '',
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'module' => 'taxonomy',
                'settings' => array(),
                'type' => 'taxonomy_term_reference_link',
                'weight' => '3',
            ),
            'teaser' => array(
                'label' => 'above',
                'settings' => array(),
                'type' => 'hidden',
                'weight' => 0,
            ),
        ),
        'entity_type' => 'node',
        'field_name' => 'field_tags',
        'label' => 'Tags',
        'required' => 0,
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'widget' => array(
            'active' => 0,
            'module' => 'options',
            'settings' => array(
                'autocomplete_path' => 'taxonomy/autocomplete',
                'size' => 60,
            ),
            'type' => 'taxonomy_autocomplete',
            'weight' => '4',
        )
    );

    field_delete_instance($instance);
}

?>