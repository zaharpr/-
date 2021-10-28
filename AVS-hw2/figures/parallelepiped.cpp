//------------------------------------------------------------------------------
// parallelepiped.cpp - содержит функции обработки параллелепипеда.
//------------------------------------------------------------------------------

#include "parallelepiped.h"

//------------------------------------------------------------------------------
void Parallelepiped::In(FILE *ifst) {
    int aValue;
    int bValue;
    int cValue;
    if (fscanf(ifst, "%d%d%d", &aValue, &bValue, &cValue) != EOF) {
        this->a = aValue;
        this->b = bValue;
        this->c = cValue;
    }
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
    return (double) 2.0 * (this->a * this->b + this->b * this->c + this->a * this->c);
}
