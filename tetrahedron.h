#ifndef __tetrahedron__
#define __tetrahedron__

//------------------------------------------------------------------------------
// tetrahedron.h - содержит описание тетраэдра и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"

// тетраэдр
struct tetrahedron {
    int a; // длина ребра
    double density;
};

// Ввод параметров тетраэдра из файла
void In(tetrahedron &t, ifstream &ifst);

// Случайный ввод параметров тетраэдра
void InRnd(tetrahedron &t);

// Вывод параметров тетраэдра в форматируемый поток
void Out(tetrahedron &t, ofstream &ofst);

// Вычисление периметра тетраэдра
double SurfaceArea(tetrahedron &t);

#endif //__tetrahedron__
