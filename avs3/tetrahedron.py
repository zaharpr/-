from math import sqrt
import random


# ----------------------------------------------
# Ввод параметров тетраэдра из файла.
def in_file(tetrahedron, line):
    str_array = line.split(' ')
    tetrahedron.append("tetrahedron")
    tetrahedron.append(float(str_array[1]))  # density.
    tetrahedron.append(int(str_array[2]))  # a.
    tetrahedron.append(surface_area(tetrahedron))  # Surface area.


# Случайный ввод параметров тетраэдра.
def in_rnd(tetrahedron):
    tetrahedron.append("tetrahedron")
    tetrahedron.append(round(random.uniform(0.1, 20.0), 3))  # density.
    tetrahedron.append(random.randint(1, 20))  # a.
    tetrahedron.append(surface_area(tetrahedron))  # Surface area.


# Вычисление плозади поверхности тетраэдра.
def surface_area(tetrahedron):
    return float(sqrt(3) * tetrahedron[2] * tetrahedron[2])
