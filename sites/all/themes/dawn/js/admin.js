jQuery(document).ready(function($){
	
	$('.vertical-tabs').before('<div class="branding">Boutique Framework 1.1</div>');
	$(".vertical-tab-button:eq(1)").addClass('general');
	$(".vertical-tab-button:eq(2)").addClass('background');
	$(".vertical-tab-button:eq(3)").addClass('typography');
	$(".vertical-tab-button:eq(4)").addClass('regions');
	$(".vertical-tab-button:eq(5)").addClass('header');
	
	/* THEME SETTINGS: BACKGROUND IMAGE */
	
	$('input:checked').parent().addClass('form-item-active');

	$('input:radio').click(function() {
		$('input:radio[name='+$(this).attr('name')+']').parent().removeClass('form-item-active');
        $(this).parent().addClass('form-item-active');
	});
	
	/* THEME SETTINGS: COLOR PICKER */
	$('#edit-highlight-color, #edit-background-color, #edit-header-background, #edit-footer-background, #edit-h1-color, #edit-h2-color, #edit-h3-color, #edit-h4-color, #edit-h5-color, #edit-h6-color, #edit-link-normal-color, #edit-link-hover-color, #edit-link-visited-color, #edit-link-active-color, #edit-base-color').ColorPicker({
			onSubmit: function(hsb, hex, rgb, el) {
				$(el).val(hex);
				$(el).ColorPickerHide();
			},
			onBeforeShow: function () {
				$(this).ColorPickerSetColor(this.value);
			}
		}).bind('keyup', function(){
			$(this).ColorPickerSetColor(this.value);
		});
	
//	$('#edit-highlight-color, #edit-background-color, #edit-header-background, #edit-footer-background, #edit-h1-color, #edit-h2-color, #edit-h3-color, #edit-h4-color, #edit-h5-color, #edit-h6-color, #edit-link-normal-color, #edit-link-hover-color, #edit-link-visited-color, #edit-link-active-color, #edit-base-color').each(function() {
//		$this = $(this);
//		$color = $(this).parent().find('.colorSelector');
//		$value = $this.parent().find('.colorSelector > div');
//		
//		$color.ColorPicker({
//			onSubmit: function(hsb, hex, rgb, el) {
//				$(el).ColorPickerHide();
//			},
//			onBeforeShow: function () {
//				$(this).ColorPickerSetColor($(this).parents().eq(1).find('input').val());
//			}
//		});
//	});

	$('.colorpicker_submit').text('Submit');
});
