
.002_postfix_increment_operator.o:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000000000000 _main:
; {
       0: 55                           	pushq	%rbp
       1: 48 89 e5                     	movq	%rsp, %rbp
       4: 48 83 ec 50                  	subq	$80, %rsp
       8: 48 8d 45 d0                  	leaq	-48(%rbp), %rax
       c: 48 8d 4d e0                  	leaq	-32(%rbp), %rcx
      10: 48 8b 15 00 00 00 00         	movq	(%rip), %rdx
      17: 48 8b 12                     	movq	(%rdx), %rdx
      1a: 48 89 55 f8                  	movq	%rdx, -8(%rbp)
      1e: c7 45 cc 00 00 00 00         	movl	$0, -52(%rbp)
; 	int	*ptr1 = array1;
      25: 48 89 4d c0                  	movq	%rcx, -64(%rbp)
; 	int	*ptr2 = array2;
      29: 48 89 45 b8                  	movq	%rax, -72(%rbp)
; 	*ptr1++ = *ptr2++;
      2d: 48 8b 45 b8                  	movq	-72(%rbp), %rax
      31: 48 89 c1                     	movq	%rax, %rcx
      34: 48 81 c1 04 00 00 00         	addq	$4, %rcx
      3b: 48 89 4d b8                  	movq	%rcx, -72(%rbp)
      3f: 8b 30                        	movl	(%rax), %esi
      41: 48 8b 45 c0                  	movq	-64(%rbp), %rax
      45: 48 89 c1                     	movq	%rax, %rcx
      48: 48 81 c1 04 00 00 00         	addq	$4, %rcx
      4f: 48 89 4d c0                  	movq	%rcx, -64(%rbp)
      53: 89 30                        	movl	%esi, (%rax)
      55: 48 8b 05 00 00 00 00         	movq	(%rip), %rax
      5c: 48 8b 00                     	movq	(%rax), %rax
      5f: 48 8b 4d f8                  	movq	-8(%rbp), %rcx
      63: 48 39 c8                     	cmpq	%rcx, %rax
      66: 0f 85 08 00 00 00            	jne	8 <_main+0x74>
      6c: 31 c0                        	xorl	%eax, %eax
; 	return (0);
      6e: 48 83 c4 50                  	addq	$80, %rsp
      72: 5d                           	popq	%rbp
      73: c3                           	retq
      74: e8 00 00 00 00               	callq	0 <_main+0x79>
      79: 0f 0b                        	ud2
