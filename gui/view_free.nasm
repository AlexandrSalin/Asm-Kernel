%include 'inc/func.inc'
%include 'inc/list.inc'
%include 'inc/heap.inc'
%include 'inc/gui.inc'

	fn_function gui/view_free
		;inputs
		;r0 = view object
		;trashes
		;r0-r5

		;save view object
		vp_push r0

		;sub view from any parent
		fn_call gui/view_sub

		;free any child views
		vp_cpy [r4], r0
		loop_list_forwards r0 + GUI_VIEW_LIST, r1, r0
			vp_push r1
			fn_call gui/view_free
			vp_pop r1
		loop_end

		;free view object data
		vp_cpy [r4], r0
		vp_lea [r0 + GUI_VIEW_DIRTY_LIST], r1
		fn_bind gui/gui_statics, r5
		vp_lea [r5 + GUI_STATICS_PATCH_HEAP], r0
		fn_call gui/patch_list_free
		vp_lea [r0 + GUI_VIEW_TRANSPARENT_LIST], r1
		fn_call gui/patch_list_free

		;free view object
		vp_pop r1
		vp_lea [r5 + GUI_STATICS_VIEW_HEAP], r0
		hp_freecell r0, r1, r2
		vp_ret

	fn_function_end