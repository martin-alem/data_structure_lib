cmake_minimum_required(VERSION 3.18)
project(datastructure C)

set(CMAKE_C_STANDARD 11)

add_executable(datastructure main.c singly_linked_list.h singly_linked_list.c)