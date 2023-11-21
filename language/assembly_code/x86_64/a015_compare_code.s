	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12	sdk_version 13, 1
	.globl	_scale3                         ## -- Begin function scale3
	.p2align	4, 0x90
_scale3:                                ## @scale3
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	addl	$10, %edi
	imull	%esi, %edi
	addl	%edx, %edi
	movswl	%di, %eax
##    leaq   (%rsi,%rsi,9), %rbx
##    leaq   (%rbx,%rdx), %rbx
##    leaq   (%rbx,%rdi,%rsi), %rbx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
