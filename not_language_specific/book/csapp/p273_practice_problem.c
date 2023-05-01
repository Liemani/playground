/*
## void switcher(long a, long b, long c, long *dest)
## a in %rsi, b in %rdi, c in %rdx, d in %rcx

switcher:
    cmpq    $7, %rdi
    ja      .L2
    jmp     *.L4(,%rdi,8)
    .section    .rodata
.L7:
    xorq    $15, %rsi
    movq    %rsi, %rdx
.L3:
    leaq    112(%rdx), %rdi
    jmp     .L6
.L5:
    leaq    (%rdx,%rsi), %rdi
    salq    $2, %rdi
    jmp     .L6
.L2:
    movq    %rsi, %rdi
.L6:
    movq    %rdi, (%rcx)
    ret
.L4:
    .quad   .L3 ## 0
    .quad   .L2 ## 1
    .quad   .L5 ## 2
    .quad   .L2 ## 3
    .quad   .L6 ## 4
    .quad   .L7 ## 5
    .quad   .L2 ## 6
    .quad   .L5 ## 7
*/

void switcher(long a, long b, long c, long *dest) {
    long val;
    switch (a) {
        case 5:
            c = b ^ 15;
        case 0:
            val = c + 112;
            break;
        case 2:
        case 7:
            val = (c + b) << 2;
            break;
        case 4:
            val = a;
            break;
// .L2:
//          case 1:
//          case 3:
//          case 6:
        default:
            val = b;
    }
    *dest = val;
}
