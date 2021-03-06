(import 'class/class_component.inc)

(def-class 'view 'component)
(def-method 'create 'class/view/create)
(def-method 'new 'class/view/new)
(def-method 'init 'class/view/init)
(def-method 'add_front 'class/view/add_front 'static '(r0 r1))
(def-method 'add_back 'class/view/add_back 'static '(r0 r1))
(def-method 'sub 'class/view/sub 'static '(r0))
(def-method 'to_front 'class/view/to_front 'static '(r0))
(def-method 'add_dirty 'class/view/add_dirty 'static '(r0 r8 r9 r10 r11))
(def-method 'add_opaque 'class/view/add_opaque 'static '(r0 r8 r9 r10 r11))
(def-method 'sub_opaque 'class/view/sub_opaque 'static '(r0 r8 r9 r10 r11))
(def-method 'get_relative 'class/view/get_relative 'static '(r0 r1 r8 r9) '(r8 r9))
(def-method 'dirty 'class/view/dirty 'static '(r0))
(def-method 'dirty_all 'class/view/dirty_all 'static '(r0))
(def-method 'opaque 'class/view/opaque 'static '(r0))
(def-method 'forward 'class/view/forward 'static '(r0 r1 r2))
(def-method 'backward 'class/view/backward 'static '(r0 r1 r2))
(def-method 'forward_tree 'class/view/forward_tree 'static '(r0 r1 r2 r3))
(def-method 'backward_tree 'class/view/backward_tree 'static '(r0 r1 r2 r3))
(def-method 'change 'class/view/change 'static '(r0 r8 r9 r10 r11))
(def-method 'hit_tree 'class/view/hit_tree 'static '(r0 r8 r9) '(r1 r8 r9))
(def-method 'set_owner 'class/view/set_owner 'static '(r0 r1))
(def-method 'find_owner 'class/view/find_owner 'static '(r0) '(r1))
(def-method 'draw_panel 'class/view/draw_panel 'static '(r0 r1 r2 r3))
(def-method 'set_color 'class/view/set_color 'static '(r0 r1))
(def-method 'get_color 'class/view/get_color 'static '(r0) '(r1))
(def-method 'get_bounds 'class/view/get_bounds 'static '(r0) '(r8 r9 r10 r11))
(def-method 'set_bounds 'class/view/set_bounds 'static '(r0 r8 r9 r10 r11))
(def-method 'set_flags 'class/view/set_flags 'static '(r0 r1))
(def-method 'get_parent 'class/view/get_parent 'static '(r0) '(r1))
(def-method 'get_first 'class/view/get_first 'static '(r0) '(r1))
(def-method 'get_last 'class/view/get_last 'static '(r0) '(r1))

(def-method 'deinit 'class/view/deinit 'override)

(def-method 'draw 'class/obj/null 'virtual '(r0 r1))
(def-method 'hit 'class/view/hit 'virtual '(r0 r8 r9) '(r1))
(def-method 'pref_size 'class/view/pref_size 'virtual '(r0) '(r10 r11))
(def-method 'layout 'class/obj/null 'virtual '(r0))
(def-method 'event 'class/view/event 'virtual '(r0 r1))
(def-method 'mouse_down 'class/obj/null 'virtual '(r0 r1))
(def-method 'mouse_up 'class/obj/null 'virtual '(r0 r1))
(def-method 'mouse_move 'class/obj/null 'virtual '(r0 r1))
(def-method 'mouse_hover 'class/obj/null 'virtual '(r0 r1))
(def-method 'key_down 'class/obj/null 'virtual '(r0 r1))
(def-method 'key_up 'class/obj/null 'virtual '(r0 r1))

(def-bit)
	(bit 'view_flag_solid)
(def-bit-end)

(def-struct 'view 'component)
	(struct 'view_node 'ln_node)
	(struct 'view_list 'lh_list)
	(ptr 'view_parent)
	(ptr 'view_tcb)
	(ptr 'view_dirty_region)
	(ptr 'view_opaque_region)
	(ptr 'view_ctx_node)
	(long 'view_ctx_x)
	(long 'view_ctx_y)
	(long 'view_x)
	(long 'view_y)
	(long 'view_w)
	(long 'view_h)
	(ulong 'view_last_buttons)
	(ulong 'view_flags)
	(ulong 'view_color)
(def-struct-end)
