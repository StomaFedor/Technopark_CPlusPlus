# CMakeList.txt: проект CMake для Homework1CMake; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required(VERSION 3.0)
project(Homework1)
set(CMAKE_CXX_STANDARD 17)
include_directories(include)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (Homework1CMake "Homework1CMake.cpp"  "src/FileReader.cpp" "include/FileReader.h" "src/StatisticsWorker.cpp" "include/StatisticsWorker.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
