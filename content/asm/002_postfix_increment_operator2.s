
002_postfix_increment_operator.o:	file format mach-o arm64


Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
; {
       0: ff 03 01 d1  	sub	sp, sp, #64
       4: fd 7b 03 a9  	stp	x29, x30, [sp, #48]
       8: fd c3 00 91  	add	x29, sp, #48
       c: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0xc>
      10: 08 01 40 f9  	ldr	x8, [x8]
      14: 08 01 40 f9  	ldr	x8, [x8]
      18: a8 83 1f f8  	stur	x8, [x29, #-8]
      1c: ff 17 00 b9  	str	wzr, [sp, #20]
      20: a8 43 00 d1  	sub	x8, x29, #16
; 	ptr1 = array1;
      24: e8 07 00 f9  	str	x8, [sp, #8]
      28: e8 63 00 91  	add	x8, sp, #24
; 	ptr2 = array2;
      2c: e8 03 00 f9  	str	x8, [sp]
; 	*ptr1++ = *ptr2++;
      30: e8 03 40 f9  	ldr	x8, [sp]
      34: 09 11 00 91  	add	x9, x8, #4
      38: e9 03 00 f9  	str	x9, [sp]
      3c: 08 01 40 b9  	ldr	w8, [x8]
      40: e9 07 40 f9  	ldr	x9, [sp, #8]
      44: 2a 11 00 91  	add	x10, x9, #4
      48: ea 07 00 f9  	str	x10, [sp, #8]
      4c: 28 01 00 b9  	str	w8, [x9]
      50: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0x50>
      54: 08 01 40 f9  	ldr	x8, [x8]
      58: 08 01 40 f9  	ldr	x8, [x8]
      5c: a9 83 5f f8  	ldur	x9, [x29, #-8]
      60: 08 01 09 eb  	subs	x8, x8, x9
      64: a1 00 00 54  	b.ne	0x78 <ltmp0+0x78>
      68: 00 00 80 52  	mov	w0, #0
; 	return (0);
      6c: fd 7b 43 a9  	ldp	x29, x30, [sp, #48]
      70: ff 03 01 91  	add	sp, sp, #64
      74: c0 03 5f d6  	ret
      78: 00 00 00 94  	bl	0x78 <ltmp0+0x78>
