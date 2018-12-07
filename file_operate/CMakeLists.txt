cmake_minimum_required(VERSION 3.12)
project(file_operate C)

set(CMAKE_C_STANDARD 11)

add_executable(file_operate
        main.c
        main1.c file_rw.c)
