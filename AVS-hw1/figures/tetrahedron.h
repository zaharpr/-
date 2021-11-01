#ifndef __tetrahedron__
#define __tetrahedron__

//------------------------------------------------------------------------------
// tetrahedron.h - содержит описание тетраэдра и его интерфейса.
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "../rnd.h"

// Тетраэдр.
struct tetrahedron  {
    // Длина ребра.
    int a;
};

// Ввод параметров тетраэдра из файла.
void In(tetrahedron &t, FILE *ifst);

// Случайный ввод параметров тетраэдра.
void InRnd(tetrahedron &t);

// Вывод параметров тетраэдра в форматируемый поток.
void Out(tetrahedron &t, FILE *ofst);

// Вычисление периметра тетраэдра.
double SurfaceArea(tetrahedron &t);

#endif //__tetrahedron__
