%include 'class/class_ref.inc'

	fn_function class/ref/deref
		;inputs
		;r0 = object
		;trashes
		;r1

		;dec ref count
		vp_cpy [r0 + ref_count], r1
		vp_dec r1
		vp_cpy r1, [r0 + ref_count]

		;destroy if 0
		if r1, ==, 0
			method_call ref, destroy
		endif
		vp_ret

	fn_function_end