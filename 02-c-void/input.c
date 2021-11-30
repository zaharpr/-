//------------------------------------------------------------------------------
// input.c - единица компиляции, вбирающая в себя все функции ввода данных.
//------------------------------------------------------------------------------

#include <stdio.h>

#include "extdata.h"

// Ввод параметров параллелепипеда из файла.
void InParallelepiped(void *r, FILE *ifst) {
    fscanf(ifst, "%lf%d%d%d", (double *) r, (int *) (r + doubleSize), (int *) (r + doubleSize + intSize),
           (int *) (r + doubleSize + 2 * intSize));
}

// Ввод параметров тетраэдра из файла.
void InTetrahedron(void *t, FILE *ifst) {
    fscanf(ifst, "%lf%d", (double *) t, (int *) (t + doubleSize));
}

// Ввод параметров шара из файла.
void InSphere(void *s, FILE *ifst) {
    fscanf(ifst, "%lf%d", (double *) s, (int *) (s + doubleSize));
}

// Ввод параметров обобщенной фигуры из файла.
int InShape(void *s, FILE *ifst) {
    int k;
    fscanf(ifst, "%d", &k);
    switch (k) {
        case 1:
            *((int *) s) = PARALLELEPIPED;
            InParallelepiped(s + intSize, ifst);
            return 1;
        case 2:
            *((int *) s) = TETRAHEDRON;
            InTetrahedron(s + intSize, ifst);
            return 1;
        case 3:
            *((int *) s) = SPHERE;
            InSphere(s + intSize, ifst);
            return 1;
        default:
            return 0;
    }
}

// Ввод содержимого контейнера из указанного файла.
void InContainer(void *c, int *len, FILE *ifst) {
    void *tmp = c;
    while (!feof(ifst)) {
        if (InShape(tmp, ifst)) {
            tmp = tmp + shapeSize;
            (*len)++;
        }
    }
}
