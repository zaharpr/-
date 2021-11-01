#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда и его интерфейса.
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "../rnd.h"

// Параллелепипед.
struct parallelepiped {
    // Длина, ширина, высота.
    int a, b, c;
};

// Ввод параметров параллелепипеда из файла.
void In(parallelepiped &p, FILE *ifst);

// Случайный ввод параметров параллелепипеда.
void InRnd(parallelepiped &p);

// Вывод параметров параллелепипеда в форматируемый поток.
void Out(parallelepiped &p, FILE *ofst);

// Вычисление площади поверхности параллелепипеда.
double SurfaceArea(parallelepiped &p);

#endif //__parallelepiped__
