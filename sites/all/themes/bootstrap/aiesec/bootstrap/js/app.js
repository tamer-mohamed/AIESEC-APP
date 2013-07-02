(function($) {

    $(document).delegate('#homeTabs a','click',function(e) {
        e.preventDefault();
        $(this).tab('show');
        
    })

}(jQuery));