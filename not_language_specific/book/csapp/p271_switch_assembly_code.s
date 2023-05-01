switch_eg:
    subq    $100, %rsi
    cmpq    $6, %rsi
    ja      loc_def
    jmp     *jt(, %rsi, 8)
loc_A:
    imulq   $13, %rdi
    jmp     done
loc_B:
    addq    $10, %rdi
loc_C:
    addq    $11, %rdi
    jmp     done
loc_D:
    imulq   %rdi, %rdi
    jmp     done
loc_def:
    movl    $0, %edi
done:
    movq   %rdi, (%rdx)
    ret

    .section    .rodata
    .align 8            ## Align address to multiple of 8
jt:
    .quad   loc_A       ## Case 100: loc_A
    .quad   loc_def     ## Case 101: loc_def
    .quad   loc_B       ## Case 102: loc_B
    .quad   loc_C       ## Case 103: loc_C
    .quad   loc_D       ## Case 104: loc_D
    .quad   loc_def     ## Case 105: loc_def
    .quad   loc_D       ## Case 106: loc_D
