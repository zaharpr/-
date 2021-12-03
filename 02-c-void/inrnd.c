//------------------------------------------------------------------------------
// inrnd.c - единица компиляции, вбирающая функции генерации случайных данных.
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "data.h"

int Random() {
    return rand() % 20 + 1;
}

double RandomDouble() {
    return ((double) rand() * (20 - 0.1)) / (double) RAND_MAX + 0.1;
}

// Случайный ввод параметров параллелепипеда.
void InRndParallelepiped(void *p) {
//    double density = RandomDouble();
    *((double *) p) = RandomDouble();

    int a = Random();
    *((int *) (p + doubleSize)) = a;
    int b = Random();
    *((int *) (p + doubleSize + intSize)) = b;
    int c = Random();
    *((int *) (p + doubleSize + intSize + intSize)) = c;
}

// Случайный ввод параметров тетраэдра.
void InRndTetrahedron(void *t) {
//    double density = RandomDouble();
    *((double *) t) = RandomDouble();

    int a = Random();
    *((int *) (t + doubleSize)) = a;
}

// Случайный ввод параметров шара.
void InRndSphere(void *s) {
//    double density = RandomDouble();
    *((double *) s) = RandomDouble();

    int a = Random();
    *((int *) (s + doubleSize)) = a;
}

// Случайный ввод обобщенной фигуры.
int InRndShape(void *s) {
    int k = rand() % 3 + 1;
    switch (k) {
        case 1:
            *((int *) s) = PARALLELEPIPED;
            InRndParallelepiped(s + intSize);
            return 1;
        case 2:
            *((int *) s) = TETRAHEDRON;
            InRndTetrahedron(s + intSize);
        case 3:
            *((int *) s) = SPHERE;
            InRndSphere(s + intSize);
            return 1;
        default:
            return 0;
    }
}

// Случайный ввод содержимого контейнера.
void InRndContainer(void *c, int *len, int size) {
    void *tmp = c;
    while (*len < size) {
        if (InRndShape(tmp)) {
            tmp = tmp + shapeSize;
            (*len)++;
        }
    }
}
