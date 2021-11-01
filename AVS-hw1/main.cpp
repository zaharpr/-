//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование.
//------------------------------------------------------------------------------

#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }
    printf("Start\n");

    //region Подсчет работы времени программы.
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    //endregion

    container c;
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        FILE *ifst = fopen(argv[2], "r");
        In(c, ifst);
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("Incorrect number of figures = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }
        // Системные часы в качестве инициализатора.
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел.
        InRnd(c, size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод заполненного контейнера в файл.
    FILE *ofst1 = fopen(argv[3], "w");
    fprintf(ofst1, "Filled container:\n");
    Out(c, ofst1);

    // Сортировка контейнера.
    ShellSort(c);

    // The 2nd part of task
    // Вывод отсортированного контейнера в файл.
    FILE *ofst2 = fopen(argv[4], "w");
    fprintf(ofst2, "Sorted container:\n");
    Out(c, ofst2);

    // Вывод результата подсчёта времени работы программы.
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used: %f\n", cpu_time_used);

    Clear(c);
    printf("Stop\n");

    return 0;
}
