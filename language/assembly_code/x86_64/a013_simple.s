
./a013_simple.o:	file format mach-o arm64

Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
; main():
; /Users/bagjeonghun/git/playground/as/./a013_simple.c:1
; int main() {
       0: ff 43 00 d1  	sub	sp, sp, #16
       4: 00 00 80 52  	mov	w0, #0
       8: ff 0f 00 b9  	str	wzr, [sp, #12]
       c: 28 00 80 52  	mov	w8, #1
; /Users/bagjeonghun/git/playground/as/./a013_simple.c:2
;     int a = 1;
      10: e8 0b 00 b9  	str	w8, [sp, #8]
      14: 48 00 80 52  	mov	w8, #2
; /Users/bagjeonghun/git/playground/as/./a013_simple.c:3
;     int b = 2;
      18: e8 07 00 b9  	str	w8, [sp, #4]
; /Users/bagjeonghun/git/playground/as/./a013_simple.c:4
;     int c = a + b;
      1c: e8 0b 40 b9  	ldr	w8, [sp, #8]
      20: e9 07 40 b9  	ldr	w9, [sp, #4]
      24: 08 01 09 0b  	add	w8, w8, w9
      28: e8 03 00 b9  	str	w8, [sp]
; /Users/bagjeonghun/git/playground/as/./a013_simple.c:6
;     return 0;
      2c: ff 43 00 91  	add	sp, sp, #16
      30: c0 03 5f d6  	ret
