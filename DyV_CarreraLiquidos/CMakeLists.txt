cmake_minimum_required(VERSION 3.28)
project(DyV_CarreraLiquidos C)

set(CMAKE_C_STANDARD 11)

add_executable(DyV_CarreraLiquidos main.c
        ivector.h
        Corredor.h
        ivector.c)
