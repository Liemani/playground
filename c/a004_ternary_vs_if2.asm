
a004_ternary_vs_if.o:	file format mach-o arm64

Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
; main():
; /Users/bagjeonghun/git/playground/c/a004_ternary_vs_if.c:3
; int main(void) {
       0: ff c3 00 d1  	sub	sp, sp, #48
       4: fd 7b 02 a9  	stp	x29, x30, [sp, #32]
       8: fd 83 00 91  	add	x29, sp, #32
       c: bf c3 1f b8  	stur	wzr, [x29, #-4]
; /Users/bagjeonghun/git/playground/c/a004_ternary_vs_if.c:4
;     int a = 0;
      10: bf 83 1f b8  	stur	wzr, [x29, #-8]
      14: 28 00 80 52  	mov	w8, #1
; /Users/bagjeonghun/git/playground/c/a004_ternary_vs_if.c:5
;     int b = 1;
      18: a8 43 1f b8  	stur	w8, [x29, #-12]
; /Users/bagjeonghun/git/playground/c/a004_ternary_vs_if.c:11
;     if (a == b)
      1c: a8 83 5f b8  	ldur	w8, [x29, #-8]
      20: a9 43 5f b8  	ldur	w9, [x29, #-12]
      24: 08 01 09 6b  	subs	w8, w8, w9
      28: a1 00 00 54  	b.ne	0x3c <ltmp0+0x3c>
      2c: 01 00 00 14  	b	0x30 <ltmp0+0x30>
; /Users/bagjeonghun/git/playground/c/a004_ternary_vs_if.c:12
;         c = a;
      30: a8 83 5f b8  	ldur	w8, [x29, #-8]
      34: e8 13 00 b9  	str	w8, [sp, #16]
      38: 04 00 00 14  	b	0x48 <ltmp0+0x48>
; /Users/bagjeonghun/git/playground/c/a004_ternary_vs_if.c:14
;         c = b;
      3c: a8 43 5f b8  	ldur	w8, [x29, #-12]
      40: e8 13 00 b9  	str	w8, [sp, #16]
      44: 01 00 00 14  	b	0x48 <ltmp0+0x48>
; /Users/bagjeonghun/git/playground/c/a004_ternary_vs_if.c:19
;     printf("c = %d\n", c);
      48: e9 13 40 b9  	ldr	w9, [sp, #16]
      4c: e8 03 09 aa  	mov	x8, x9
      50: e9 03 00 91  	mov	x9, sp
      54: 28 01 00 f9  	str	x8, [x9]
      58: 00 00 00 90  	adrp	x0, 0x0 <ltmp0+0x58>
      5c: 00 00 00 91  	add	x0, x0, #0
; /Users/bagjeonghun/git/playground/c/a004_ternary_vs_if.c:19
;     printf("c = %d\n", c);
      60: 00 00 00 94  	bl	0x60 <ltmp0+0x60>
      64: 00 00 80 52  	mov	w0, #0
; /Users/bagjeonghun/git/playground/c/a004_ternary_vs_if.c:21
;     return 0;
      68: fd 7b 42 a9  	ldp	x29, x30, [sp, #32]
      6c: ff c3 00 91  	add	sp, sp, #48
      70: c0 03 5f d6  	ret
