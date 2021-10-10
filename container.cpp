//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, ifstream &ifst) {
    while (!ifst.eof()) {
        if ((c.cont[c.len] = In(ifst)) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while (c.len < size) {
        c.cont[c.len] = InRnd();
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << endl;
    for (int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

//------------------------------------------------------------------------------
// Вычисление суммы площадей поверхности всех фигур в контейнере
double SurfaceAreaSum(container &c) {
    double sum = 0.0;
    for (int i = 0; i < c.len; i++) {
        sum += SurfaceArea(*(c.cont[i]));
    }
    return sum;
}

void ShellSort(container &c, int n) {
    int i, j, step;
    shape *tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++) {
            tmp = c.cont[i];
            for (j = i; j >= step; j -= step) {
                if (tmp < c.cont[j - step])
                    c.cont[j] = c.cont[j - step];
                else
                    break;
            }
            c.cont[j] = tmp;
        }
}

