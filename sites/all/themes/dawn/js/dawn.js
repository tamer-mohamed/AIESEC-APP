jQuery(document).ready(function($){

	jQuery.fn.exists = function(){ return this.length>0; }
	
	/* REMOVE IF JAVASCRIPT ENEABLED */
	
	$('body').removeClass('no-js');
	
	/* ADD BODY CLASS IF SAFARI */
	
	if (navigator.userAgent.indexOf('Safari') != -1 && navigator.userAgent.indexOf('Chrome') == -1) {
		$('body').addClass('safari');
	}
	
	/* RESPONSIVE MENU */
	
	$mobileNav = $('.mobile-navigation');
	$mainMenu = $('.main-menu');
	$clone = $mainMenu.clone().appendTo('.main-menu').removeAttr("id");
	$mobileMenu = $('.main-menu ul.menu').first().addClass('mobile-nav');
	
	$mobileNav.click(function(){
		$mainMenu.slideToggle('fast').addClass('mobile');
		$mobileNav.toggleClass('open');
	});
	
	$(window).resize(function() {
	    if (($(window).width() > 767) && ($mobileNav.not('.open'))) {
	    	$mainMenu.show();
	    } else if (!($mobileNav.is('.open'))) {
	    	$mainMenu.hide();
	    };
	});
	
	/* DROPDOWN MENU HOVER STATES */
	
	$('.main-menu > ul > li, .main-menu > ul > li > ul > li').each(function() {
		$(this).hover( function () {
			$(this).children('ul').delay(200).stop( true, true).slideDown({duration: 300});
		}, function () {
			$(this).stop( true, true).children('ul').hide({duration: 0});
		});	
	});
	
	/* JQUERY ISOTOPE */

	if ($('#isotope-container').exists()) {
		var $container = $('#isotope-container');
		$container.isotope({
			itemSelector: '.isotope-element',
			getSortData : {
			name: function ($elem) {
				        return $elem.find(".name").text();
				    },
	          date: function ($elem) {
			        return $elem.find('.portfolio-item').attr('data-date');
			    }
		      }
		});

		var $optionSets = $('#isotope-options .option-set, #sort-by, #sort-direction'),
		$optionLinks = $optionSets.find('a');
	
		$optionSets.each(function() {
			$optionLinks.click(function(){
		
				var $this = $(this);
				// don't proceed if already active
				if ( $this.hasClass('active') ) {
					return false;
				}
				var $optionSet = $this.parents('.option-set');
				$optionSet.find('.active').removeClass('active');
				$this.parent().addClass('active');
		
				var options = {},
				key = $optionSet.attr('data-option-key'),
				value = $this.attr('data-option-value');
				// parse 'false' as false boolean
				value = value === 'false' ? false : value;
				options[ key ] = value;
				if ( key === 'layoutMode' && typeof changeLayoutMode === 'function' ) {
					// changes in layout modes need extra logic
					changeLayoutMode( $this, options )
				} else {
					// otherwise, apply new options
					$container.isotope( options );
				}
		
				return false;
			});
		})
	}
	
	$('#user-login.modal, #account-options').css({
        width: 'auto',
        'margin-top': function () {
            return -($(this).height() / 2);
        },
		'margin-left': function () {
			return -($(this).width() / 2);
		}
    });
            
	/* RETURN TO TOP */
	
	$(window).scroll(function () {
			if ($(this).scrollTop() >= 150) {
				$('#toTop').fadeIn();
			} else {
				$('#toTop').fadeOut();
			}
	});
	
	$('#toTop a').click(function(){
		$('html, body').animate({scrollTop:0}, 300);
		return false;
	});
	
	
	/* ACCORDION ACTIVE STATES */
		
	$('.snippet').click(function() {
		$(this).toggleClass('open');
	});
	
	$('.accordion .in').prev().addClass('active');
	
	$('.accordion-heading a').click(function() {
		$('.accordion-heading').removeClass('active');
        $(this).parent().addClass('active');
	});
	
	/* GOOGLE MAPS */
    
	if ($('.map').exists()) {
		var container = $(".map");
	
		if (container.length == 0){ return; } 
	
		var mapInner = $('.map');	
	
		var coordinate = new google.maps.LatLng(container.data("lat"), container.data("lon"));
	
		var mapOptions = {
				center: coordinate,
				zoom: 15,
				mapTypeId: google.maps.MapTypeId.ROADMAP,
				mapTypeControl: false
		};
		
		var map = new google.maps.Map(mapInner.get(0), mapOptions);
		
		var myMarker = new google.maps.Marker({
	        position: coordinate,
	        map: map,
	    });
	}

	/* SIMPLENEWS CAPTCHA */
	
	if ($('#footer .block-simplenews').exists() && $('body.not-logged-in').exists()) {
		$('#footer .block-simplenews > p').append('<form id="newsletter"><input type="text" class="newsletter" name="mail" value="" size="20" maxlength="128" class="form-text required"><input type="submit" value="Go" /></form>');
		$('#footer .simplenews-subscribe').wrap('<div id="simplenews-wrap" class="modal hide fade" />');
		$('#footer #simplenews-wrap span.fieldset-legend').unwrap().addClass('modal-header').prepend('<button type="button" class="close" data-dismiss="modal" aria-hidden="true">×</button>');
		$('#footer input.newsletter').attr("placeholder", "Enter Your E-mail Address");
		$('#simplenews-wrap .btn').wrap('<div class="modal-footer" />');
		
		$('#footer #simplenews-wrap').css({
	        'margin-top': function () {
	            return -($(this).height() / 2);
	        },
			'margin-left': function () {
				return -($(this).width() / 2);
			}
	    });
		
		$('#footer .newsletter').keyup(function(){
			$('#edit-mail').val($(this).val());
		});
		
		$('#newsletter').submit(function(e){
			e.preventDefault();
			$('#simplenews-wrap').modal('toggle');
			return false;
		})
	}
	
	if ($('#footer .block-simplenews').exists() && $('body.logged-in').exists()) {
		$('#footer .block-simplenews .btn').addClass('btn-small');
	}
	
	/* TWITTER FEED */
	$account = $('div.tweet').attr('data-twitter');
		
    jQuery(".tweet").tweet({
        username: $account,
        modpath: Drupal.settings.basePath+'/sites/all/themes/dawn/js/plugins/twitter/',
        join_text: "auto",
        avatar_size: 16,
        count: 2,
        auto_join_text_default: "", 
        auto_join_text_ed: "",
        auto_join_text_ing: "",
        auto_join_text_reply: "",
        auto_join_text_url: "",
        loading_text: "Loading tweets..."
    });


});
