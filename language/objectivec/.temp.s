a.out:
(__TEXT,__text) section
_main:
0000000100003f38	sub	sp, sp, #0x30
0000000100003f3c	stp	x29, x30, [sp, #0x20]
0000000100003f40	add	x29, sp, #0x20
0000000100003f44	mov	w8, #0x0
0000000100003f48	str	w8, [sp, #0xc]
0000000100003f4c	stur	wzr, [x29, #-0x4]
0000000100003f50	stur	w0, [x29, #-0x8]
0000000100003f54	str	x1, [sp, #0x10]
0000000100003f58	bl	0x100003f9c ; symbol stub for: _objc_autoreleasePoolPush
0000000100003f5c	str	x0, [sp]
0000000100003f60	adrp	x0, 1 ; 0x100004000
0000000100003f64	add	x0, x0, #0x18 ; Objc cfstring ref: @"bad cfstring ref"
0000000100003f68	bl	0x100003f84 ; symbol stub for: _NSLog
0000000100003f6c	ldr	x0, [sp]
0000000100003f70	bl	0x100003f90 ; symbol stub for: _objc_autoreleasePoolPop
0000000100003f74	ldr	w0, [sp, #0xc]
0000000100003f78	ldp	x29, x30, [sp, #0x20]
0000000100003f7c	add	sp, sp, #0x30
0000000100003f80	ret
