%include 'inc/func.inc'
%include 'class/class_vector.inc'
%include 'cmd/lisp/class_lisp.inc'

	def_function cmd/lisp/func_quote
		;inputs
		;r0 = lisp object
		;r1 = args
		;outputs
		;r0 = lisp object
		;r1 = 0, else value

		ptr this, args
		ulong length

		push_scope
		retire {r0, r1}, {this, args}

		static_call vector, get_length, {args}, {length}
		if {length != 1}
			static_call lisp, error, {this, "(quote arg) wrong numbers of args"}
			assign {0}, {args}
		else
			static_call vector, ref_element, {args, 0}, {args}
		endif

		eval {this, args}, {r0, r1}
		pop_scope
		return

	def_function_end