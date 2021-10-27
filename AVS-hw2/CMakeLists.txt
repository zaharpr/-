# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(avs2 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        # Headers
        figures/shape.h
        figures/parallelepiped.h
        figures/tetrahedron.h
        figures/sphere.h
        container.h
        rnd.h

        # Sources
        figures/shape.cpp
        figures/parallelepiped.cpp
        figures/tetrahedron.cpp
        figures/sphere.cpp
        container.cpp
        main.cpp
        )

add_executable(avs2 ${SOURCE_FILES})
