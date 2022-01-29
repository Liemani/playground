
003_index_vs_pointer2.o:	file format mach-o arm64


Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
; main():
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:3
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
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:4
; 	int	array[size] = { 2, 1 };
      28: 08 01 40 f9  	ldr	x8, [x8]
      2c: e9 43 00 91  	add	x9, sp, #16
      30: e8 0b 00 f9  	str	x8, [sp, #16]
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:7
; 	pointer = array + 1;
      34: 28 11 00 91  	add	x8, x9, #4
      38: e8 03 00 f9  	str	x8, [sp]
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:8
; 	if (pointer - array < size)
      3c: e8 03 40 f9  	ldr	x8, [sp]
      40: 08 01 09 eb  	subs	x8, x8, x9
      44: 89 00 80 d2  	mov	x9, #4
      48: 08 0d c9 9a  	sdiv	x8, x8, x9
      4c: 08 09 00 f1  	subs	x8, x8, #2
      50: 6a 00 00 54  	b.ge	0x5c <ltmp0+0x5c>
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:9
; 		*pointer = 0;
      54: e8 03 40 f9  	ldr	x8, [sp]
      58: 1f 01 00 b9  	str	wzr, [x8]
      5c: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0x5c>
      60: 08 01 40 f9  	ldr	x8, [x8]
      64: 08 01 40 f9  	ldr	x8, [x8]
      68: a9 83 5f f8  	ldur	x9, [x29, #-8]
      6c: 08 01 09 eb  	subs	x8, x8, x9
      70: a1 00 00 54  	b.ne	0x84 <ltmp0+0x84>
      74: 00 00 80 52  	mov	w0, #0
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:11
; 	return 0;
      78: fd 7b 42 a9  	ldp	x29, x30, [sp, #32]
      7c: ff c3 00 91  	add	sp, sp, #48
      80: c0 03 5f d6  	ret
      84: 00 00 00 94  	bl	0x84 <ltmp0+0x84>
