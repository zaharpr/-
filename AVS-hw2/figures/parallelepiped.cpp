//------------------------------------------------------------------------------
// parallelepiped.cpp - содержит функции обработки параллелепипеда.
//------------------------------------------------------------------------------

#include "parallelepiped.h"

//------------------------------------------------------------------------------
void Parallelepiped::In(FILE *ifst) {
    if (fscanf(ifst, "%d %d %d", &a, &b, &c) != EOF) {}
}

void Parallelepiped::InRnd() {
    a = rand() % 20 + 1;
    b = rand() % 20 + 1;
    c = rand() % 20 + 1;
}

void Parallelepiped::Out(FILE *ofst) {
    fprintf(ofst, "It is Parallelepiped: a = %d, b = %d, c = %d, density = %f."
                  " SurfaceArea = %f.\n", a, b, c, density, SurfaceArea());
}

double Parallelepiped::SurfaceArea() {
    return (double) 2.0 * (a * b + b * c + a * c);
}

