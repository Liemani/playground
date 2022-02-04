
005_analyzeStackSegment.o:	file format mach-o arm64


Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
; main():
; /Users/bagjeonghun/git/playground/content/assembly/005_analyzeStackSegment.c:1
; int	main() {
       0: ff 43 00 d1  	sub	sp, sp, #16
       4: 00 00 80 52  	mov	w0, #0
       8: ff 0f 00 b9  	str	wzr, [sp, #12]
; /Users/bagjeonghun/git/playground/content/assembly/005_analyzeStackSegment.c:2
; 	int	a = 0;
       c: ff 0b 00 b9  	str	wzr, [sp, #8]
; /Users/bagjeonghun/git/playground/content/assembly/005_analyzeStackSegment.c:4
; 	return 0;
      10: ff 43 00 91  	add	sp, sp, #16
      14: c0 03 5f d6  	ret
