
003_index_vs_pointer2.o:	file format mach-o arm64


Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
; main():
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:3
; int	main(void) {
       0: ff 03 01 d1  	sub	sp, sp, #64
       4: fd 7b 03 a9  	stp	x29, x30, [sp, #48]
       8: fd c3 00 91  	add	x29, sp, #48
       c: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0xc>
      10: 08 01 40 f9  	ldr	x8, [x8]
      14: 08 01 40 f9  	ldr	x8, [x8]
      18: a8 83 1f f8  	stur	x8, [x29, #-8]
      1c: ff 17 00 b9  	str	wzr, [sp, #20]
      20: 09 00 00 90  	adrp	x9, 0x0 <ltmp0+0x20>
      24: 29 01 00 91  	add	x9, x9, #0
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:4
; 	int	array[size] = { 3, 2, 1 };
      28: 2a 01 40 f9  	ldr	x10, [x9]
      2c: e8 63 00 91  	add	x8, sp, #24
      30: ea 0f 00 f9  	str	x10, [sp, #24]
      34: 29 09 40 b9  	ldr	w9, [x9, #8]
      38: e9 23 00 b9  	str	w9, [sp, #32]
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:5
; 	const int*	end = array + size;
      3c: 09 31 00 91  	add	x9, x8, #12
      40: e9 07 00 f9  	str	x9, [sp, #8]
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:7
; 	for (int* pointer = array; pointer < end; pointer += 1)
      44: e8 03 00 f9  	str	x8, [sp]
      48: e8 03 40 f9  	ldr	x8, [sp]
      4c: e9 07 40 f9  	ldr	x9, [sp, #8]
      50: 08 01 09 eb  	subs	x8, x8, x9
      54: e2 00 00 54  	b.hs	0x70 <ltmp0+0x70>
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:8
; 		*pointer = 0;
      58: e8 03 40 f9  	ldr	x8, [sp]
      5c: 1f 01 00 b9  	str	wzr, [x8]
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:7
; 	for (int* pointer = array; pointer < end; pointer += 1)
      60: e8 03 40 f9  	ldr	x8, [sp]
      64: 08 11 00 91  	add	x8, x8, #4
      68: e8 03 00 f9  	str	x8, [sp]
      6c: f7 ff ff 17  	b	0x48 <ltmp0+0x48>
      70: 08 00 00 90  	adrp	x8, 0x0 <ltmp0+0x70>
      74: 08 01 40 f9  	ldr	x8, [x8]
      78: 08 01 40 f9  	ldr	x8, [x8]
      7c: a9 83 5f f8  	ldur	x9, [x29, #-8]
      80: 08 01 09 eb  	subs	x8, x8, x9
      84: a1 00 00 54  	b.ne	0x98 <ltmp0+0x98>
      88: 00 00 80 52  	mov	w0, #0
; /Users/bagjeonghun/git/playground/content/assembly/003_index_vs_pointer2.c:10
; 	return 0;
      8c: fd 7b 43 a9  	ldp	x29, x30, [sp, #48]
      90: ff 03 01 91  	add	sp, sp, #64
      94: c0 03 5f d6  	ret
      98: 00 00 00 94  	bl	0x98 <ltmp0+0x98>
