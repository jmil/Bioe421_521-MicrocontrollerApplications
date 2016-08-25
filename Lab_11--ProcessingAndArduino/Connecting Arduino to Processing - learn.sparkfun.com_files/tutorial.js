// Tutorials plugin
(function( $ ){

  var methods = {
    init: function( options ) {
      var self = this;

      if($('.tutorial-page pre').is('*')) {
        $(self).tutorial('rainbow');
      }

      if($('#sections').is('*')) {
        $(self).tutorial('init_all');
      }

      if(window.location.hash) {
        require([
          'jqueryui',
        ], function() {
          var hash = window.location.hash.substring(1);
          if($('#' + hash).length)
            $('#' + hash).closest('.section').effect('highlight', {}, 2000);
        });
      }
    },

    rainbow: function() {
      // syntax highlighting
      require([
        'rainbow',
      ], function() {
        require([
          'generic',
          'c',
        ], function() {
          // set up the coloring params and throw in a hidden div with the code for copying
          $('.tutorial-page pre').each(function(i, el) {
            var content = $(el).html();
            var code = $(el).find('code').html();
            var lang = code.match(/^language:([a-zA-Z]+\n)/);

            // if we have a language, set up rainbowjs
            if(lang) {
              var lines = code.split('\n');
              lines.splice(0,1);
              code = lines.join('\n');
              $(el).html(code).wrapInner('<code />').attr('data-language', lang);
            }

            // add a copy button
            $(el).after($('<div>').attr('id', 'code-'+i).html(code).addClass('hide'));
            $(el).prepend($('<div>').attr('data-code-id', 'code-'+i).html('<button class="btn btn-default btn-sm">Copy Code</button>').addClass('copy-code'));
          });

          // do the coloring
          Rainbow.color();

          // link each copy button
          // fucking flash, man.
          require(['ZeroClipboard.min'], function (ZeroClipboard) {
            ZeroClipboard.config( { moviePath: '/js/ZeroClipboard.swf' } );

            var client = new ZeroClipboard($('.copy-code'));

            client.on('load', function(client) {
              client.on('datarequested', function(client) {
                client.setText($('#' + $(this).attr('data-code-id')).text());
              });
              client.on('complete', function(client, args) {
                $(this).find('button').html('Copied!').effect('highlight');
              });
            });
          });
        });
      });
    },

    init_all: function() {
      var self = this;
      var sidebar_affix = $('#sidebar_affix');

      sidebar_affix.affix({
        offset: {
          top: function () {
            return (this.top = sidebar_affix.offset().top + sidebar_affix.outerHeight(true))
          }
        , bottom: function () {
            return (this.bottom = $('footer').outerHeight(true))
          }
        }
      })

      // if we're "view-all"ing
      didScroll = true;
      $(window).scroll(function() {
        didScroll = true;
      });

      setInterval(function() {
        if(didScroll) {
          didScroll = false;
          var pos = $(window).scrollTop();
          $('#tutorial').tutorial('scrolled', pos);
        }
      }, 100);

      $('#tutorial').imagesLoaded(function() {
        offsets = {};
        $('#sections .section').each(function() {
          offsets[$(this).offset().top - 10] = $(this).find('h2').attr('id');
        });
        $(self).data('offsets', offsets);
      })
    },

    scrolled: function(pos) {
      var hilite = '';
      $.each($(this).data('offsets'), function(k, v) {
        if(pos > k) {
          hilite = v;
        }
      });
      $('#tutorial-pages .list-group-item').removeClass('active');
      $('#tutorial-pages .list-group-item[data-pagename="'+ hilite +'"]').addClass('active');
    }

  };

  $.fn.tutorial = function( method ) {
    if ( methods[method] ) {
      return methods[ method ].apply( this, Array.prototype.slice.call( arguments, 1 ));
    } else if ( typeof method === 'object' || ! method ) {
      return methods.init.apply( this, arguments );
    } else {
      $.error( 'Method ' +  method + ' does not exist on jQuery.learn' );
    }
  };

})( jQuery );
