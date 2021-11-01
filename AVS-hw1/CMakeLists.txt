# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(avs1 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES

        # Headers
        rnd.h
        figures/shape.h
        figures/sphere.h
        figures/parallelepiped.h
        figures/tetrahedron.h
        container.h

        # Sources
        figures/sphere.cpp
        figures/shape.cpp
        figures/parallelepiped.cpp
        figures/tetrahedron.cpp
        container.cpp
        main.cpp
        )

add_executable(avs1 ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
