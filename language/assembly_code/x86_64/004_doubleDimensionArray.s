
004_doubleDimensionArray.o:	file format mach-o arm64


Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
; main():
; /Users/bagjeonghun/git/playground/content/assembly/004_doubleDimensionArray.c:1
; int	main(void) {
       0: ff 43 01 d1  	sub	sp, sp, #80
       4: fd 7b 04 a9  	stp	x29, x30, [sp, #64]
       8: fd 03 01 91  	add	x29, sp, #64
       c: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0xc>
      10: 08 01 40 f9  	ldr	x8, [x8]
      14: 08 01 40 f9  	ldr	x8, [x8]
      18: a8 83 1f f8  	stur	x8, [x29, #-8]
      1c: ff 1f 00 b9  	str	wzr, [sp, #28]
      20: 09 00 00 90  	adrp	x9, 0x0 <ltmp0+0x20>
      24: 29 01 00 91  	add	x9, x9, #0
; /Users/bagjeonghun/git/playground/content/assembly/004_doubleDimensionArray.c:2
; 	int	array[2][3] = {
      28: 20 01 c0 3d  	ldr	q0, [x9]
      2c: e8 83 00 91  	add	x8, sp, #32
      30: e0 0b 80 3d  	str	q0, [sp, #32]
      34: 29 09 40 f9  	ldr	x9, [x9, #16]
      38: e9 1b 00 f9  	str	x9, [sp, #48]
; /Users/bagjeonghun/git/playground/content/assembly/004_doubleDimensionArray.c:9
; 	pointerArray = array;
      3c: e8 0b 00 f9  	str	x8, [sp, #16]
; /Users/bagjeonghun/git/playground/content/assembly/004_doubleDimensionArray.c:10
; 	pointer = *array;
      40: e8 07 00 f9  	str	x8, [sp, #8]
; /Users/bagjeonghun/git/playground/content/assembly/004_doubleDimensionArray.c:11
; 	pointer = *(array + 1);
      44: 08 31 00 91  	add	x8, x8, #12
      48: e8 07 00 f9  	str	x8, [sp, #8]
      4c: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0x4c>
      50: 08 01 40 f9  	ldr	x8, [x8]
      54: 08 01 40 f9  	ldr	x8, [x8]
      58: a9 83 5f f8  	ldur	x9, [x29, #-8]
      5c: 08 01 09 eb  	subs	x8, x8, x9
      60: a1 00 00 54  	b.ne	0x74 <ltmp0+0x74>
      64: 00 00 80 52  	mov	w0, #0
; /Users/bagjeonghun/git/playground/content/assembly/004_doubleDimensionArray.c:13
; 	return 0;
      68: fd 7b 44 a9  	ldp	x29, x30, [sp, #64]
      6c: ff 43 01 91  	add	sp, sp, #80
      70: c0 03 5f d6  	ret
      74: 00 00 00 94  	bl	0x74 <ltmp0+0x74>
