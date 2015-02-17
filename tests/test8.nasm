%include "func.inc"
%include "task.inc"

;;;;;;;;;;;
; test code
;;;;;;;;;;;

	fn_function "tests/test8"
		;array task started by test7

		;read exit command etc
		vp_lea [r15 + TK_NODE_MAILBOX], r0
		fn_call sys/mail_read
		fn_call sys/mail_free

		;wait a bit
		vp_cpy 2000000, r0
		fn_call sys/math_random
		vp_add 6000000, r0
		fn_call sys/task_sleep

		;print Hello
		vp_lea [rel hello], r0
		vp_cpy 1, r1
		fn_call sys/write_string

		;stop this task
		fn_jmp sys/task_stop

	hello:
		db "Hello from array worker !", 10, 0

	fn_function_end