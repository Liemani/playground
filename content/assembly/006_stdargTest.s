
006_stdargTest.o:	file format mach-o arm64


Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
; stdargTest():
; /Users/bagjeonghun/git/playground/content/assembly/006_stdargTest.c:3
; void	stdargTest(const char* str, ...) {
       0: ff 83 00 d1  	sub	sp, sp, #32
       4: e0 0f 00 f9  	str	x0, [sp, #24]
       8: e9 43 00 91  	add	x9, sp, #16
; /Users/bagjeonghun/git/playground/content/assembly/006_stdargTest.c:6
; 	va_start(ap, str);
       c: e8 83 00 91  	add	x8, sp, #32
      10: 28 01 00 f9  	str	x8, [x9]
; /Users/bagjeonghun/git/playground/content/assembly/006_stdargTest.c:7
; 	va_arg(ap, int);
      14: e9 0b 40 f9  	ldr	x9, [sp, #16]
      18: 28 01 40 b9  	ldr	w8, [x9]
      1c: 29 21 00 91  	add	x9, x9, #8
      20: e9 0b 00 f9  	str	x9, [sp, #16]
      24: e8 0f 00 b9  	str	w8, [sp, #12]
; /Users/bagjeonghun/git/playground/content/assembly/006_stdargTest.c:8
; 	va_arg(ap, int);
      28: e9 0b 40 f9  	ldr	x9, [sp, #16]
      2c: 28 01 40 b9  	ldr	w8, [x9]
      30: 29 21 00 91  	add	x9, x9, #8
      34: e9 0b 00 f9  	str	x9, [sp, #16]
      38: e8 0b 00 b9  	str	w8, [sp, #8]
; /Users/bagjeonghun/git/playground/content/assembly/006_stdargTest.c:9
; 	va_arg(ap, double);
      3c: e9 0b 40 f9  	ldr	x9, [sp, #16]
      40: 28 01 40 f9  	ldr	x8, [x9]
      44: 29 21 00 91  	add	x9, x9, #8
      48: e9 0b 00 f9  	str	x9, [sp, #16]
      4c: e8 03 00 f9  	str	x8, [sp]
; /Users/bagjeonghun/git/playground/content/assembly/006_stdargTest.c:11
; }
      50: ff 83 00 91  	add	sp, sp, #32
      54: c0 03 5f d6  	ret

0000000000000058 <_main>:
; main():
; /Users/bagjeonghun/git/playground/content/assembly/006_stdargTest.c:13
; int	main(void) {
      58: ff c3 00 d1  	sub	sp, sp, #48
      5c: fd 7b 02 a9  	stp	x29, x30, [sp, #32]
      60: fd 83 00 91  	add	x29, sp, #32
      64: 08 00 80 52  	mov	w8, #0
      68: a8 83 1f b8  	stur	w8, [x29, #-8]
      6c: bf c3 1f b8  	stur	wzr, [x29, #-4]
      70: 00 00 00 90  	adrp	x0, 0x0 <_main+0x18>
      74: 00 00 00 91  	add	x0, x0, #0
; /Users/bagjeonghun/git/playground/content/assembly/006_stdargTest.c:14
; 	stdargTest("abc", 2147483648, 10, 1.1);
      78: e9 03 00 91  	mov	x9, sp
      7c: 08 00 b0 d2  	mov	x8, #2147483648
      80: 28 01 00 f9  	str	x8, [x9]
      84: 48 01 80 d2  	mov	x8, #10
      88: 28 05 00 f9  	str	x8, [x9, #8]
      8c: e8 e7 01 b2  	mov	x8, #-7378697629483820647
      90: 48 33 93 f2  	movk	x8, #39322
      94: 28 fe e7 f2  	movk	x8, #16369, lsl #48
      98: 28 09 00 f9  	str	x8, [x9, #16]
      9c: 00 00 00 94  	bl	0x9c <_main+0x44>
      a0: a0 83 5f b8  	ldur	w0, [x29, #-8]
; /Users/bagjeonghun/git/playground/content/assembly/006_stdargTest.c:15
; 	return 0;
      a4: fd 7b 42 a9  	ldp	x29, x30, [sp, #32]
      a8: ff c3 00 91  	add	sp, sp, #48
      ac: c0 03 5f d6  	ret
