//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include <cstdlib> // для функций rand()
#include <ctime>   // для функции time()

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

void generateRandomTest(){
    Container c{10000};
    srand(time(0));
    c.InRnd(10000);
    FILE *ofstr = fopen("..\\tests\\rndIn5.txt", "w");
    c.Out(ofstr);
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }
    printf("Start\n");

    // Подсчет времени работы программы.
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Создание контейнера.
    Container c{10000};
    // Работа программы.
    if (!strcmp(argv[1], "-f")) {
        // Ввод из файла.
        FILE *ifst = fopen(argv[2], "r");
        c.In(ifst);
    } else if (!strcmp(argv[1], "-n")) {
        // Рандомная генерация контейнера.
        int size = atoi(argv[2]);

        if ((size < 1) || (size > 10000)) {
            printf("Incorrect number of figures = %d. Set 0 < number <= 10000.\n", size);
            return 3;
        }
        // Системные часы в качестве инициализатора.
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел.
        c.InRnd(size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл.
    FILE *ofst1 = fopen(argv[3], "w");
    fprintf(ofst1, "Filled container:\n");
    c.Out(ofst1);

    // Сортировка контейнера.
    c.ShellSort();

    // The 2nd part of task.
    FILE *ofst2 = fopen(argv[4], "w");
    fprintf(ofst2, "Sorted container:\n");
    c.Out(ofst2);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used: %f\n", cpu_time_used);

    printf("Stop\n");

    return 0;
}
