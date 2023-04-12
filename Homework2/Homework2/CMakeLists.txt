cmake_minimum_required(VERSION 3.0)
project(Homework2)
set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable (Homework2 "Homework2.cpp" "include/ICalculatable.h" "include/Addition.h" "include/Subtraction.h" "include/Number.h" "include/Multiplication.h" "include/Arcsin.h" "include/Arccos.h" "include/Calculator.h" "src/Calculator.cpp")


