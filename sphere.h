#ifndef __sphere__
#define __sphere__

//------------------------------------------------------------------------------
// sphere.h - содержит описание шара
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"

//------------------------------------------------------------------------------
// шар
struct sphere {
    int r; // радиус
    double density;
};

// Ввод параметра шара из файла
void In(sphere &s, ifstream &ifst);

// Случайный ввод параметра шара
void InRnd(sphere &s);

// Вывод параметра шара в форматируемый поток
void Out(sphere &s, ofstream &ofst);

// Вычисление площади поверхности шара
double SurfaceArea(sphere &s);

#endif //__sphere__
