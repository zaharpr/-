//------------------------------------------------------------------------------
// tetrahedron_In.cpp - содержит процедуру ввода параметров
// для уже созданного тетраэдра.
//------------------------------------------------------------------------------

#include "tetrahedron.h"
#include "math.h"

//------------------------------------------------------------------------------
void In(tetrahedron &t, FILE *ifst) {
    int aValue;
    if (fscanf(ifst, "%d", &aValue) != EOF) {
        t.a = aValue;
    }
}

void InRnd(tetrahedron &t) {
    t.a = Random();
}

//------------------------------------------------------------------------------
void Out(tetrahedron &t, FILE *ofst) {
    fprintf(ofst, "It is Tetrahedron: a = %d. SurfaceArea = %f.\n", t.a, SurfaceArea(t));
}

//------------------------------------------------------------------------------
double SurfaceArea(tetrahedron &t) {
    return (double) std::sqrt(3) * t.a * t.a;
}
