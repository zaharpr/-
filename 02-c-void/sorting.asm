
section .text

extern memcpy
extern SurfaceAreaShape

; void ShellSort(void *c, int len)
;     for (int d = len / 2; d > 0; d /= 2)
;         for (int i = d; i < len; i++)
;             for (int j = i; j >= d &&
;                   SurfaceAreaShape(c + j * shape_size) < SurfaceAreaShape(c + (j - d) * shape_size); j -= d) {
;                 void *tmp[shape_size];
;                 memcpy(tmp, c + j * shape_size, shape_size);
;                 memcpy(c + j * languageSize, c + (j - d) * (shape_size), shape_size);
;                 memcpy(c + (j - d) * (shape_size), tmp, shape_size);
;             }

global ShellSort
ShellSort:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 64 ; выделяем место на стеке.
        mov     [rbp - 8], rdi
        mov     [rbp - 12], esi
        mov     eax, [rbp - 12]
        mov     ecx, 2
        cdq
        idiv    ecx
        mov     [rbp - 16], eax
.first_loop:                    ; первый цикл for (int d = len / 2; d > 0; d /= 2)
        cmp     dword [rbp - 16], 0; в случае d <= 0 выходим
        jle     .leave_first_loop;
        mov     eax, [rbp - 16]
        mov     [rbp - 20], eax ; сохраняем значение итератора i.
.second_loop:                   ; второй цикл for (int i = d; i < len; i++)
        mov     eax, [rbp - 20] ; i.
        cmp     eax, [rbp - 12] ; если итератор >= d.
        jge     .step_first_loop
        mov     eax, [rbp - 20]
        mov     [rbp - 24], eax ; j = i.
.third_loop:                    ; третий цикл for (int j = i; j >= d; j -= d).
        mov     eax, [rbp - 24] ; j.
        cmp     eax, [rbp - 16] ; если j < d.
        jl      .step_second_loop
        mov     rdi, [rbp - 8]
        imul    eax, [rbp - 24], 24 ; j * shape_size.
        cdqe
        add     rdi, rax ; c + j * shape_size.
        add     rdi, 4 ;  c + j * shape_size.
        call    SurfaceAreaShape
        movsd   [rbp - 32], xmm0 ; сохраним SurfaceAreaShape(cont[j]).
        mov     rdi, [rbp - 8] ; делаем все то же самое для cont[j - d].
        mov     eax, [rbp - 24]
        sub     eax, [rbp - 16]
        imul    eax, eax, 24
        cdqe
        add     rdi, rax
        add     rdi, 4
        call    SurfaceAreaShape
        movsd   [rbp - 40], xmm0 ; сохраним SurfaceAreaShape(c [j - d]).
        movsd   xmm0, [rbp - 32]
        ucomisd xmm0, [rbp - 40]  ; если SAS1 < SAS2.
        jb      .swap             ; меняем местами элементы.
        jmp     .step_second_loop ; иначе переход на следующую итерацию.
.swap: ; смена элементов местами.
        mov     [rbp - 48], rsp ; запомним место под tmp.
        mov     rdi, rsp ; первый аргумент - tmp.
        add     rdi, -400
        mov     [rbp - 56], rdi
        mov     rsp, rdi
        mov     rsi, [rbp - 8] ; c.
        imul    eax, [rbp - 24], 24 ; j * shape_size.
        cdqe
        add     rsi, rax ; второй аргумент - c + j * shape_size.
        mov     edx, 24 ; третий аргумент - shape_size.
        call    memcpy ; memcpy(tmp, c + j * shape_size, shape_size).
        mov     rdi, [rbp - 8] ; c.
        imul    eax, [rbp - 24], 24 ; j * shape_size.
        cdqe
        add     rdi, rax ; первый аргумет - c + j * shape_size.
        mov     rsi, [rbp - 8] ; то же и для с + (j - d) * (shape_size).
        mov     eax, [rbp - 24]
        sub     eax, [rbp - 16]
        imul    eax, eax, 24
        cdqe
        add     rsi, rax ; второй аргумент - c + (j - d) * (shape_size).
        mov     edx, 24 ; третий аргумент - shape_size.
        call    memcpy ; memcpy(c + j * shape_size, c + (j - d) * (shape_size), shape_size).
        mov     rsi, [rbp - 56] ; полностью аналогичный вызов memcpy(c + (j - d) * (shape_size), tmp, shape_size).
        mov     rdi, [rbp - 8]
        mov     eax, [rbp - 24]
        sub     eax, [rbp - 16]
        imul    eax, eax, 24
        cdqe
        add     rdi, rax
        mov     edx, 24
        call    memcpy ; memcpy(c + (j - d) * (shape_size), tmp, shape_size).
.third_loop_step: ; переход к следущей итерации для третьего цикла.
        mov     ecx, [rbp - 16] ; d
        mov     eax, [rbp - 24] ; j
        sub     eax, ecx ; j - d
        mov     [rbp - 24], eax ; j = j - d;
        mov     rsp, [rbp - 48] ; возвращаем стек обратно.
        jmp     .third_loop
.step_second_loop: ; переход к следущей итерации для второго цикла.
        mov     eax, [rbp - 20] ; i
        inc     eax; i + 1
        mov     [rbp - 20], eax ; i = i + 1
        jmp     .second_loop
.step_first_loop: ; переход к следущей итерации для первого цикла.
        mov     eax, [rbp - 16] ; d
        mov     ecx, 2
        cdq
        idiv    ecx ; d / 2
        mov     [rbp - 16], eax ; d /= 2;
        jmp     .first_loop
.leave_first_loop: ;выход из первого цикла.
        mov     rsp, rbp
        pop     rbp
        ret