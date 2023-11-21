.global _main
.align 2

_main:
  mov X0, #1          // 1 is StdOut
  adr X1, helloworld  // string to print
  mov X2, #13         // length of our string
  mov X16, #4         // Unix write system call
  svc #0x80           // Call Linux to output the string

  mov X0, #0          // Use 0 return code
  mov X16, #1         // Service code 1 terminates
  svc #0x80           // Call Linux to terminate

helloworld:
.ascii "Hello World!\n"
