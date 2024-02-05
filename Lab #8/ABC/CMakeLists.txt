cmake_minimum_required(VERSION 3.27)
project(ABC C)

set(CMAKE_C_STANDARD 11)

add_executable(ABC main.c
        arbori.h
        arbori.c)
