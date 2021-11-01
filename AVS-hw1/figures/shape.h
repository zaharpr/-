#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры.
//------------------------------------------------------------------------------

#include "sphere.h"
#include "parallelepiped.h"
#include "tetrahedron.h"

//------------------------------------------------------------------------------
// Класс, обобщающая все имеющиеся фигуры.
struct shape {
    // Общий параметр - плотность.
    double density;
    // Значения ключей для каждой из фигур.
    enum key {
        SPHERE, PARALLELEPIPED, TETRAHEDRON
    } type_of_shape; // Ключ.
    // Используемые альтернативы.
    union { // Используем простейшую реализацию.
        struct sphere s;
        struct parallelepiped p;
        struct tetrahedron t;
    };
};

// Ввод обобщенной фигуры.
shape *In(FILE *ifdt);

// Случайный ввод обобщенной фигуры.
shape *InRnd();

// Вывод обобщенной фигуры.
void Out(shape &s, FILE *ofst);

// Вычисление периметра обобщенной фигуры.
double SurfaceArea(shape &s);

#endif
