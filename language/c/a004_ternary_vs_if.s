	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	stur	wzr, [x29, #-8]
	mov	w8, #1
	stur	w8, [x29, #-12]
	ldur	w8, [x29, #-8]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	b.ne	LBB0_2
	b	LBB0_1
LBB0_1:
	ldur	w8, [x29, #-8]
	str	w8, [sp, #12]                   ; 4-byte Folded Spill
	b	LBB0_3
LBB0_2:
	ldur	w8, [x29, #-12]
	str	w8, [sp, #12]                   ; 4-byte Folded Spill
	b	LBB0_3
LBB0_3:
	ldr	w8, [sp, #12]                   ; 4-byte Folded Reload
	str	w8, [sp, #16]
	ldr	w9, [sp, #16]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	w0, #0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"c = %d\n"

.subsections_via_symbols
