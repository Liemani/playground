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
	xorl	%eax, %eax
    movl    $0x2, %r8d
    movl    $0xFFFFFFFF, %r9d
    addl    %r8d, %r9d
    movl    $0x7FFFFFFF, %r9d
    addl    %r8d, %r9d
    movl    $0x80000000, %r10d
    subl    %r8d, %r10d
    sall    $0x2, %r10d
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
