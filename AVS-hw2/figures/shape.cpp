//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры.
//------------------------------------------------------------------------------

#include "shape.h"
#include "parallelepiped.h"
#include "sphere.h"
#include "tetrahedron.h"
#include "time.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла.
Shape *Shape::StaticIn(FILE *ifst) {
    int type_of_shape;
    float densityValue;
    if (fscanf(ifst, "%d%f", &type_of_shape, &densityValue) == EOF) {
        return nullptr;
    }

    Shape *shape;

    switch (type_of_shape) {
        case 1:
            shape = new Parallelepiped;
            shape->density = densityValue;
            break;
        case 2:
            shape = new Sphere;
            shape->density = densityValue;
            break;
        case 3:
            shape = new Tetrahedron;
            shape->density = densityValue;
            break;
        default:
            return nullptr;
    }
    shape->In(ifst);
    return shape;
}

// Случайный ввод обобщенной фигуры.
Shape *Shape::StaticInRnd() {
    int type_of_shape = rand() % 3 + 1;

    Shape *shape = nullptr;
    switch (type_of_shape) {
        case 1:
            shape = new Parallelepiped;
            shape->density = Random::RandomDouble();
            break;
        case 2:
            shape = new Sphere;
            shape->density = Random::RandomDouble();
            break;
        case 3:
            shape = new Tetrahedron;
            shape->density = Random::RandomDouble();
            break;
    }
    shape->InRnd();
    return shape;
}
