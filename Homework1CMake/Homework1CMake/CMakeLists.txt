cmake_minimum_required(VERSION 3.0)
project(Homework1)
set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable (Homework1CMake "Homework1CMake.cpp"  "src/FileReader.cpp" "include/FileReader.h" "src/StatisticsWorker.cpp" "include/StatisticsWorker.h")