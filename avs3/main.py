import sys
import time

from extender import *


def err_message1():
    print("incorrect command line!\n"
          "  Waited:\n"
          "     command -f infile outfile01 outfile02\n"
          "  Or:\n"
          "     command -n number outfile01 outfile02\n")


def err_message2():
    print("incorrect qualifier value!\n"
          "  Waited:\n"
          "     command -f infile outfile01 outfile02\n"
          "  Or:\n"
          "     command -r number outfile01 outfile02\n")


# ----------------------------------------------
if __name__ == '__main__':
    if len(sys.argv) != 5:
        err_message1()
        exit(1)

    print('==> Start')
    # Старт счётчика времени работы программы.
    time_of_start = time.time()
    # Создание контейнера.
    cont = []

    # Ввод из файла.
    if sys.argv[1] == '-f':
        in_file = open(sys.argv[2], 'r')
        figures_array = in_file.read().split("\n")
        in_file.close()

        container.in_file(cont, figures_array)
    # Рандомный ввод.
    elif sys.argv[1] == '-r':
        size = int(sys.argv[2])

        if size < 1 or size > 10000:
            print("Incorrect number of figures = " + size + ". Set 0 < number <= 10000.\n")
            exit(3)
        else:
            container.in_rnd(cont, size)
    else:
        err_message2()
        exit(2)

    # Вывод неотсортированного контейнера.
    out_file = open(sys.argv[3], 'w+')
    container.out(cont, out_file)
    out_file.close()

    # Сортировка контейнера.
    container.shell_sort(cont)

    # Вывод отсортированного контейнера.
    out_file_sorted = open(sys.argv[4], 'w+')
    container.out(cont, out_file_sorted)
    out_file_sorted.close()

    # Подсчёт времени работы программы.
    time_of_end = time.time()
    print("CPU time used: " + str(time_of_end - time_of_start) + "sec.")

    print('==> Finish')
