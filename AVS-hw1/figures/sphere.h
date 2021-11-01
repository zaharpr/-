#ifndef __sphere__
#define __sphere__

//------------------------------------------------------------------------------
// sphere.h - содержит описание шара.
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "../rnd.h"

// Шар.
struct sphere {
    // Радиус.
    int r;
};

// Ввод параметра шара из файла.
void In(sphere &s, FILE *ifst);

// Случайный ввод параметра шара.
void InRnd(sphere &s);

// Вывод параметра шара в форматируемый поток.
void Out(sphere &s, FILE *ofst);

// Вычисление площади поверхности шара.
double SurfaceArea(sphere &s);

#endif //__sphere__
