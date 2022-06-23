
a007_memcpy.o:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000000000000 _main:
; /Users/jeonpark/git/playground/contents/as/a007_memcpy.c:3
; int main(void) {
       0: 55                           	pushq	%rbp
       1: 48 89 e5                     	movq	%rsp, %rbp
       4: 31 c0                        	xorl	%eax, %eax
       6: c7 45 fc 00 00 00 00         	movl	$0, -4(%rbp)
; /Users/jeonpark/git/playground/contents/as/a007_memcpy.c:7
;     a = 'a';
       d: c6 45 fb 61                  	movb	$97, -5(%rbp)
; /Users/jeonpark/git/playground/contents/as/a007_memcpy.c:9
;     memcpy(&b, &a, sizeof(char));
      11: 8a 4d fb                     	movb	-5(%rbp), %cl
      14: 88 4d fa                     	movb	%cl, -6(%rbp)
; /Users/jeonpark/git/playground/contents/as/a007_memcpy.c:11
;     return 0;
      17: 5d                           	popq	%rbp
      18: c3                           	retq
