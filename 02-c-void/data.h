#ifndef __data__
#define __data__

//------------------------------------------------------------------------------
// data.h - Описание данных бестиповой программы.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Раздел констант.
//------------------------------------------------------------------------------

// Константа, определяющая размер целого числа.
int const intSize = sizeof(int);
// Константа, определяющая размер дробного числа.
int const doubleSize = sizeof(double);
// Константа, задающая размер для параллелепипеда.
int const paralSize = doubleSize + 3 * intSize;
// Константа, задающая размер для тетраэдра.
int const tetrSize = doubleSize + intSize;
// Константа, задающая размер для шара.
int const sphereSize = doubleSize + intSize;
// Константа, задающая размер для обобщенной фигуры.
int const shapeSize = intSize + paralSize;
// Константа, определяющая размерность массива фигур.
int const maxSize = 10000 * shapeSize;
// Константа, задающая признак параллелепипеда.
int const PARALLELEPIPED = 1;
// Константа, задающая признак тетраэдра.
int const TETRAHEDRON = 2;
// Константа, задающая признак шара.
int const SPHERE = 3;

// Ввод содержимого контейнера из указанного файла.
void InContainer(void *c, int *len, FILE *ifst);

// Случайный ввод содержимого контейнера.
void InRndContainer(void *c, int *len, int size);

// Вывод содержимого контейнера в файл.
void OutContainer(void *c, int len, FILE *ofst);

void ShellSort(void *cont, int len);

#endif
