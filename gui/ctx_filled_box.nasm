%include 'inc/func.inc'
%include 'inc/sdl2.inc'

	struc FBOX
		FBOX_RECT:			resb sdl_rect_size
		FBOX_CLIP_RECT:		resb sdl_rect_size
		FBOX_CTX:			resq 1
		FBOX_PATCH:			resq 1
		FBOX_OLD_STACK:		resq 1
		FBOX_SIZE:
	endstruc

	fn_function gui/ctx_filled_box
		;inputs
		;r0 = ctx
		;r8 = x
		;r9 = y
		;r10 = width
		;r11 = height
		;trashes
		;r0-r3, r5-r15

		vp_cpy r4, r1
		vp_sub FBOX_SIZE, r4
		vp_and -16, r4
		vp_cpy r1, [r4 + FBOX_OLD_STACK]

		;save draw rectangle info
		vp_cpy r0, [r4 + FBOX_CTX]
		vp_add [r0 + GUI_CTX_X], r8
		vp_add [r0 + GUI_CTX_Y], r9
		vp_cpy r8d, [r4 + FBOX_RECT + sdl_rect_x]
		vp_cpy r9d, [r4 + FBOX_RECT + sdl_rect_y]
		vp_cpy r10d, [r4 + FBOX_RECT + sdl_rect_w]
		vp_cpy r11d, [r4 + FBOX_RECT + sdl_rect_h]

		;for each patch on the dirty list
		vp_cpy [r0 + GUI_CTX_DIRTY_REGION], r0
		loop_start
			vp_cpy [r0 + GUI_PATCH_NEXT], r0
			breakif r0, ==, 0
			vp_cpy r0, [r4 + FBOX_PATCH]

			;set clip region to this patch
			vp_cpy [r0 + GUI_PATCH_X], r8
			vp_cpy [r0 + GUI_PATCH_Y], r9
			vp_cpy [r0 + GUI_PATCH_X1], r10
			vp_cpy [r0 + GUI_PATCH_Y1], r11
			vp_sub r8, r10
			vp_sub r9, r11
			vp_cpy r8d, [r4 + FBOX_CLIP_RECT + sdl_rect_x]
			vp_cpy r9d, [r4 + FBOX_CLIP_RECT + sdl_rect_y]
			vp_cpy r10d, [r4 + FBOX_CLIP_RECT + sdl_rect_w]
			vp_cpy r11d, [r4 + FBOX_CLIP_RECT + sdl_rect_h]
			vp_cpy [r4 + FBOX_CTX], r0
			vp_lea [r4 + FBOX_CLIP_RECT], r1
			sdl_rendersetcliprect [r0+ GUI_CTX_SDL_CTX], r1

			;draw the rectangle
			vp_cpy [r4 + FBOX_CTX], r0
			vp_lea [r4 + FBOX_RECT], r1
			sdl_renderfillrect [r0+ GUI_CTX_SDL_CTX], r1

			vp_cpy [r4 + FBOX_PATCH], r0
		loop_end

		vp_cpy [r4 + FBOX_OLD_STACK], r4
		vp_ret

	fn_function_end