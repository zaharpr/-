//------------------------------------------------------------------------------
// perimeter.c - единица компиляции, вбирающая функции вычисления периметра.
//------------------------------------------------------------------------------

#include <memory.h>
#include "extdata.h"
#include "math.h"

// Вычисление площади поверхности параллелепипеда.
double SurfaceAreaParallelepiped(void *p) {
    return 2.0 * (*((int *) (p + doubleSize)) * *((int *) (p + doubleSize + intSize)) +
                  *((int *) (p + doubleSize)) * *((int *) (p + doubleSize + (2 * intSize))) +
                  *((int *) (p + doubleSize + intSize)) * *((int *) (p + doubleSize + (2 * intSize))));
}

// Вычисление площади поверхности тетраэдра.
double SurfaceAreaTetrahedron(void *t) {
    return (double) (sqrt(3) * *((int *) (t + doubleSize)) * *((int *) (t + doubleSize)));
}

// Вычисление площади поверхности шара.
double SurfaceAreaSphere(void *s) {
    return (double) (4 * 3.1415 * *((int *) (s + doubleSize)) * *((int *) (s + doubleSize)));
}

// Вычисление площади поверхности фигуры.
double SurfaceAreaShape(void *s) {
    int k = *((int *) s);
    if (k == PARALLELEPIPED) {
        return SurfaceAreaParallelepiped(s + intSize);
    } else if (k == TETRAHEDRON) {
        return SurfaceAreaTetrahedron(s + intSize);
    } else if (k == SPHERE) {
        return SurfaceAreaSphere(s + intSize);
    } else {
        return 0.0;
    }
}

// Сортировка Шелла по убыванию.
void ShellSort(void *cont, int len) {
    int i, j, k;
    void *temp;
    for (i = len / 2; i > 0; i = i / 2) {
        for (j = i; j < len; j++) {
            for (k = j - i; k >= 0; k = k - i) {
                void *first = cont + (shapeSize * (k + i));
                void *second = cont + (shapeSize * k);
                if (SurfaceAreaShape(first) <= SurfaceAreaShape(second)) {
                    break;
                } else {
                    char temp[shapeSize];
                    memcpy(temp, second, shapeSize);
                    memcpy(second, first, shapeSize);
                    memcpy(first, temp, shapeSize);
                }
            }
        }
    }
}