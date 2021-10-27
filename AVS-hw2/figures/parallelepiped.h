#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда и его интерфейса.
//------------------------------------------------------------------------------

# include "../rnd.h"
#include "shape.h"

// Класс фигуры - параллелепипеда.
class Parallelepiped : public Shape {
public:
    virtual ~Parallelepiped() {}

    // Ввод параметров параллелепипеда из файла.
    virtual void In(FILE *ifst);

    // Случайный ввод параметров параллелепипеда.
    virtual void InRnd();

    // Вывод параметров параллелепипеда в форматируемый поток.
    virtual void Out(FILE *ofst);

    // Вычисление площади поверхности параллелепипеда.
    virtual double SurfaceArea();

private:
    // Длина, ширина, высота.
    int a, b, c;
};

#endif //__parallelepiped__
