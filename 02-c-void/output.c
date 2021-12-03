//------------------------------------------------------------------------------
// output.c - единица компиляции, вбирающая в себя все функции вывода данных.
//------------------------------------------------------------------------------

#include <stdio.h>

#include "data.h"

// Вычисление площади поверхности параллелепипеда.
double SurfaceAreaParallelepiped(void *p);

// Вывод параметров параллелепипеда в файл
void OutParallelepiped(void *p, FILE *ofst) {
    fprintf(ofst, "It is Parallelepiped: a = %d, b = %d, c = %d, density = %lf. SurfaceArea = %lf\n",
            *((int *) p + doubleSize), *((int *) (p + doubleSize + intSize)),
            *((int *) (p + doubleSize + intSize + intSize)),
            *((double *) p), SurfaceAreaParallelepiped(p));
}

// Вычисление площади поверхности тетраэдра.
double SurfaceAreaTetrahedron(void *t);

// Вывод параметров тетраэдра в файл.
void OutTetrahedron(void *t, FILE *ofst) {
    fprintf(ofst, "It is Tetrahedron: a = %d, density = %lf. SurfaceArea = %lf\n",
            *((int *) t + doubleSize), *((double *) t), SurfaceAreaTetrahedron(t));
}

// Вычисление площади поверхности шара.
double SurfaceAreaSphere(void *s);

// Вывод параметров шара в файл.
void OutSphere(void *s, FILE *ofst) {
    fprintf(ofst, "It is Sphere: r = %d, density = %lf. SurfaceArea = %lf\n",
            *((int *) s + doubleSize), *((double *) s), SurfaceAreaSphere(s));
}

// Вывод параметров текущей фигуры в файл.
void OutShape(void *s, FILE *ofst) {
    int k = *((int *) s);
    if (k == PARALLELEPIPED) {
        OutParallelepiped(s + intSize, ofst);
    } else if (k == TETRAHEDRON) {
        OutTetrahedron(s + intSize, ofst);
    } else if (k == SPHERE) {
        OutSphere(s + intSize, ofst);
    } else {
        fprintf(ofst, "Incorrect figure!\n");
    }
}

// Вывод содержимого контейнера в файл.
void OutContainer(void *c, int len, FILE *ofst) {
    void *tmp = c;
    fprintf(ofst, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i);
        OutShape(tmp, ofst);
        tmp += shapeSize;
    }
}
