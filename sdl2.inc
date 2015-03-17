%ifndef SDL2_1234
    %define SDL2_1234

%include "vp.inc"
%include "code.inc"
%include "gui.inc"

;;;;;;;;;;;;;;;;;
; sdl2 structures
;;;;;;;;;;;;;;;;;

	extern _SDL_SetMainReady
	extern _SDL_Init
	extern _SDL_Quit
	extern _SDL_CreateWindow
	extern _SDL_CreateWindowAndRenderer
	extern _SDL_DestroyWindow
	extern _SDL_Delay
	extern _SDL_CreateRenderer

	SDL_SETMAINREADY			equ 0
	SDL_INIT					equ 1
	SDL_QUIT					equ 2
	SDL_CREATEWINDOW			equ 3
	SDL_CREATEWINDOWANDRENDERER	equ 4
	SDL_DESTROYWINDOW			equ 5
	SDL_DELAY					equ 6
	SDL_CREATERENDERER			equ 7

	SDL_INIT_TIMER			equ 0x00000001
	SDL_INIT_AUDIO			equ 0x00000010
	SDL_INIT_VIDEO			equ 0x00000020
	SDL_INIT_JOYSTICK		equ 0x00000200
	SDL_INIT_HAPTIC			equ 0x00001000
	SDL_INIT_GAMECONTROLLER	equ 0x00002000
	SDL_INIT_EVENTS			equ 0x00004000
	SDL_INIT_NOPARACHUTE	equ 0x00100000
	SDL_INIT_EVERYTHING		equ SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS | \
								SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMECONTROLLER

	SDL_WINDOW_FULLSCREEN			equ 0x00000001
	SDL_WINDOW_OPENGL				equ 0x00000002
	SDL_WINDOW_SHOWN				equ 0x00000004
	SDL_WINDOW_HIDDEN				equ 0x00000008
	SDL_WINDOW_BORDERLESS			equ 0x00000010
	SDL_WINDOW_RESIZABLE			equ 0x00000020
	SDL_WINDOW_MINIMIZED			equ 0x00000040
	SDL_WINDOW_MAXIMIZED			equ 0x00000080
	SDL_WINDOW_INPUT_GRABBED		equ 0x00000100
	SDL_WINDOW_INPUT_FOCUS			equ 0x00000200
	SDL_WINDOW_MOUSE_FOCUS			equ 0x00000400
	SDL_WINDOW_FULLSCREEN_DESKTOP	equ SDL_WINDOW_FULLSCREEN | 0x00001000
	SDL_WINDOW_FOREIGN				equ 0x00000800
	SDL_WINDOW_ALLOW_HIGHDPI		equ 0x00002000

	SDL_WINDOWPOS_UNDEFINED_MASK				equ 0x1FFF0000
	%define	SDL_WINDOWPOS_UNDEFINED_DISPLAY(X)	(SDL_WINDOWPOS_UNDEFINED_MASK|(X))
	%define	SDL_WINDOWPOS_UNDEFINED				SDL_WINDOWPOS_UNDEFINED_DISPLAY(0)
	%define	SDL_WINDOWPOS_ISUNDEFINED(X)		(((X)&0xFFFF0000) == SDL_WINDOWPOS_UNDEFINED_MASK)

	SDL_WINDOWPOS_CENTERED_MASK					equ 0x2FFF0000
	%define	SDL_WINDOWPOS_CENTERED_DISPLAY(X)	(SDL_WINDOWPOS_CENTERED_MASK|(X))
	%define	SDL_WINDOWPOS_CENTERED				SDL_WINDOWPOS_CENTERED_DISPLAY(0)
	%define	SDL_WINDOWPOS_ISCENTERED(X)			(((X)&0xFFFF0000) == SDL_WINDOWPOS_CENTERED_MASK)

	SDL_RENDERER_SOFTWARE		equ 0x00000001
	SDL_RENDERER_ACCELERATED	equ 0x00000002
	SDL_RENDERER_PRESENTVSYNC	equ 0x00000004
	SDL_RENDERER_TARGETTEXTURE	equ 0x00000008

;;;;;;;;;;;;;
; sdl2 macros
;;;;;;;;;;;;;

	%macro sdl_setmainready 0
		fn_bind sys/gui_statics, r0
		vp_cpy [r0 + GUI_STATICS_SDL_FUNCS], r0
		vp_call [r0 + (SDL_SETMAINREADY * 8)]
	%endmacro

	%macro sdl_init 1
		;flags
		vp_cpy %1, r7
		fn_bind sys/gui_statics, r0
		vp_cpy [r0 + GUI_STATICS_SDL_FUNCS], r0
		vp_call [r0 + (SDL_INIT * 8)]
	%endmacro

	%macro sdl_delay 1
		;time
		vp_cpy %1, r7
		fn_bind sys/gui_statics, r0
		vp_cpy [r0 + GUI_STATICS_SDL_FUNCS], r0
		vp_call [r0 + (SDL_DELAY * 8)]
	%endmacro

	%macro sdl_quit 0
		fn_bind sys/gui_statics, r0
		vp_cpy [r0 + GUI_STATICS_SDL_FUNCS], r0
		vp_call [r0 + (SDL_QUIT * 8)]
	%endmacro

	%macro sdl_createwindow 6
		;title, x, y, w, h, flags
		vp_cpy %1, r7		;title
		vp_cpy %2, r6		;x
		vp_cpy %3, r2		;y
		vp_cpy %4, r1		;w
		vp_cpy %5, r8		;h
		vp_cpy %6, r9		;flags
		fn_bind sys/gui_statics, r0
		vp_cpy [r0 + GUI_STATICS_SDL_FUNCS], r0
		vp_call [r0 + (SDL_CREATEWINDOW * 8)]
	%endmacro

	%macro sdl_createwindowandrenderer 5
		;w, h, flags, window**, renderer**
		vp_cpy %1, r7		;w
		vp_cpy %2, r6		;h
		vp_cpy %3, r2		;flags
		vp_cpy %4, r1		;window**
		vp_cpy %5, r8		;renderer**
		fn_bind sys/gui_statics, r0
		vp_cpy [r0 + GUI_STATICS_SDL_FUNCS], r0
		vp_call [r0 + (SDL_CREATEWINDOWANDRENDERER * 8)]
	%endmacro

	%macro sdl_destroywindow 1
		;window
		vp_cpy %1, r7
		fn_bind sys/gui_statics, r0
		vp_cpy [r0 + GUI_STATICS_SDL_FUNCS], r0
		vp_call [r0 + (SDL_DESTROYWINDOW * 8)]
	%endmacro

	%macro sdl_createrenderer 3
		;window*, index, flags
		vp_cpy %1, r7		;window*
		vp_cpy %2, r6		;index
		vp_cpy %3, r2		;flags
		fn_bind sys/gui_statics, r0
		vp_cpy [r0 + GUI_STATICS_SDL_FUNCS], r0
		vp_call [r0 + (SDL_CREATERENDERER * 8)]
	%endmacro

%endif