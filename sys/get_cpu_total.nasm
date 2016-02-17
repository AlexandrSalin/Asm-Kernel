%include "func.inc"
%include "task.inc"

	fn_function "sys/get_cpu_total"
		;outputs
		;r0 = cpu total

		fn_bind sys/task_statics, r0
		vp_cpy [r0 + TK_STATICS_CPU_TOTAL], r0
		vp_ret

	fn_function_end