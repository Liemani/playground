
a012_memcpy_array.o:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000000000000 _main:
; /Users/jeonpark/git/playground/contents/as/a012_memcpy_array.c:5
; int main(void) {
       0: 55                           	pushq	%rbp
       1: 48 89 e5                     	movq	%rsp, %rbp
       4: 48 81 ec 80 00 00 00         	subq	$128, %rsp
       b: 48 8b 05 00 00 00 00         	movq	(%rip), %rax
      12: 48 8b 00                     	movq	(%rax), %rax
      15: 48 89 45 f8                  	movq	%rax, -8(%rbp)
      19: c7 45 8c 00 00 00 00         	movl	$0, -116(%rbp)
; /Users/jeonpark/git/playground/contents/as/a012_memcpy_array.c:9
;     memcpy(&b, &a, sizeof(char) * ARRAY_SIZE);
      20: 48 8d 45 90                  	leaq	-112(%rbp), %rax
      24: 48 8d 4d c0                  	leaq	-64(%rbp), %rcx
      28: 48 89 c7                     	movq	%rax, %rdi
      2b: 48 89 ce                     	movq	%rcx, %rsi
      2e: ba 2a 00 00 00               	movl	$42, %edx
      33: e8 00 00 00 00               	callq	0 <_main+0x38>
      38: 48 8b 05 00 00 00 00         	movq	(%rip), %rax
      3f: 48 8b 00                     	movq	(%rax), %rax
      42: 48 8b 4d f8                  	movq	-8(%rbp), %rcx
      46: 48 39 c8                     	cmpq	%rcx, %rax
      49: 0f 85 0b 00 00 00            	jne	11 <_main+0x5a>
      4f: 31 c0                        	xorl	%eax, %eax
; /Users/jeonpark/git/playground/contents/as/a012_memcpy_array.c:11
;     return 0;
      51: 48 81 c4 80 00 00 00         	addq	$128, %rsp
      58: 5d                           	popq	%rbp
      59: c3                           	retq
      5a: e8 00 00 00 00               	callq	0 <_main+0x5f>
      5f: 0f 0b                        	ud2
