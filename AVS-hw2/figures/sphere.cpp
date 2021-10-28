//------------------------------------------------------------------------------
// sphere.cpp - содержит функции обработки сферы.
//------------------------------------------------------------------------------

#include "sphere.h"

//------------------------------------------------------------------------------
void Sphere::In(FILE *ifst) {
    int rValue;
    if (fscanf(ifst, "%d", &rValue) != EOF) {
        this->r = rValue;
    }
}

void Sphere::InRnd() {
    r = rand() % 20 + 1;
}

void Sphere::Out(FILE *ofst) {
    fprintf(ofst, "It is Sphere: r = %d, density = %f."
                  " SurfaceArea = %f.\n", r, density, SurfaceArea());
}

double Sphere::SurfaceArea() {
    return (double) 4 * 3.1415 * this->r;
}
