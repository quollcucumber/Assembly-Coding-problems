asm(R"::(
.text
.globl main
main:
     push %rbp

     # read in a, and b
     lea fmt_in(%rip), %rdi
     lea a(%rip), %rsi
     lea b(%rip), %rdx
     xor %al, %al
     call scanf

     #add it together and store in esi
     mov a(%rip), %esi
     add b(%rip), %esi

     #print esi

     lea fmt_out(%rip), %rdi
     xor %al, %al
     call printf

     xor %eax, %eax
     pop %rbp
     ret
     .data
     fmt_in: .asciz "%d %d"
     fmt_out: .asciz "%d\n"
     .bss
     a: .zero 4
     b: .zero 4
     )::");
