	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12	sdk_version 13, 1
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
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	leaq	L_.str(%rip), %rbx
	movq	%rbx, %rdi
	movl	$1, %esi
	xorl	%eax, %eax
	callq	_printf
	movq	%rbx, %rdi
	xorl	%esi, %esi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"

.subsections_via_symbols
