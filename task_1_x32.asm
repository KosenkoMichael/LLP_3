section .rodata
fmt: dq "%d ",  0

section .text
extern scanf
extern printf
extern puts
extern malloc
extern free

global main
    
main:
mov ebp, esp; for correct debugging
push edi
push esi
push ebx
push ebp

mov ebp, esp; for correct debugging

sub esp, 4 + 8

; esp = arg1
; esp + 4 = arg2
; ebp - 4 = arrsize
; callee saved = ebx, eci, edi

lea eax, [fmt]
mov [esp], eax
lea eax, [ebp - 4]
mov [esp + 4], eax
call scanf

mov dword[esp], 100
call malloc
mov esi, eax

mov ebx, 0

start_in:                       
cmp ebx, [ebp-4]
jge end_in
lea eax, [fmt]
mov [esp], eax
lea eax, [esi + ebx*4] 
mov [esp + 4], eax
call scanf

add ebx, 1
jmp start_in
end_in:

sub dword[ebp - 4], 1
; bbsort start

;eax
;ebx = i
;ecx = j
;edx
;esi = arrray
;edi

mov ebx, 0
bbsort_start:
    cmp ebx, dword[ebp - 4]
    jge bbsort_end
    mov ecx, 0
iter_bbsort_start:
    mov eax, dword[ebp - 4]
    sub eax, ebx
    cmp ecx, eax
    jge iter_bbsort_end
    mov edx, [esi + 4*ecx]
    mov edi, [esi + 4*ecx + 4]
    cmp edx, edi
    jle comp_end
    mov [esi + 4*ecx], edi
    mov [esi + 4*ecx+4], edx
comp_end:
    inc ecx
    jmp iter_bbsort_start
iter_bbsort_end:
    inc ebx
    jmp bbsort_start
bbsort_end:

; bbsort end
add dword[ebp - 4], 1
mov ebx, 0

start_out:    
cmp ebx, [ebp-4]
jge end_out  
lea eax, [fmt]
mov [esp], eax
mov eax, [esi + ebx*4] 
mov [esp + 4], eax
call printf

add ebx, 1
jmp start_out
end_out:
    
mov [esp], esi
call free
        
leave
mov ebp, esp
pop ebx
pop esi
pop edi
ret