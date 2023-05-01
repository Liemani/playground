/*
switch2:
    addq    $2, %rdi
    cmpq    $8, %rdi
    ja      .L2
    jmp     *.L4(,%rdi,8)
.L4:
    .quad   .L9     ## -2
    .quad   .L5     ## -1
    .quad   .L6     ## 0
    .quad   .L7     ## 1
    .quad   .L2     ## 2
    .quad   .L7     ## 3
    .quad   .L8     ## 4
    .quad   .L2     ## 5
    .quad   .L5     ## 6
*/

void switch2(short x, short *dest) {
    short val = 0;
    switch (x) {
        case -1:
        case 6:

        case 0:

        case 1:
        case 3:

        case 4:

        case -2:

        default:
    }
    *dest = val;
}
