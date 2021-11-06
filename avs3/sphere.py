import random


# ----------------------------------------------
# Ввод параметров сферы из файла.
def in_file(sphere, line):
    str_array = line.split(' ')
    sphere.append("sphere")
    sphere.append(float(str_array[1]))  # density.
    sphere.append(int(str_array[2]))  # r.
    sphere.append(surface_area(sphere))  # Surface area.


# Случайный ввод параметров сферы.
def in_rnd(sphere):
    sphere.append("sphere")
    sphere.append(round(random.uniform(0.1, 20.0), 3))  # density.
    sphere.append(random.randint(1, 20))  # r.
    sphere.append(surface_area(sphere))  # Surface area.


# def out(tetrahedron, out_stream):
#     out_stream.out(f"Tetrahedron: a = {tetrahedron[2]},"
#                    f" density = {tetrahedron[1]}, SurfaceArea = {tetrahedron[3]}")


# Вычисление плозади поверхности сферы.
def surface_area(sphere):
    return float(4 * 3.1415 * sphere[2])
