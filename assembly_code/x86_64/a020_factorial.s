	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12	sdk_version 13, 1
	.globl	_fact_for                       ## -- Begin function fact_for
	.p2align	4, 0x90
_fact_for:                              ## @fact_for
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$1, %eax
	cmpq	$2, %rdi
	jl	LBB0_3
## %bb.1:
	movl	$1, %eax
	movl	$1, %ecx
	subq	%rdi, %rcx
	movl	$2, %edx
	.p2align	4, 0x90
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	imulq	%rdx, %rax
	leaq	(%rcx,%rdx), %rsi
	addq	$1, %rsi
	addq	$1, %rdx
	cmpq	$2, %rsi
	jne	LBB0_2
LBB0_3:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
