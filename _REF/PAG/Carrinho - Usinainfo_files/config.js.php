
function ColorEv (i,j,type)
{
		$("#" + i).ColorPicker({
			color: "#0000ff",
			onShow: function (colpkr) {
				$(colpkr).fadeIn(500);
				return false;
			},
			onHide: function (colpkr) {
				$(colpkr).fadeOut(500);
				return false;
			},
			onChange: function (hsb, hex, rgb) {
				$("#" + i).css("background", "#" + hex); //custom event change
				$.cookie("" + i + "", "#" + hex);
				$("" + j + "").css("" + type + "","" + $.cookie(i) + "");
			}
		});
			if ($.cookie("" + i + "") != null)
			{
				$("#" + i + "").css("background","" + $.cookie(i) + "");
				$("" + j + "").css("" + type + "","" + $.cookie(i) + "");
			}
}
$(document).ready(function() {
			$('select[name=setting_column] option[value=2_column_left]').attr('selected', 'selected');
			$('div.2_column_left').show();
			$('input[value="grid_6,grid_18(3)"]').attr('checked', 'checked');ColorEv("page_color","#page","background");ColorEv("text_page_color_text","body, input, select, textarea, .product_desc, .compare label, .category-product-count, ul.pagination .current span, #block_contact_infos li  pre, .breadcrumb a, .price.unit, #buy_block p#pQuantityAvailable, #cart_block #cart-prices span.ajax_cart_shipping_cost","color");loadGoogleFont("text_page_fstyle","body, input, select, textarea, .product_desc, .compare label, .category-product-count, ul.pagination .current span, #block_contact_infos li  pre, .breadcrumb a, .price.unit, #buy_block p#pQuantityAvailable, #cart_block #cart-prices span.ajax_cart_shipping_cost");ColorEv("link_page_normal_color_text","a, a:active, a:visited, .box1 .title a:hover, #usefull_link_block li, #more_info_tabs .idTabs a, .title_hide_show","color");ColorEv("header_color",".mode_header","background");ColorEv("header_color_bg",".header_content_menu","background");ColorEv("footer_color",".mode_footer","background");ColorEv("title_footer_color_text","#footer .title_block, #footer .title_block a, .show_hide_footer","color");loadGoogleFont("title_footer_fstyle","#footer .title_block, #footer .title_block a, .show_hide_footer");loadGoogleFontFromConfig("title_footer_fstyle","Open Sans");
							loadGoogleFontFromConfig("bg_title_menu_fstyle","Open Sans");
							ColorEv("txt_name_product_color_text",".name_product a, #pb-left-column h1, #pb-left-column h1 a, #new_comment_form .product .product_desc .product_name, .title_post a, .pltitle, .post_name h3 a, #plpost h2","color");loadGoogleFont("name_product_fstyle",".name_product a, .title_post a, .pltitle, .post_name h3 a");loadGoogleFontFromConfig("button_default_fstyle","Roboto");
							loadGoogleFontFromConfig("title_h1_fstyle","Roboto");
							loadGoogleFontFromConfig("title_h2_fstyle","Open Sans");
							loadGoogleFontFromConfig("title_h1_fstyle","Roboto");
							});