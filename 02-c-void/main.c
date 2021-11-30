//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование.
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h> // для функций rand() и srand().
#include <time.h>   // для функции time().
#include <string.h>

#include "data.h"
// #include "input.c"
// #include "inrnd.c"
// #include "perimeter.c"
// #include "output.c"

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -r number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -r number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    unsigned char cont[maxSize];
    // Количество элементов в массиве
    int len = 0;

    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    // Начало подсчёта времени работы программы.
    clock_t start = clock();

    // Заполнение контейнера из файла или рандомно в зависимости от аргументов.
    if (!strcmp(argv[1], "-f")) {
        FILE *ifst = fopen(argv[2], "r");
        InContainer(cont, &len, ifst);
    } else if (!strcmp(argv[1], "-r")) {
        int size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("Incorrect number of figures = %d. Set 0 < number <= 10000.\n",
                   size);
            return 3;
        }
        // Системные часы в качестве инициализатора рандома.
        srand((unsigned int) (time(0)));
        // Заполнение контейнера генератором случайных чисел.
        InRndContainer(cont, &len, size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого заполненного контейнера в файл.
    FILE *ofst1 = fopen(argv[3], "w");
    fprintf(ofst1, "Filled container:\n");
    OutContainer(cont, len, ofst1);
    fclose(ofst1);

    // Сортировка контейнера.
    ShellSort(cont, len);

    // Вывод содержимого отсортированного контейнера в файл.
    FILE *ofst2 = fopen(argv[4], "w");
    fprintf(ofst2, "Sorted container:\n");
    OutContainer(cont, len, ofst2);
    fclose(ofst2);

    // Вывод результата времени работы программы.
    clock_t end = clock();
    double calcTime = ((double) (end - start)) / (CLOCKS_PER_SEC + 1.0);
    printf("CPU time used: %lf\n", calcTime);

    printf("Stop\n");

    return 0;
}
