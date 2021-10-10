//------------------------------------------------------------------------------
// parallelepiped.cpp - содержит функции обработки параллелепипеда
//------------------------------------------------------------------------------

#include "parallelepiped.h"

//------------------------------------------------------------------------------
// Ввод параметров параллелепипеда из потока
void In(parallelepiped &p, ifstream &ifst) {
    ifst >> p.a >> p.b >> p.c;
}

// Случайный ввод параметров параллелепипеда
void InRnd(parallelepiped &p) {
    p.a = Random();
    p.b = Random();
    p.c = Random();
    p.density = RandomDouble();
}

//------------------------------------------------------------------------------
// Вывод параметров параллелепипеда в поток
void Out(parallelepiped &p, ofstream &ofst) {
    ofst << "It is Parallelepiped: a = "
         << p.a << ", b = " << p.b
         << ", c = " << p.c
         << ". SurfaceArea = " << SurfaceArea(p) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление площади поверхности параллелепипеда
double SurfaceArea(parallelepiped &p) {
    return 2 * (p.a * p.b + p.b * p.c + p.a * p.c);
}
