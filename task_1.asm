section .rodata
fmt: dq "%lld ",  0

section .text
extern scanf
extern printf
extern puts
extern malloc
extern free

global main
    
main:
    mov rbp, rsp; for correct debugging
push rsi
push rbp

mov rbp, rsp; for correct debugging

sub rsp, 8 + 32

lea rcx, [fmt] 
lea rdx, [rbp - 8] 
call scanf

mov rcx, 100
call malloc
mov rsi, rax
    
mov r12, 0

start_in:                       
cmp r12, [rbp-8]
jge end_in
lea rcx, [fmt] 
lea rdx, [rsi + r12*8] 
call scanf

add r12, 1
jmp start_in
end_in:

mov rbx, 0
bbsort_start:
    mov r9, [rbp - 8]
    sub r9, 1
    cmp rbx, r9
    jge bbsort_end
    mov rcx, 0
iter_bbsort_start:
    mov r10, r9
    sub r10, rbx
    cmp rcx, r10
    jge iter_bbsort_end
    mov r11, [rsi + 8*rcx]
    mov r14, rcx
    imul r14, 8
    mov r12, [rsi + r14 + 8]
    cmp r11, r12
    jle comp_end
    mov r13, r11
    mov [rsi + 8*rcx], r12
    mov [rsi + 8*rcx+8], r13
comp_end:
    inc rcx
    jmp iter_bbsort_start
iter_bbsort_end:
    inc rbx
    jmp bbsort_start
bbsort_end:
;bb_sort_end

mov r12, 0
start_out:    
cmp r12, [rbp-8]
jge end_out  
lea rcx, [fmt]
mov rdx, [rsi + r12*8] 
call printf

add r12, 1
jmp start_out
end_out:
    
mov rcx, rsi
call free
        
leave
mov rbp, rsp
pop rsi
ret