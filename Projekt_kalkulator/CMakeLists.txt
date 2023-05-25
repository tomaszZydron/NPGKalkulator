cmake_minimum_required(VERSION 3.24)
project(Projekt_kalkulator)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

include_directories(include)
set(SOURCE_FILES
        src/kalkulator.cpp)
add_executable(Projekt_kalkulatora ${SOURCE_FILES} main.cpp)
