# ----------------------------------------------
from extender import *
import random


# Заполнение контейнера из файла.
def in_file(cont, figures_array):
    for figure in figures_array:
        type_of_figure = figure[0]
        if type_of_figure == '1':
            paral = []
            parallelepiped.in_file(paral, figure)
            cont.append(paral)
        elif type_of_figure == '2':
            tetr = []
            tetrahedron.in_file(tetr, figure)
            cont.append(tetr)
        elif type_of_figure == '3':
            sphr = []
            sphere.in_file(sphr, figure)
            cont.append(sphr)


# Случайное заполнение контейнера.
def in_rnd(cont, size):
    for _ in range(size):
        type_of_figure = random.randint(1, 3)
        if type_of_figure == 1:
            paral = []
            parallelepiped.in_rnd(paral)
            cont.append(paral)
        elif type_of_figure == 2:
            tetr = []
            tetrahedron.in_rnd(tetr)
            cont.append(tetr)
        elif type_of_figure == 3:
            sphr = []
            sphere.in_rnd(sphr)
            cont.append(sphr)


# Вывод содержимого контейнера.
def out(cont, out_stream):
    out_stream.write(f"Container contains {len(cont)} elements:\n")
    i = 0
    for figure in cont:
        i += 1
        out_stream.write(f"{i}: It is a {figure[0]}, ")

        if figure[0] == "parallelepiped":
            out_stream.write(f"a = {figure[2]}, b = {figure[3]}, c = {figure[4]}, ")
        elif figure[0] == "tetrahedron":
            out_stream.write(f"a = {figure[2]}, ")
        elif figure[0] == "sphere":
            out_stream.write(f"r = {figure[2]}, ")

        out_stream.write(f"density = {figure[1]}, surface area = {figure[len(figure) - 1]}\n")


# Сортировка Шелла по убыванию для элементов контейнера.
def shell_sort(cont):
    inc = len(cont) // 2
    while inc:
        for i, el in enumerate(cont[inc:], inc):
            while i >= inc and cont[i - inc][len(cont[i - inc]) - 1] < el[len(el) - 1]:
                cont[i] = cont[i - inc]
                i -= inc
            cont[i] = el
        inc = 1 if inc == 2 else inc * 5 // 11
