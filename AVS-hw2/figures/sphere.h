#ifndef __sphere__
#define __sphere__

//------------------------------------------------------------------------------
// sphere.h - содержит описание сферы и её интерфейса.
//------------------------------------------------------------------------------

# include "../rnd.h"
#include "shape.h"

// Класс фигуры - сферы.
class Sphere : public Shape {
public:
    virtual ~Sphere() {}

    // Ввод параметров сферы из файла.
    virtual void In(FILE *ifst);

    // Случайный ввод параметров сферы.
    virtual void InRnd();

    // Вывод параметров сферы в форматируемый поток.
    virtual void Out(FILE *ofst);

    // Вычисление периметра сферы.
    virtual double SurfaceArea();

private:
    // Радиус.
    int r;
};

#endif //__sphere__
