cmake_minimum_required(VERSION 3.26)
project(Studenti_bursieri C)

set(CMAKE_C_STANDARD 11)

add_executable(Studenti_bursieri main.c
        catalog.c
        catalog.h)
