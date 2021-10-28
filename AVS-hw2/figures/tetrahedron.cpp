//------------------------------------------------------------------------------
// tetrahedron.cpp - содержит функции обработки тетраэдра.
//------------------------------------------------------------------------------

#include "tetrahedron.h"
#include "math.h"

//------------------------------------------------------------------------------
void Tetrahedron::In(FILE *ifst) {
    int aValue;
    if (fscanf(ifst, "%d", &aValue) != EOF) {
        this->a = aValue;
    }
}

void Tetrahedron::InRnd() {
    a = rand() % 20 + 1;
}

void Tetrahedron::Out(FILE *ofst) {
    fprintf(ofst, "It is Tetrahedron: a = %d, density = %f."
                  " SurfaceArea = %f.\n", a, density, SurfaceArea());
}

double Tetrahedron::SurfaceArea() {
    return (double) std::sqrt(3) * this->a * this->a;
}
