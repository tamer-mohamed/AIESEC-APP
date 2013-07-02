jQuery(document).ready(function($){
	
	$('#user-login.modal, #account-options').css({
		width: '320px',
		'margin-top': function () {
			return -($(this).height() / 2);
		},
		'margin-left': function () {
			return -($(this).width() / 2);
		}
	})

});
