#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <fstream>

#include "../rnd.h"

// Класс обобщенной геометрической фигуры.
class Shape {
public:
    double density;

    virtual ~Shape() {};

    // Ввод обобщенной фигуры
    static Shape *StaticIn(FILE *ifdt);

    // Ввод обобщенной фигуры
    virtual void In(FILE *ifdt) = 0;

    // Случайный ввод обобщенной фигуры
    static Shape *StaticInRnd();

    // Виртуальный метод ввода случайной фигуры
    virtual void InRnd() = 0;

    // Вывод обобщенной фигуры
    virtual void Out(FILE *ofst) = 0;

    // Вычисление периметра обобщенной фигуры
    virtual double SurfaceArea() = 0;
};

#endif
