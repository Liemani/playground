
a008_memcpy_short.o:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000000000000 _main:
; /Users/jeonpark/git/playground/contents/as/a008_memcpy_short.c:3
; int main(void) {
       0: 55                           	pushq	%rbp
       1: 48 89 e5                     	movq	%rsp, %rbp
       4: 31 c0                        	xorl	%eax, %eax
       6: c7 45 fc 00 00 00 00         	movl	$0, -4(%rbp)
; /Users/jeonpark/git/playground/contents/as/a008_memcpy_short.c:7
;     a = 42;
       d: 66 c7 45 fa 2a 00            	movw	$42, -6(%rbp)
; /Users/jeonpark/git/playground/contents/as/a008_memcpy_short.c:9
;     memcpy(&b, &a, sizeof(short));
      13: 66 8b 4d fa                  	movw	-6(%rbp), %cx
      17: 66 89 4d f8                  	movw	%cx, -8(%rbp)
; /Users/jeonpark/git/playground/contents/as/a008_memcpy_short.c:11
;     return 0;
      1b: 5d                           	popq	%rbp
      1c: c3                           	retq
