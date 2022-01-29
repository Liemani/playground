
003_index_vs_pointer1.o:	file format mach-o arm64


Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
; main():
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:3
; int	main(void) {
       0: ff c3 00 d1  	sub	sp, sp, #48
       4: fd 7b 02 a9  	stp	x29, x30, [sp, #32]
       8: fd 83 00 91  	add	x29, sp, #32
       c: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0xc>
      10: 08 01 40 f9  	ldr	x8, [x8]
      14: 08 01 40 f9  	ldr	x8, [x8]
      18: a8 83 1f f8  	stur	x8, [x29, #-8]
      1c: ff 0f 00 b9  	str	wzr, [sp, #12]
      20: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0x20>
      24: 08 01 00 91  	add	x8, x8, #0
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:4
; 	int	array[size] = { 2, 1 };
      28: 08 01 40 f9  	ldr	x8, [x8]
      2c: e8 0b 00 f9  	str	x8, [sp, #16]
      30: 28 00 80 52  	mov	w8, #1
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:7
; 	index = 1;
      34: e8 0b 00 b9  	str	w8, [sp, #8]
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:8
; 	if (index < size)
      38: e8 0b 40 b9  	ldr	w8, [sp, #8]
      3c: 08 09 00 71  	subs	w8, w8, #2
      40: aa 00 00 54  	b.ge	0x54 <ltmp0+0x54>
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:9
; 		array[index] = 0;
      44: ea 0b 80 b9  	ldrsw	x10, [sp, #8]
      48: e9 43 00 91  	add	x9, sp, #16
      4c: 08 00 80 52  	mov	w8, #0
      50: 28 79 2a b8  	str	w8, [x9, x10, lsl #2]
      54: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0x54>
      58: 08 01 40 f9  	ldr	x8, [x8]
      5c: 08 01 40 f9  	ldr	x8, [x8]
      60: a9 83 5f f8  	ldur	x9, [x29, #-8]
      64: 08 01 09 eb  	subs	x8, x8, x9
      68: a1 00 00 54  	b.ne	0x7c <ltmp0+0x7c>
      6c: 00 00 80 52  	mov	w0, #0
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:11
; 	return 0;
      70: fd 7b 42 a9  	ldp	x29, x30, [sp, #32]
      74: ff c3 00 91  	add	sp, sp, #48
      78: c0 03 5f d6  	ret
      7c: 00 00 00 94  	bl	0x7c <ltmp0+0x7c>
