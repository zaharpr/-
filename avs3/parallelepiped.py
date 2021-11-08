import random


# ----------------------------------------------
# Ввод параметров параллелепипеда из файла.
def in_file(parallelepiped, line):
    str_array = line.split(' ')
    parallelepiped.append("parallelepiped")
    parallelepiped.append(float(str_array[1]))  # density.
    parallelepiped.append(int(str_array[2]))  # a.
    parallelepiped.append(int(str_array[3]))  # b.
    parallelepiped.append(int(str_array[4]))  # c.
    parallelepiped.append(surface_area(parallelepiped))  # Surface area.


# Случайный ввод параметров параллелепипеда.
def in_rnd(parallelepiped):
    parallelepiped.append("parallelepiped")
    parallelepiped.append(round(random.uniform(0.1, 20.0), 3))  # density.
    parallelepiped.append(random.randint(1, 20))  # a.
    parallelepiped.append(random.randint(1, 20))  # b.
    parallelepiped.append(random.randint(1, 20))  # c.
    parallelepiped.append(surface_area(parallelepiped))  # Surface area.


# Вычисление плозади поверхности параллелепипеда.
def surface_area(parallelepiped):
    return float(2.0 * (parallelepiped[2] * parallelepiped[3] +
                        parallelepiped[2] * parallelepiped[4] +
                        parallelepiped[3] * parallelepiped[4]))
