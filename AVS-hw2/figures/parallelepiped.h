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
    ~Parallelepiped() {}

    // Ввод параметров параллелепипеда из файла.
    void In(FILE *ifst);

    // Случайный ввод параметров параллелепипеда.
    void InRnd();

    // Вывод параметров параллелепипеда в форматируемый поток.
    void Out(FILE *ofst);

    // Вычисление площади поверхности параллелепипеда.
    double SurfaceArea();

private:
    // Длина, ширина, высота.
    int a, b, c;
};

#endif //__parallelepiped__
