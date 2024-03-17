cmake_minimum_required(VERSION 3.28)
project(BusqTernaria C)

set(CMAKE_C_STANDARD 11)

add_executable(BusqTernaria main.c
        ivector.c
        ivector.h)
