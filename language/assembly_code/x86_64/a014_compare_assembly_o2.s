	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12	sdk_version 13, 1
	.globl	_exchang                        ## -- Begin function exchang
	.p2align	4, 0x90
_exchang:                               ## @exchang
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	(%rdi), %rax
	movq	%rsi, (%rdi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
