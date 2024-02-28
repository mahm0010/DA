cmake_minimum_required(VERSION 3.28)
project(DyV_SumaVector C)

set(CMAKE_C_STANDARD 11)

add_executable(DyV_SumaVector main.c
        ivector.h
        ivector.c)
