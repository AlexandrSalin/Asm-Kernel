(import 'inc/class.inc)
(import 'inc/code.inc)
(import 'inc/list.inc)
(import 'inc/heap.inc)

;;;;;;;;;;;;;;;;;;;
; mail static class
;;;;;;;;;;;;;;;;;;;

(def-class 'sys_mail)
(def-method 'statics 'sys/mail_statics)
(def-method 'init 'sys/mail_init)
(def-method 'deinit 'sys/mail_deinit)
(def-method 'alloc 'sys/mail_alloc 'static '() '(r0))
(def-method 'alloc_parcel 'sys/mail_alloc_parcel 'static '(r0) '(r0))
(def-method 'send 'sys/mail_send 'static '(r0))
(def-method 'read 'sys/mail_read 'static '(r0) '(r0))
(def-method 'try_read 'sys/mail_try_read 'static '(r0) '(r0))
(def-method 'select 'sys/mail_select 'static '(r0 r1) '(r0))
(def-method 'mymail 'sys/mail_mymail 'static '() '(r0))
(def-method 'init_mailbox 'sys/mail_init_mailbox 'static '(r0))
(def-method 'in 'sys/mail_in)
(def-method 'out 'sys/mail_out)

;;;;;;;;;;;;;;;;;
; mail structures
;;;;;;;;;;;;;;;;;

(defcvar 'mail_data_size 512)

(def-struct 'mailbox 'lh_list)
	(struct 'mailbox_parcel_list 'lh_list)
	(ptr 'mailbox_tcb)
(def-struct-end)

(def-struct 'id)
	(ulong 'id_mbox)
	(ulong 'id_cpu)
(def-struct-end)

(def-struct 'msg 'ln_node)
	(ulong 'msg_length)
	(struct 'msg_dest 'id)
	(struct 'msg_parcel_id 'id)
	(ulong 'msg_parcel_size)
	(ulong 'msg_parcel_total)
	(ulong 'msg_parcel_frag)
	(offset 'msg_header_size)
	(struct 'msg_data 'mail_data)
(def-struct-end)

(def-struct 'ml_statics)
	(struct 'ml_statics_offchip_list 'lh_list)
	(struct 'ml_statics_heap 'hp_heap)
	(ptr 'ml_statics_kernel_mailbox)
	(ptr 'ml_statics_in_mailbox)
	(ptr 'ml_statics_out_mailbox)
	(ulong 'ml_statics_parcel_id)
(def-struct-end)

;;;;;;;;;;;;;
; mail macros
;;;;;;;;;;;;;

(defcfun ml-init (%1 %2 %3)
	;inputs
	;%1 = mailbox
	;%2 = temp
	;%3 = temp
	;outputs
	;%1 = mailbox
	;trashes
	;%2, %3

	(vp-xor-rr %2 %2)
	(vp-cpy-ri %2 %1 mailbox_tcb)
	(lh-init %1 %2)
	(vp-lea-i %1 mailbox_parcel_list %2)
	(lh-init %2 %3))

(defcfun ml-temp-create (%1 %2)
	;inputs
	;%1 = temp
	;%2 = temp
	;outputs
	;r4 = mailbox
	;trashes
	;%1, %2

	(vp-sub-cr mailbox_size r4)
	(ml-init r4 %1 %2))

(defcfun ml-temp-destroy ()
	(vp-add-cr mailbox_size r4))
