swap_add:
    pushq   %rbp
    movq    %rsp, %rbp

    

    popq    %rbp
    retq

caller:
    pushq   %rbp
    movq    %rsp, %rbp

    callq   swap_add

    popq    %rbp
    retq




	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	L_.str(%rip), %rdi

Init:
    movl    $0, %ecx
    movl    $1, %edx
Loop:
    addl    %edx, %ecx
    addl    $1, %edx
    cmpl    $10, %edx
    jle     Loop

	movl	%ecx, %esi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq

