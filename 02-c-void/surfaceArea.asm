;----------------------------------------------------------------------------------------
; surfaceArea.asm - единица компиляции, вбирающая функции вычисления площади поверхности.
;----------------------------------------------------------------------------------------

extern PARALLELEPIPED
extern TETRAHEDRON
extern SPHERE

global SurfaceAreaParallelepiped
SurfaceAreaParallelepiped:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес параллелепипеда.
    mov eax, [rdi+8] ; a.
    imul eax, [rdi+12] ; b.
    mov ebx, [rdi+8] ; a.
    imul ebx, [rdi+16] ; c.
    add eax, ebx
    mov ebx, [rdi+16] ; c.
    imul ebx, [rdi+12] ; b.
    add eax, ebx
    imul eax, 2

leave
ret

global SurfaceAreaTetrahedron
SurfaceAreaTetrahedron:
section .data
.i4     dq      4
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес тетраэдра.
    mov eax, [rdi+8]
    mov ebx, eax
    imul eax, ebx
    imul eax, 2
    idiv qword[.i4]
    mov eax, edx

leave
ret

global SurfaceAreaSphere
SurfaceAreaSphere:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес шара.
    mov eax, [rdi+8]
    mov ebx, eax
    imul eax, ebx
    imul eax, 3
    imul eax, 4

leave
ret

global SurfaceAreaShape
SurfaceAreaShape:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес фигуры
    mov eax, [rdi]
    cmp eax, [PARALLELEPIPED]
    je .paralSurfaceArea
    cmp eax, [TETRAHEDRON]
    je .tetrSurfaceArea
    cmp eax, [SPHERE]
    je .sphereSurfaceArea
    xor eax, eax
    cvtsi2sd    xmm0, eax
    jmp     .return

.paralSurfaceArea:
    ; Вычисление площади поверхности параллелепипеда.
    add     rdi, 4
    call    SurfaceAreaParallelepiped
    jmp     .return

.tetrSurfaceArea:
    ; Вычисление площади поверхности тетраэдра.
    add     rdi, 4
    call    SurfaceAreaTetrahedron
    jmp     .return

.sphereSurfaceArea:
    ; Вычисление площади поверхности шара.
    add     rdi, 4
    call    SurfaceAreaSphere
    jmp     .return

.return:

leave
ret