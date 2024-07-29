	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12	sdk_version 13, 1
	.globl	_absdiff_se                     ## -- Begin function absdiff_se
	.p2align	4, 0x90
_absdiff_se:                            ## @absdiff_se
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp

    cmpq    %rsi, %rdi
    jge     LBB0_2
## %bb.1:
    addq    $1, _lt_cnt(%rip)
    subq    %rdi, %rsi
    movq    %rsi, %rax
    popq    %rbp
    retq
LBB0_2:
    addq    $1, _ge_cnt(%rip)
    subq    %rsi, %rdi
    movq    %rdi, %rax
    popq    %rbp
    retq

##	movq	%rdi, %rax
##	subq	%rsi, %rax
##	jge	LBB0_2
#### %bb.1:
##	addq	$1, _lt_cnt(%rip)
##	subq	%rdi, %rsi
##	movq	%rsi, %rax
##	popq	%rbp
##	retq
##LBB0_2:
##	addq	$1, _ge_cnt(%rip)
##	popq	%rbp
##	retq

	.cfi_endproc
                                        ## -- End function
	.globl	_lt_cnt                         ## @lt_cnt
.zerofill __DATA,__common,_lt_cnt,8,3
	.globl	_ge_cnt                         ## @ge_cnt
.zerofill __DATA,__common,_ge_cnt,8,3
.subsections_via_symbols
