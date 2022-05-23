
a011_memcpy_longlong.o:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000000000000 _main:
; /Users/jeonpark/git/playground/contents/as/a011_memcpy_longlong.c:3
; int main(void) {
       0: 55                           	pushq	%rbp
       1: 48 89 e5                     	movq	%rsp, %rbp
       4: 31 c0                        	xorl	%eax, %eax
       6: c7 45 fc 00 00 00 00         	movl	$0, -4(%rbp)
; /Users/jeonpark/git/playground/contents/as/a011_memcpy_longlong.c:7
;     a = 42;
       d: 48 c7 45 f0 2a 00 00 00      	movq	$42, -16(%rbp)
; /Users/jeonpark/git/playground/contents/as/a011_memcpy_longlong.c:9
;     memcpy(&b, &a, sizeof(long long));
      15: 48 8b 4d f0                  	movq	-16(%rbp), %rcx
      19: 48 89 4d e8                  	movq	%rcx, -24(%rbp)
; /Users/jeonpark/git/playground/contents/as/a011_memcpy_longlong.c:11
;     return 0;
      1d: 5d                           	popq	%rbp
      1e: c3                           	retq
