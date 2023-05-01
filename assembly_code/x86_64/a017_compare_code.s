	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12	sdk_version 13, 1
	.globl	_arith                          ## -- Begin function arith
	.p2align	4, 0x90
_arith:                                 ## @arith
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	xorl	%edi, %esi
	shlq	$4, %rdx
	leaq	(%rdx,%rdx,2), %rax
	andl	$252645135, %esi                ## imm = 0xF0F0F0F
	subq	%rsi, %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
