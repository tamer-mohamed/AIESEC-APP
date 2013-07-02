<?php

/**
 * @file
 * dawn_tools.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function aiesec_app_tools_taxonomy_default_vocabularies() {
    return array(
        'user_types' => array(
            'name' => 'User Types',
            'machine_name' => 'user_types',
            'description' => '',
            'hierarchy' => '0',
            'module' => 'taxonomy',
            'weight' => '0',
            'rdf_mapping' => array(
                'rdftype' => array(
                    0 => 'skos:ConceptScheme',
                ),
                'name' => array(
                    'predicates' => array(
                        0 => 'dc:title',
                    ),
                ),
                'description' => array(
                    'predicates' => array(
                        0 => 'rdfs:comment',
                    ),
                ),
            ),
        ),
        'tags' => array(
            'name' => 'Tags',
            'machine_name' => 'tags',
            'description' => 'Use tags to group articles on similar topics into categories.',
            'hierarchy' => '0',
            'module' => 'taxonomy',
            'weight' => '0',
            'rdf_mapping' => array(
                'rdftype' => array(
                    0 => 'skos:ConceptScheme',
                ),
                'name' => array(
                    'predicates' => array(
                        0 => 'dc:title',
                    ),
                ),
                'description' => array(
                    'predicates' => array(
                        0 => 'rdfs:comment',
                    ),
                ),
            ),
        ),
    );
}


function _aiesec_app_tools_delete_user_types_terms() {
    taxonomy_term_delete(reset(taxonomy_get_term_by_name('Student'))->tid);
    taxonomy_term_delete(reset(taxonomy_get_term_by_name('Company'))->tid);
    taxonomy_term_delete(reset(taxonomy_get_term_by_name('Alumni'))->tid);
}
