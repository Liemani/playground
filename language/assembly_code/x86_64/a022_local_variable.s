	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12	sdk_version 13, 1
	.globl	_add_one                        ## -- Begin function add_one
	.p2align	4, 0x90
_add_one:                               ## @add_one
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -20(%rbp)
	movslq	-8(%rbp), %rax
	movq	%rax, -32(%rbp)
	movl	-20(%rbp), %edi
	callq	_add_one
	movl	%eax, -20(%rbp)
	movq	-32(%rbp), %rax
	movl	%eax, %edi
	callq	_add_one
	cltq
	movq	%rax, -32(%rbp)
	movslq	-20(%rbp), %rax
	addq	-32(%rbp), %rax
                                        ## kill: def $eax killed $eax killed $rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
