jQuery(document).ready(function() {
    jQuery('#myTab a').click(function(e) {
        e.preventDefault();
        jQuery(this).tab('show');
    });
})

