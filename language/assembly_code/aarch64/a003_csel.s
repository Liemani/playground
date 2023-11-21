	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	wzr, [sp, #12]

    mov w1, #0xfffffffd

    mov w8, #0x2
    mov w9, #0x3

    cmn    w1, #0x3

    csel   w0, w8, w9, lo
    csel   w0, w8, w9, eq
    csel   w0, w8, w9, hi

	add	sp, sp, #16

; _test:
    mov    w8, #0x1              ; w8 = 1
    mov    w9, #0x1              ; w9 = 1
    sub    w10, w1, #0x40        ; w10 = w1 - 0x40
    cmn    w10, #0x1f            ; nzcv = w10 - (-0x1f)
    cset   w10, lo               ; w10 = nzcv < 0
    cmp    w1, #0x22             ; nzcv = w1 - 0x22
    csel   w9, w9, w10, eq       ; w9 = nzcv == 0 ? w9 : w10
    cmp    w1, #0x5f             ; nzcv = w1 - 0x5f
    csel   w9, wzr, w9, hi       ; w9 = nzcv > 0 ? wzr : w9
    cmn    w1, #0x3              ; nzcv = w1 - (-0x3)
    csel   w0, w8, w9, hi        ; w0 = nzcv > 0 ? w8 : w9

	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
