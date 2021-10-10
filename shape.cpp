//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "shape.h"

//-----------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
shape *In(ifstream &ifst) {
    shape *sp;
    int k;
    ifst >> k >> sp->density;
    switch (k) {
        case 1:
            sp = new shape;
            sp->k = shape::SPHERE;
            In(sp->s, ifst);
            return sp;
        case 2:
            sp = new shape;
            sp->k = shape::PARALLELEPIPED;
            In(sp->p, ifst);
            return sp;
        case 3:
            sp = new shape;
            sp->k = shape::TETRAHEDRON;
            In(sp->t, ifst);
            return sp;
        default:
            return 0;
    }
}

// Случайный ввод обобщенной фигуры
shape *InRnd() {
    shape *sp;
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            sp = new shape;
            sp->k = shape::SPHERE;
            InRnd(sp->s);
            return sp;
        case 2:
            sp = new shape;
            sp->k = shape::PARALLELEPIPED;
            InRnd(sp->p);
            return sp;
        case 3:
            sp = new shape;
            sp->k = shape::TETRAHEDRON;
            InRnd(sp->t);
            return sp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(shape &s, ofstream &ofst) {
    switch (s.k) {
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
            ofst << "Incorrect figure!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double SurfaceArea(shape &s) {
    switch (s.k) {
        case shape::SPHERE:
            return SurfaceArea(s.s);
            break;
        case shape::PARALLELEPIPED:
            return SurfaceArea(s.p);
            break;
        case shape::TETRAHEDRON:
            return SurfaceArea(s.t);
            break;
        default:
            return 0.0;
    }
}
