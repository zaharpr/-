//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера.
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
void Init(container &c) {
    c.length = 0;
}

//------------------------------------------------------------------------------
void Clear(container &c) {
    for (int i = 0; i < c.length; i++) {
        delete c.cont[i];
    }
    c.length = 0;
}

//------------------------------------------------------------------------------
void In(container &c, FILE *ifst) {
    while (!feof(ifst)) {
        if ((c.cont[c.length] = In(ifst)) != nullptr) {
            c.length++;
        } else {
            break;
        }
    }
}

//------------------------------------------------------------------------------
void InRnd(container &c, int size) {
    while (c.length < size) {
        if ((c.cont[c.length] = InRnd()) != nullptr) {
            c.length++;
        }
    }
}

//------------------------------------------------------------------------------
void Out(container &c, FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.", c.length);
    for (int i = 0; i < c.length; i++) {
        fprintf(ofst, "%d: ", i);
        Out(*c.cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
void ShellSort(container &c) {
    int i, j, step;
    shape *tmp;
    for (step = c.length / 2; step > 0; step /= 2) {
        for (i = step; i < c.length; i++) {
            tmp = c.cont[i];
            for (j = i; j >= step; j -= step) {
                if (SurfaceArea(*tmp) > SurfaceArea(*c.cont[j - step]))
                    c.cont[j] = c.cont[j - step];
                else
                    break;
            }
            c.cont[j] = tmp;
        }
    }
}
