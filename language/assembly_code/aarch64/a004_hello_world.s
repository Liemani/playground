.global _main
.align 2

_main:
  b _printf
  b _terminate

_printf:
  mov X0, #1          // stdout
  adr X1, helloworld  // address of hello world string
  mov X2, #13         // length of hello world string
  mov X16, #4         // write to stdout
  svc 0               // syscall

_reboot:
  mov X0, #1    // instant reboot
  mov X16, #55  // reboot
  svc 0         // syscall

_terminate:
  mov X0, #0  // return 0
  mov X16, #1 // terminate
  svc 0       // syscall

helloworld:
.ascii "Hello, world\n"


//.global _main
//.align 2
//
//_main:
//  mov X0, #0  // return 0
//  mov X16, #1 // terminate
//  svc 0       // syscall
