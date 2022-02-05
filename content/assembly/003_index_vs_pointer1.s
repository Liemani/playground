
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
      1c: ff 07 00 b9  	str	wzr, [sp, #4]
      20: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0x20>
      24: 08 01 00 91  	add	x8, x8, #0
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:4
; 	int	array[size] = { 3, 2, 1 };
      28: 09 01 40 f9  	ldr	x9, [x8]
      2c: e9 07 00 f9  	str	x9, [sp, #8]
      30: 08 09 40 b9  	ldr	w8, [x8, #8]
      34: e8 13 00 b9  	str	w8, [sp, #16]
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:6
; 	for (int index = 0; index < size; index += 1)
      38: ff 03 00 b9  	str	wzr, [sp]
      3c: e8 03 40 b9  	ldr	w8, [sp]
      40: 08 0d 00 71  	subs	w8, w8, #3
      44: 2a 01 00 54  	b.ge	0x68 <ltmp0+0x68>
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:7
; 		array[index] = 0;
      48: ea 03 80 b9  	ldrsw	x10, [sp]
      4c: e9 23 00 91  	add	x9, sp, #8
      50: 08 00 80 52  	mov	w8, #0
      54: 28 79 2a b8  	str	w8, [x9, x10, lsl #2]
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:6
; 	for (int index = 0; index < size; index += 1)
      58: e8 03 40 b9  	ldr	w8, [sp]
      5c: 08 05 00 11  	add	w8, w8, #1
      60: e8 03 00 b9  	str	w8, [sp]
      64: f6 ff ff 17  	b	0x3c <ltmp0+0x3c>
      68: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0x68>
      6c: 08 01 40 f9  	ldr	x8, [x8]
      70: 08 01 40 f9  	ldr	x8, [x8]
      74: a9 83 5f f8  	ldur	x9, [x29, #-8]
      78: 08 01 09 eb  	subs	x8, x8, x9
      7c: a1 00 00 54  	b.ne	0x90 <ltmp0+0x90>
      80: 00 00 80 52  	mov	w0, #0
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer1.c:9
; 	return 0;
      84: fd 7b 42 a9  	ldp	x29, x30, [sp, #32]
      88: ff c3 00 91  	add	sp, sp, #48
      8c: c0 03 5f d6  	ret
      90: 00 00 00 94  	bl	0x90 <ltmp0+0x90>
