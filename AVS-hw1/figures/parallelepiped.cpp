//------------------------------------------------------------------------------
// parallelepiped.cpp - содержит функции обработки параллелепипеда.
//------------------------------------------------------------------------------

#include "parallelepiped.h"

//------------------------------------------------------------------------------
void In(parallelepiped &p, FILE *ifst) {
    int aValue;
    int bValue;
    int cValue;
    if (fscanf(ifst, "%d%d%d", &aValue, &bValue, &cValue) != EOF) {
        p.a = aValue;
        p.b = bValue;
        p.c = cValue;
    }
}

void InRnd(parallelepiped &p) {
    p.a = Random();
    p.b = Random();
    p.c = Random();
}

//------------------------------------------------------------------------------
void Out(parallelepiped &p, FILE *ofst) {
    fprintf(ofst, "It is Parallelepiped: a = %d, b = %d, c = %d. SurfaceArea = %f.\n",
            p.a, p.b, p.c,
            SurfaceArea(p));
}

//------------------------------------------------------------------------------
double SurfaceArea(parallelepiped &p) {
    return (double) 2.0 * (p.a * p.b + p.b * p.c + p.a * p.c);
}
