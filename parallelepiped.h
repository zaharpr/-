#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"

// параллелепипед
struct parallelepiped {
    int a, b, c; // длина, ширина, высота
    double density;
};

// Ввод параметров параллелепипеда из файла
void In(parallelepiped &p, ifstream &ifst);

// Случайный ввод параметров параллелепипеда
void InRnd(parallelepiped &p);

// Вывод параметров прямоугольника в форматируемый поток
void Out(parallelepiped &p, ofstream &ofst);

// Вычисление площади поверхности прямоугольника
double SurfaceArea(parallelepiped &p);

#endif //__parallelepiped__
