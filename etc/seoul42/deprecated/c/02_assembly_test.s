	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	movl	$0, -4(%rbp)
	movl	$200, -8(%rbp)
	cmpl	$0, -8(%rbp)
	movb	%al, -9(%rbp)           ## 1-byte Spill
	je	LBB0_2
## %bb.1:
	cmpl	$0, -8(%rbp)
	setne	%al
	xorb	$-1, %al
	movb	%al, %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movl	%edx, -8(%rbp)
	movb	%al, -9(%rbp)           ## 1-byte Spill
LBB0_2:
	movb	-9(%rbp), %al           ## 1-byte Reload
	xorl	%ecx, %ecx
	movb	%al, -10(%rbp)          ## 1-byte Spill
	movl	%ecx, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
