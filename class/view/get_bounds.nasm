%include 'inc/func.inc'
%include 'class/class_view.inc'

	fn_function class/view/get_bounds
		;inputs
		;r0 = view object
		;outputs
		;r0 = view object
		;r8 = x
		;r9 = y
		;r10 = width
		;r11 = height

		vp_cpy [r0 + view_x], r8
		vp_cpy [r0 + view_y], r9
		vp_cpy [r0 + view_w], r10
		vp_cpy [r0 + view_h], r11
		vp_ret

	fn_function_end