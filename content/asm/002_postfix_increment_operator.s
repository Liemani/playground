	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 0
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
Lfunc_begin0:
	.file	1 "/Users/bagjeonghun/git/playground/content/asm" "002_postfix_increment_operator.c"
	.loc	1 3 0                           ; 002_postfix_increment_operator.c:3:0
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80                     ; =80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64                    ; =64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	str	wzr, [sp, #20]
	sub	x8, x29, #24                    ; =24
Ltmp0:
	.loc	1 6 7 prologue_end              ; 002_postfix_increment_operator.c:6:7
	str	x8, [sp, #8]
	add	x8, sp, #24                     ; =24
	.loc	1 7 7                           ; 002_postfix_increment_operator.c:7:7
	str	x8, [sp]
	.loc	1 11 17                         ; 002_postfix_increment_operator.c:11:17
	ldr	x8, [sp]
	add	x9, x8, #4                      ; =4
	str	x9, [sp]
	.loc	1 11 12 is_stmt 0               ; 002_postfix_increment_operator.c:11:12
	ldr	w8, [x8]
	.loc	1 11 7                          ; 002_postfix_increment_operator.c:11:7
	ldr	x9, [sp, #8]
	add	x10, x9, #4                     ; =4
	str	x10, [sp, #8]
	.loc	1 11 10                         ; 002_postfix_increment_operator.c:11:10
	str	w8, [x9]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	ldur	x9, [x29, #-8]
	subs	x8, x8, x9
	b.ne	LBB0_2
; %bb.1:
	.loc	1 0 10                          ; 002_postfix_increment_operator.c:0:10
	mov	w0, #0
	.loc	1 12 2 is_stmt 1                ; 002_postfix_increment_operator.c:12:2
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80                     ; =80
	ret
LBB0_2:
	.loc	1 0 0 is_stmt 0                 ; 002_postfix_increment_operator.c:0:0
	bl	___stack_chk_fail
Ltmp1:
Lfunc_end0:
	.cfi_endproc
                                        ; -- End function
	.section	__DWARF,__debug_abbrev,regular,debug
Lsection_abbrev:
	.byte	1                               ; Abbreviation Code
	.byte	17                              ; DW_TAG_compile_unit
	.byte	1                               ; DW_CHILDREN_yes
	.byte	37                              ; DW_AT_producer
	.byte	14                              ; DW_FORM_strp
	.byte	19                              ; DW_AT_language
	.byte	5                               ; DW_FORM_data2
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.ascii	"\202|"                         ; DW_AT_LLVM_sysroot
	.byte	14                              ; DW_FORM_strp
	.ascii	"\357\177"                      ; DW_AT_APPLE_sdk
	.byte	14                              ; DW_FORM_strp
	.byte	16                              ; DW_AT_stmt_list
	.byte	23                              ; DW_FORM_sec_offset
	.byte	27                              ; DW_AT_comp_dir
	.byte	14                              ; DW_FORM_strp
	.byte	17                              ; DW_AT_low_pc
	.byte	1                               ; DW_FORM_addr
	.byte	18                              ; DW_AT_high_pc
	.byte	6                               ; DW_FORM_data4
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	2                               ; Abbreviation Code
	.byte	46                              ; DW_TAG_subprogram
	.byte	1                               ; DW_CHILDREN_yes
	.byte	17                              ; DW_AT_low_pc
	.byte	1                               ; DW_FORM_addr
	.byte	18                              ; DW_AT_high_pc
	.byte	6                               ; DW_FORM_data4
	.byte	64                              ; DW_AT_frame_base
	.byte	24                              ; DW_FORM_exprloc
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.byte	58                              ; DW_AT_decl_file
	.byte	11                              ; DW_FORM_data1
	.byte	59                              ; DW_AT_decl_line
	.byte	11                              ; DW_FORM_data1
	.byte	39                              ; DW_AT_prototyped
	.byte	25                              ; DW_FORM_flag_present
	.byte	73                              ; DW_AT_type
	.byte	19                              ; DW_FORM_ref4
	.byte	63                              ; DW_AT_external
	.byte	25                              ; DW_FORM_flag_present
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	3                               ; Abbreviation Code
	.byte	52                              ; DW_TAG_variable
	.byte	0                               ; DW_CHILDREN_no
	.byte	2                               ; DW_AT_location
	.byte	24                              ; DW_FORM_exprloc
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.byte	58                              ; DW_AT_decl_file
	.byte	11                              ; DW_FORM_data1
	.byte	59                              ; DW_AT_decl_line
	.byte	11                              ; DW_FORM_data1
	.byte	73                              ; DW_AT_type
	.byte	19                              ; DW_FORM_ref4
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	4                               ; Abbreviation Code
	.byte	36                              ; DW_TAG_base_type
	.byte	0                               ; DW_CHILDREN_no
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.byte	62                              ; DW_AT_encoding
	.byte	11                              ; DW_FORM_data1
	.byte	11                              ; DW_AT_byte_size
	.byte	11                              ; DW_FORM_data1
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	5                               ; Abbreviation Code
	.byte	1                               ; DW_TAG_array_type
	.byte	1                               ; DW_CHILDREN_yes
	.byte	73                              ; DW_AT_type
	.byte	19                              ; DW_FORM_ref4
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	6                               ; Abbreviation Code
	.byte	33                              ; DW_TAG_subrange_type
	.byte	0                               ; DW_CHILDREN_no
	.byte	73                              ; DW_AT_type
	.byte	19                              ; DW_FORM_ref4
	.byte	55                              ; DW_AT_count
	.byte	11                              ; DW_FORM_data1
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	7                               ; Abbreviation Code
	.byte	36                              ; DW_TAG_base_type
	.byte	0                               ; DW_CHILDREN_no
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.byte	11                              ; DW_AT_byte_size
	.byte	11                              ; DW_FORM_data1
	.byte	62                              ; DW_AT_encoding
	.byte	11                              ; DW_FORM_data1
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	8                               ; Abbreviation Code
	.byte	15                              ; DW_TAG_pointer_type
	.byte	0                               ; DW_CHILDREN_no
	.byte	73                              ; DW_AT_type
	.byte	19                              ; DW_FORM_ref4
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	0                               ; EOM(3)
	.section	__DWARF,__debug_info,regular,debug
Lsection_info:
Lcu_begin0:
.set Lset0, Ldebug_info_end0-Ldebug_info_start0 ; Length of Unit
	.long	Lset0
Ldebug_info_start0:
	.short	4                               ; DWARF version number
.set Lset1, Lsection_abbrev-Lsection_abbrev ; Offset Into Abbrev. Section
	.long	Lset1
	.byte	8                               ; Address Size (in bytes)
	.byte	1                               ; Abbrev [1] 0xb:0x99 DW_TAG_compile_unit
	.long	0                               ; DW_AT_producer
	.short	12                              ; DW_AT_language
	.long	47                              ; DW_AT_name
	.long	80                              ; DW_AT_LLVM_sysroot
	.long	175                             ; DW_AT_APPLE_sdk
.set Lset2, Lline_table_start0-Lsection_line ; DW_AT_stmt_list
	.long	Lset2
	.long	186                             ; DW_AT_comp_dir
	.quad	Lfunc_begin0                    ; DW_AT_low_pc
.set Lset3, Lfunc_end0-Lfunc_begin0     ; DW_AT_high_pc
	.long	Lset3
	.byte	2                               ; Abbrev [2] 0x32:0x52 DW_TAG_subprogram
	.quad	Lfunc_begin0                    ; DW_AT_low_pc
.set Lset4, Lfunc_end0-Lfunc_begin0     ; DW_AT_high_pc
	.long	Lset4
	.byte	1                               ; DW_AT_frame_base
	.byte	109
	.long	232                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	2                               ; DW_AT_decl_line
                                        ; DW_AT_prototyped
	.long	132                             ; DW_AT_type
                                        ; DW_AT_external
	.byte	3                               ; Abbrev [3] 0x4b:0xe DW_TAG_variable
	.byte	2                               ; DW_AT_location
	.byte	145
	.byte	104
	.long	241                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	4                               ; DW_AT_decl_line
	.long	139                             ; DW_AT_type
	.byte	3                               ; Abbrev [3] 0x59:0xe DW_TAG_variable
	.byte	2                               ; DW_AT_location
	.byte	143
	.byte	24
	.long	268                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	5                               ; DW_AT_decl_line
	.long	139                             ; DW_AT_type
	.byte	3                               ; Abbrev [3] 0x67:0xe DW_TAG_variable
	.byte	2                               ; DW_AT_location
	.byte	143
	.byte	8
	.long	275                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	6                               ; DW_AT_decl_line
	.long	158                             ; DW_AT_type
	.byte	3                               ; Abbrev [3] 0x75:0xe DW_TAG_variable
	.byte	2                               ; DW_AT_location
	.byte	143
	.byte	0
	.long	280                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	7                               ; DW_AT_decl_line
	.long	158                             ; DW_AT_type
	.byte	0                               ; End Of Children Mark
	.byte	4                               ; Abbrev [4] 0x84:0x7 DW_TAG_base_type
	.long	237                             ; DW_AT_name
	.byte	5                               ; DW_AT_encoding
	.byte	4                               ; DW_AT_byte_size
	.byte	5                               ; Abbrev [5] 0x8b:0xc DW_TAG_array_type
	.long	132                             ; DW_AT_type
	.byte	6                               ; Abbrev [6] 0x90:0x6 DW_TAG_subrange_type
	.long	151                             ; DW_AT_type
	.byte	4                               ; DW_AT_count
	.byte	0                               ; End Of Children Mark
	.byte	7                               ; Abbrev [7] 0x97:0x7 DW_TAG_base_type
	.long	248                             ; DW_AT_name
	.byte	8                               ; DW_AT_byte_size
	.byte	7                               ; DW_AT_encoding
	.byte	8                               ; Abbrev [8] 0x9e:0x5 DW_TAG_pointer_type
	.long	132                             ; DW_AT_type
	.byte	0                               ; End Of Children Mark
Ldebug_info_end0:
	.section	__DWARF,__debug_str,regular,debug
Linfo_string:
	.asciz	"Apple clang version 13.0.0 (clang-1300.0.29.3)" ; string offset=0
	.asciz	"002_postfix_increment_operator.c" ; string offset=47
	.asciz	"/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk" ; string offset=80
	.asciz	"MacOSX.sdk"                    ; string offset=175
	.asciz	"/Users/bagjeonghun/git/playground/content/asm" ; string offset=186
	.asciz	"main"                          ; string offset=232
	.asciz	"int"                           ; string offset=237
	.asciz	"array1"                        ; string offset=241
	.asciz	"__ARRAY_SIZE_TYPE__"           ; string offset=248
	.asciz	"array2"                        ; string offset=268
	.asciz	"ptr1"                          ; string offset=275
	.asciz	"ptr2"                          ; string offset=280
	.section	__DWARF,__apple_names,regular,debug
Lnames_begin:
	.long	1212240712                      ; Header Magic
	.short	1                               ; Header Version
	.short	0                               ; Header Hash Function
	.long	1                               ; Header Bucket Count
	.long	1                               ; Header Hash Count
	.long	12                              ; Header Data Length
	.long	0                               ; HeaderData Die Offset Base
	.long	1                               ; HeaderData Atom Count
	.short	1                               ; DW_ATOM_die_offset
	.short	6                               ; DW_FORM_data4
	.long	0                               ; Bucket 0
	.long	2090499946                      ; Hash in Bucket 0
.set Lset5, LNames0-Lnames_begin        ; Offset in Bucket 0
	.long	Lset5
LNames0:
	.long	232                             ; main
	.long	1                               ; Num DIEs
	.long	50
	.long	0
	.section	__DWARF,__apple_objc,regular,debug
Lobjc_begin:
	.long	1212240712                      ; Header Magic
	.short	1                               ; Header Version
	.short	0                               ; Header Hash Function
	.long	1                               ; Header Bucket Count
	.long	0                               ; Header Hash Count
	.long	12                              ; Header Data Length
	.long	0                               ; HeaderData Die Offset Base
	.long	1                               ; HeaderData Atom Count
	.short	1                               ; DW_ATOM_die_offset
	.short	6                               ; DW_FORM_data4
	.long	-1                              ; Bucket 0
	.section	__DWARF,__apple_namespac,regular,debug
Lnamespac_begin:
	.long	1212240712                      ; Header Magic
	.short	1                               ; Header Version
	.short	0                               ; Header Hash Function
	.long	1                               ; Header Bucket Count
	.long	0                               ; Header Hash Count
	.long	12                              ; Header Data Length
	.long	0                               ; HeaderData Die Offset Base
	.long	1                               ; HeaderData Atom Count
	.short	1                               ; DW_ATOM_die_offset
	.short	6                               ; DW_FORM_data4
	.long	-1                              ; Bucket 0
	.section	__DWARF,__apple_types,regular,debug
Ltypes_begin:
	.long	1212240712                      ; Header Magic
	.short	1                               ; Header Version
	.short	0                               ; Header Hash Function
	.long	2                               ; Header Bucket Count
	.long	2                               ; Header Hash Count
	.long	20                              ; Header Data Length
	.long	0                               ; HeaderData Die Offset Base
	.long	3                               ; HeaderData Atom Count
	.short	1                               ; DW_ATOM_die_offset
	.short	6                               ; DW_FORM_data4
	.short	3                               ; DW_ATOM_die_tag
	.short	5                               ; DW_FORM_data2
	.short	4                               ; DW_ATOM_type_flags
	.short	11                              ; DW_FORM_data1
	.long	0                               ; Bucket 0
	.long	1                               ; Bucket 1
	.long	193495088                       ; Hash in Bucket 0
	.long	-594775205                      ; Hash in Bucket 1
.set Lset6, Ltypes1-Ltypes_begin        ; Offset in Bucket 0
	.long	Lset6
.set Lset7, Ltypes0-Ltypes_begin        ; Offset in Bucket 1
	.long	Lset7
Ltypes1:
	.long	237                             ; int
	.long	1                               ; Num DIEs
	.long	132
	.short	36
	.byte	0
	.long	0
Ltypes0:
	.long	248                             ; __ARRAY_SIZE_TYPE__
	.long	1                               ; Num DIEs
	.long	151
	.short	36
	.byte	0
	.long	0
.subsections_via_symbols
	.section	__DWARF,__debug_line,regular,debug
Lsection_line:
Lline_table_start0:
