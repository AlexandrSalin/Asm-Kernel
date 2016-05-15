%include 'inc/func.inc'
%include 'class/class_view.inc'

	fn_function class/view/to_front
		;inputs
		;r0 = view object
		;outputs
		;r0 = view object
		;trashes
		;r2

		;are we allready front ?
		ln_is_last r0 + view_node, r1
		if r1, !=, 0
			s_call view, add_front, {r0, [r0 + view_parent]}
			s_jmp view, dirty_all, {r0}
		endif
		vp_ret

	fn_function_end