%include 'class/class_obj.inc'

	fn_function class/obj/deinit
		;inputs
		;r0 = object

		vp_cpy 0, qword[r0 + obj_vtable]
		vp_ret

	fn_function_end