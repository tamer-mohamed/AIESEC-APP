Drupal.behaviors.lc_managepage = {
    attach: function(context, settings) {
        if (context.selector !== undefined) {
            jQuery('.pager a').once('pager', function() {

                jQuery('.pager a', context).addClass('use-ajax');
                Drupal.attachBehaviors(jQuery('.pager a'));
            })
        }
    }
}
jQuery(document).ready(function() {
    jQuery('#myTab a').click(function(e) {
        jQuery(this).tab('show');
    });
    if (document.location.search.length) {
        jQuery('a[href="#news"]').tab('show');
    }
    var hash = window.location.hash;
    hash = hash.replace('=', '');

    if (window.location.hash) {
        jQuery('a[href="' + window.location.hash + '"]').tab('show');
    }


})

