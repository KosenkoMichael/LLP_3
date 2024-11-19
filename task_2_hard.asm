%include "io64.inc"
section .text

extern access3

global main

main:
    mov rbp, rsp; for correct debugging
    
    sub rsp, 100

mov dword[rsp + 8], 1 ; for rcx
lea rcx, byte[rsp + 8] ; for byte[r9] to set NON ZERO
mov dword[rdx + 8], 10 ; for loc_4017B5 positive branch
mov dword[rcx + 0Ch], 11111116 ; for CMP with EDX

mov dword[rdx], 10 ; for loc_4017AE5 negative branch

call access3

add rsp, 100

ret