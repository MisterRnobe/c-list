cmake_minimum_required(VERSION 3.14)
project(list C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_EXE main.c)
set(SOURCE_LIST_LIB list.c)

add_library(list STATIC ${SOURCE_LIST_LIB})

add_executable(main ${SOURCE_EXE})
target_link_libraries(main list)