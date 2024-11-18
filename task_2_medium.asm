%include "io64.inc"
section .text

extern access9

global main

main:
    mov rbp, rsp; for correct debugging

sub rsp, 400

mov qword[r8], 55415353h
mov rax, [r8]
mov [rsp+38], rax

mov byte[r8+10], 00h ; SUUU

mov r9, [r8+8]
mov [rsp+40], r9

mov ecx, 1
mov rdx, 0

call access9

add rsp, 400

ret