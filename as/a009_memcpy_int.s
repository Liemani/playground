
a009_memcpy_int.o:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000000000000 _main:
; /Users/jeonpark/git/playground/contents/as/a009_memcpy_int.c:3
; int main(void) {
       0: 55                           	pushq	%rbp
       1: 48 89 e5                     	movq	%rsp, %rbp
       4: 31 c0                        	xorl	%eax, %eax
       6: c7 45 fc 00 00 00 00         	movl	$0, -4(%rbp)
; /Users/jeonpark/git/playground/contents/as/a009_memcpy_int.c:7
;     a = 42;
       d: c7 45 f8 2a 00 00 00         	movl	$42, -8(%rbp)
; /Users/jeonpark/git/playground/contents/as/a009_memcpy_int.c:9
;     memcpy(&b, &a, sizeof(int));
      14: 8b 4d f8                     	movl	-8(%rbp), %ecx
      17: 89 4d f4                     	movl	%ecx, -12(%rbp)
; /Users/jeonpark/git/playground/contents/as/a009_memcpy_int.c:11
;     return 0;
      1a: 5d                           	popq	%rbp
      1b: c3                           	retq
