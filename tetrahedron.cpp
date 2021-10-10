//------------------------------------------------------------------------------
// tetrahedron_In.cpp - содержит процедуру ввода параметров
// для уже созданного тетраэдра
//------------------------------------------------------------------------------

#include "tetrahedron.h"
#include "math.h"

//------------------------------------------------------------------------------
// Ввод параметров тетраэдра из файла
void In(tetrahedron &t, ifstream &ifst) {
    ifst >> t.a;
}

// Случайный ввод параметров тетраэдра
void InRnd(tetrahedron &t) {
    t.a = Random();
    t.density = RandomDouble();
}

//------------------------------------------------------------------------------
// Вывод параметров тетраэдра в форматируемый поток
void Out(tetrahedron &t, ofstream &ofst) {
    ofst << "It is Tetrahedron: a = " << t.a
         << ". SurfaceArea = " << SurfaceArea(t) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра тетраэдра
double SurfaceArea(tetrahedron &t) {
    return std::sqrt(3) * t.a * t.a;
}
