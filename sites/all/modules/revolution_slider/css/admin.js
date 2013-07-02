jQuery(document).ready(function($) {
	
	jQuery.fn.exists = function(){ return this.length>0; }
    
	/* Slide Builder */
	if ($('.field-type-revolution-slider-layer').exists()) {
		
		/* Global Variables */
		var $image_src = $('#edit-field-image .image-widget span.file').find("a").attr("href");
			$subLayer = $('.field-type-revolution-slider-layer table.field-multiple-table tr.draggable:not(:last)');
			$last = $('.field-type-revolution-slider-layer table.field-multiple-table tr.draggable:last');
		    $current = 0;
			 
		$('.field-type-revolution-slider-slide').after('<div class="preview-bg" />');
		$('div.preview-bg').css('background-image', 'url('+$image_src+')').wrap('<div class="slide-builder" style="overflow: hidden;" />');

		/* Generate Preview Container/Image */
		var img = new Image();
			img.onload = function() {
			  console.log(this.width + 'x' + this.height);
			  $('.slide-builder').height(this.height).width($('.slide-builder').parent().width()).scrollLeft(($('.slide-builder').width())/3);
			  $('div.preview-bg').css('height', this.height).css('width', '960px').css('background-position', 'center');
			  if (this.width > $('slide-builder').parent().width()) {
				  // do this
			  }
			}
			img.src = $image_src;
			
		$last.hide();
		
		/* Build Sublayers in Preview */
		$subLayer.each(function() {
			var $x = $(this).find('input.edit-revolution_slider-fields-data-x').val(); /* data-x */
				$y = $(this).find('input.edit-revolution_slider-fields-data-y').val(); /* data-x */
				$i = $current++; /* index */
				$slideWrap = $('.slide-builder').find('div.preview-bg'); /* preview wrapper */
				$selected = $(this).find('select.edit-revolution_slider-fields-layer'); /* layer type */
				
				/* Find Values */
				$img = $(this).find('.form-managed-file span.file').find("a").attr("href"); /* img path */
				$h1 = $(this).find('.edit-revolution_slider-fields-h1-'+$i);
				
			$(this).find('input.edit-revolution_slider-fields-data-x').addClass('layer-x-'+$i+'-draggable');
			$(this).find('input.edit-revolution_slider-fields-data-y').addClass('layer-y-'+$i+'-draggable');
			$(this).find('select.edit-revolution_slider-fields-layer').addClass('select-'+$i+'-menu');
			$slideWrap.append('<div class="layer layer-'+$i+'-editor" style="left: '+$x+'px; top: '+$y+'px"></div>');
			
			/* Determine Preview Layer Type/Value */
			switch ($selected.val()) {
				case 'img':
				if ($img == undefined) {
					$('.layer-'+$i+'-editor').html('New Image');
				} else { 
					$('.layer-'+$i+'-editor').html('<img src="'+$img+'" />');
				}
				break;
				case 'div': $('.layer-'+$i+'-editor').html('div'); break;
				case 'h1': $('.layer-'+$i+'-editor').html('<h1>'+$h1.val()+'</h1>'); break;
				case 'h2': $('.layer-'+$i+'-editor').html('h2'); break;
				case 'h3': $('.layer-'+$i+'-editor').html('h3'); break;
				case 'h4': $('.layer-'+$i+'-editor').html('h4'); break;
				case 'h5': $('.layer-'+$i+'-editor').html('h5'); break;
				case 'h6': $('.layer-'+$i+'-editor').html('h6'); break;
				default: $('.layer-'+$i+'-editor').html('New Layer'); break;
			}
		
			var $index = $(this).index();
			
			$('.select-'+$index+'-menu').change(function() {
				$img = $(this).parents().eq(2).find('.form-managed-file span.file').find("a").attr("href"); /* img path */
				switch ($(this).val()) {
					case 'img': 
						if ($img == undefined) {
							$('.layer-'+$index+'-editor').html('New Image');
						} else { 
							$('.layer-'+$index+'-editor').html('<img src="'+$img+'" />');
						}; break;
					case 'div': $('.layer-'+$index+'-editor').html('div'); break;
					case 'h1': $('.layer-'+$index+'-editor').html('<h1>'+$h1.val()+'</h1>'); break;
					case 'h2': $('.layer-'+$index+'-editor').html('h2'); break;
					case 'h3': $('.layer-'+$index+'-editor').html('h3'); break;
					case 'h4': $('.layer-'+$index+'-editor').html('h4'); break;
					case 'h5': $('.layer-'+$index+'-editor').html('h5'); break;
					case 'h6': $('.layer-'+$index+'-editor').html('h6'); break;
					default: $('.layer-'+$index+'-editor').html('New Layer'); break;
				}
			});
			
			$('.layer-'+$index+'-editor').draggable({ 
				cursor: "crosshair",
				containment : "parent",
				stop: function(event,ui) {
			        var $wrapper = $slideWrap.offset();
			            $pos = ui.helper.offset();
			        $('.layer-x-'+$index+'-draggable').val($pos.left - $wrapper.left);
			        $('.layer-y-'+$index+'-draggable').val($pos.top - $wrapper.top);
			    }
			});
			
			$('input.layer-x-'+$index+'-draggable').keyup(function(){
		        $('.layer-'+$index+'-editor').css('left', $(this).val()+'px');
			});
			
			$('input.layer-y-'+$index+'-draggable').keyup(function(){
				$('.layer-'+$index+'-editor').css('top', $(this).val()+'px');
			});
			
			$h1.keyup(function(){
		        $('.layer-'+$index+'-editor').html('<h1>'+$(this).val()+'</h1>');
			});
		});
		
		/* Append new layers to preview upon layer creation */
		Drupal.behaviors.revolution_slider = {
			attach: function (context, settings) {
				$last.show();
				$last = $('.field-type-revolution-slider-layer table.field-multiple-table tr.draggable:last');
				$subLayer = $('.field-type-revolution-slider-layer table.field-multiple-table tr.draggable:not(:last)');
				$index = ($last.index() - 1);		
				$last.hide();
				
			    $('input.field-add-more-submit', context).once('revolution_slider', function () {
			    	$subLayer.each(function() {
						$i = $(this).index();
						$(this).find('input.edit-revolution_slider-fields-data-x').addClass('layer-x-'+$i+'-draggable');
						$(this).find('input.edit-revolution_slider-fields-data-y').addClass('layer-y-'+$i+'-draggable');
						$(this).find('select.edit-revolution_slider-fields-layer').addClass('select-'+$i+'-menu');			
						$slideWrap = $('.slide-builder').find('div.preview-bg'); /* preview wrapper */
						
						$h1 = $(this).find('.edit-revolution_slider-fields-h1-'+$i);
						
						var $index = $(this).index();
						
						$('.select-'+$index+'-menu').change(function() {
							/* Find Values */
							$img = $(this).parents().eq(2).find('.form-managed-file span.file').find("a").attr("href"); /* img path */
							$h1 = $(this).parents().eq(2).find('.edit-revolution_slider-fields-h1-'+$index);
							switch ($(this).val()) {
								case 'img': 
								if ($img !== undefined) {
									$('.layer-'+$index+'-editor').html('<img src="'+$img+'" />');
									} else { 
										$('.layer-'+$index+'-editor').html('New Image');
									}
								break;
								case 'div': $('.layer-'+$index+'-editor').html('div'); break;
								case 'h1': $('.layer-'+$index+'-editor').html('<h1>'+$h1.val()+'</h1>'); break;
								case 'h2': $('.layer-'+$index+'-editor').html('h2'); break;
								case 'h3': $('.layer-'+$index+'-editor').html('h3'); break;
								case 'h4': $('.layer-'+$index+'-editor').html('h4'); break;
								case 'h5': $('.layer-'+$index+'-editor').html('h5'); break;
								case 'h6': $('.layer-'+$index+'-editor').html('h6'); break;
								default: $('.layer-'+$index+'-editor').html('New Layer'); break;
							}
						});
						
						$('.layer-'+$index+'-editor').draggable({ 
							cursor: "crosshair",
							containment : "parent",
							stop: function(event,ui) {
						        var $wrapper = $slideWrap.offset();
						            $pos = ui.helper.offset();
						        $('.layer-x-'+$index+'-draggable').val($pos.left - $wrapper.left);
						        $('.layer-y-'+$index+'-draggable').val($pos.top - $wrapper.top);
						    }
						});
						
						$('input.layer-x-'+$index+'-draggable').keyup(function(){
					        $('.layer-'+$index+'-editor').css('left', $(this).val()+'px');
						});
						
						$('input.layer-y-'+$index+'-draggable').keyup(function(){
							$('.layer-'+$index+'-editor').css('top', $(this).val()+'px');
						});
						
						$h1.keyup(function(){
					        $('.layer-'+$index+'-editor').html('<h1>'+$(this).val()+'</h1>');
						});
					});
			    	
			    	$newLayer = $('div.preview-bg > .layer-'+$index+'-editor').exists();
			    	
			    	if ($newLayer == false) {
			    		console.log($newLayer);
			    		$slideWrap.append('<div class="layer layer-'+$index+'-editor">New Layer</div>');
			    	}
			    		

					$('.preview-bg > div.layer').each(function() {
						$('.layer-'+$index+'-editor').draggable({ 
							cursor: "crosshair",
							containment : "parent",
							stop: function(event,ui) {
						        var $wrapper = $slideWrap.offset();
						            $pos = ui.helper.offset();
						        $('.layer-x-'+$index+'-draggable').val($pos.left - $wrapper.left);
						        $('.layer-y-'+$index+'-draggable').val($pos.top - $wrapper.top);
						    }
						});	
					});		
					
			    });
			    
			    /* Check if Image has been removed or uploaded */
			    $preview_img = $('#edit-field-image .image-widget span.file').find("a").attr("href"); /* img path */
			    
			    $("#edit-field-image .image-widget input[type='submit']").once(function () {
					var newImage = new Image();
					newImage.onload = function() {
					  $('.slide-builder').height(this.height).width($('.slide-builder').parent().width()).scrollLeft(($('.slide-builder').width())/3);
					  $('div.preview-bg').css('height', this.height).css('width', '960px').css('background-position', 'center');
					}
					newImage.src = $preview_img;
					
			    	if ($preview_img == undefined) { 
			    		$('div.preview-bg').css('background-image', 'none');
			    		} else { 
			    		$('div.preview-bg').css('background-image', 'url('+$preview_img+')');
			    	}
			    });
			    
			    $subLayer.each(function() {
			    	$i = $(this).index();
					$img = $(this).find('.form-managed-file span.file').find("a").attr("href"); /* img path */
					$selected = $(this).find('select.edit-revolution_slider-fields-layer'); /* layer type */
					
				    $(".edit-revolution_slider-fields-image-"+$i+" > input[type='submit'], .edit-revolution_slider-fields-image-"+$i+" > input[type='submit']").once(function () {
				    	if (($img == undefined) && ($selected.val() == 'img')) {
				    		$('.layer-'+$i+'-editor').html('New Image');
				    		console.log($selected.val() + $i)
				    	} else if (($img !== undefined) && ($selected.val() == 'img')) {
				    		$('.layer-'+$i+'-editor').html('<img src="'+$img+'" />');
				    		console.log($selected.val() + $i)
				    	}
				    });
			    });  
			}
		};
	} /* EOF */

});