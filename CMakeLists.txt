cmake_minimum_required(VERSION 3.25)
project(LR2 C)

set(CMAKE_C_STANDARD 11)

add_executable(LR2 main.c mode_selection.c functions.h write_in_file.c task1.c tasks.h task2.c)
