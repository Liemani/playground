	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	__Z16throwingFunctioni          ; -- Begin function _Z16throwingFunctioni
	.p2align	2
__Z16throwingFunctioni:                 ; @_Z16throwingFunctioni
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	w0, [x29, #-4]
	ldur	w8, [x29, #-4]
	subs	w8, w8, #0
	cset	w8, lt
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	mov	w0, #1
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
LBB0_2:
	mov	x0, #8
	bl	___cxa_allocate_exception
	str	x0, [sp]                        ; 8-byte Folded Spill
	bl	__ZNSt9exceptionC1B6v15006Ev
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	adrp	x1, __ZTISt9exception@GOTPAGE
	ldr	x1, [x1, __ZTISt9exception@GOTPAGEOFF]
	adrp	x2, __ZNSt9exceptionD1Ev@GOTPAGE
	ldr	x2, [x2, __ZNSt9exceptionD1Ev@GOTPAGEOFF]
	bl	___cxa_throw
	.cfi_endproc
                                        ; -- End function
	.private_extern	__ZNSt9exceptionC1B6v15006Ev ; -- Begin function _ZNSt9exceptionC1B6v15006Ev
	.globl	__ZNSt9exceptionC1B6v15006Ev
	.weak_def_can_be_hidden	__ZNSt9exceptionC1B6v15006Ev
	.p2align	2
__ZNSt9exceptionC1B6v15006Ev:           ; @_ZNSt9exceptionC1B6v15006Ev
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	bl	__ZNSt9exceptionC2B6v15006Ev
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
Ltmp0:
	mov	w0, #-1
	bl	__Z16throwingFunctioni
Ltmp1:
	b	LBB2_1
LBB2_1:
	b	LBB2_5
LBB2_2:
Ltmp2:
	mov	x8, x1
	str	x0, [sp, #16]
	str	w8, [sp, #12]
	b	LBB2_3
LBB2_3:
	ldr	w8, [sp, #12]
	subs	w8, w8, #1
	cset	w8, ne
	tbnz	w8, #0, LBB2_7
	b	LBB2_4
LBB2_4:
	ldr	x0, [sp, #16]
	bl	___cxa_begin_catch
	str	x0, [sp]
	mov	w8, #-1
	stur	w8, [x29, #-4]
	bl	___cxa_end_catch
	b	LBB2_6
LBB2_5:
	stur	wzr, [x29, #-4]
	b	LBB2_6
LBB2_6:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
LBB2_7:
	ldr	x0, [sp, #16]
	bl	__Unwind_Resume
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table2:
Lexception0:
	.byte	255                             ; @LPStart Encoding = omit
	.byte	155                             ; @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase0-Lttbaseref0
Lttbaseref0:
	.byte	1                               ; Call site Encoding = uleb128
	.uleb128 Lcst_end0-Lcst_begin0
Lcst_begin0:
	.uleb128 Ltmp0-Lfunc_begin0             ; >> Call Site 1 <<
	.uleb128 Ltmp1-Ltmp0                    ;   Call between Ltmp0 and Ltmp1
	.uleb128 Ltmp2-Lfunc_begin0             ;     jumps to Ltmp2
	.byte	1                               ;   On action: 1
	.uleb128 Ltmp1-Lfunc_begin0             ; >> Call Site 2 <<
	.uleb128 Lfunc_end0-Ltmp1               ;   Call between Ltmp1 and Lfunc_end0
	.byte	0                               ;     has no landing pad
	.byte	0                               ;   On action: cleanup
Lcst_end0:
	.byte	1                               ; >> Action Record 1 <<
                                        ;   Catch TypeInfo 1
	.byte	0                               ;   No further actions
	.p2align	2
                                        ; >> Catch TypeInfos <<
Ltmp3:                                  ; TypeInfo 1
	.long	__ZTISt9exception@GOT-Ltmp3
Lttbase0:
	.p2align	2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	__ZNSt9exceptionC2B6v15006Ev ; -- Begin function _ZNSt9exceptionC2B6v15006Ev
	.globl	__ZNSt9exceptionC2B6v15006Ev
	.weak_def_can_be_hidden	__ZNSt9exceptionC2B6v15006Ev
	.p2align	2
__ZNSt9exceptionC2B6v15006Ev:           ; @_ZNSt9exceptionC2B6v15006Ev
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	adrp	x8, __ZTVSt9exception@GOTPAGE
	ldr	x8, [x8, __ZTVSt9exception@GOTPAGEOFF]
	add	x8, x8, #16
	str	x0, [sp, #8]
	ldr	x0, [sp, #8]
	str	x8, [x0]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
