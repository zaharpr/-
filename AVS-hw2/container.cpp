//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"


Container::Container(int size) : length{0} {
    figures = new Shape *[size];
}


Container::~Container() {
    Clear();
    delete[]figures;
}

void Container::Clear() {
    for (int i = 0; i < length; i++) {
        delete figures[i];
    }
    length = 0;
}

void Container::In(FILE *ifst) {

    while (!feof(ifst)) {
        if ((figures[length] = Shape::StaticIn(ifst)) != nullptr) { // 0 or nullptr
            length++;
        }
    }
}

void Container::InRnd(int size) {
    while (length < size) {
        if ((figures[length] = Shape::StaticInRnd()) != nullptr) {
            length++;
        }
    }
}

void Container::Out(FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.\n", length);
    for (int i = 0; i < length; i++) {
        fprintf(ofst, "%d: ", i);
        figures[i]->Out(ofst);
    }
}

void Container::ShellSort() {
    int i, j, step;
    Shape *tmp;
    for (step = length / 2; step > 0; step /= 2) {
        for (i = step; i < length; i++) {
            tmp = figures[i];
            for (j = i; j >= step; j -= step) {
                if (tmp->SurfaceArea() > figures[j - step]->SurfaceArea())
                    figures[j] = figures[j - step];
                else
                    break;
            }
            figures[j] = tmp;
        }
    }
}
