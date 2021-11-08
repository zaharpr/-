//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры.
//------------------------------------------------------------------------------

#include "shape.h"

//-----------------------------------------------------------------------------
shape *In(FILE *ifst) {
    shape *sp = new shape;
    int type_of_shape;
    float density_value;

    if (fscanf(ifst, "%d%f", &type_of_shape, &density_value) == EOF) {
        return nullptr;
    }

    switch (type_of_shape) {
        case 1:
            sp->type_of_shape = shape::PARALLELEPIPED;
            sp->density = density_value;
            In(sp->p, ifst);
            return sp;
        case 2:
            sp->type_of_shape = shape::TETRAHEDRON;
            sp->density = density_value;
            In(sp->t, ifst);
            return sp;
        case 3:
            sp->type_of_shape = shape::SPHERE;
            sp->density = density_value;
            In(sp->s, ifst);
            return sp;
        default:
            return 0;
    }
}

shape *InRnd() {
    shape *sp = new shape;
    auto type_of_shape = rand() % 3 + 1;
    switch (type_of_shape) {
        case 1:
            sp->type_of_shape = shape::PARALLELEPIPED;
            sp->density = RandomDouble();
            InRnd(sp->p);
            return sp;
        case 2:
            sp->type_of_shape = shape::TETRAHEDRON;
            sp->density = RandomDouble();
            InRnd(sp->t);
            return sp;
        case 3:
            sp->type_of_shape = shape::SPHERE;
            sp->density = RandomDouble();
            InRnd(sp->s);
            return sp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
void Out(shape &s, FILE *ofst) {
    switch (s.type_of_shape) {
        case shape::SPHERE:
            Out(s.s, ofst);
            break;
        case shape::PARALLELEPIPED:
            Out(s.p, ofst);
            break;
        case shape::TETRAHEDRON:
            Out(s.t, ofst);
            break;
        default:
            fprintf(ofst, "Incorrect figure!\n");
            return;
    }
}

//------------------------------------------------------------------------------
double SurfaceArea(shape &s) {
    switch (s.type_of_shape) {
        case shape::SPHERE:
            return SurfaceArea(s.s);
        case shape::PARALLELEPIPED:
            return SurfaceArea(s.p);
        case shape::TETRAHEDRON:
            return SurfaceArea(s.t);
        default:
            return 0.0;
    }
}
