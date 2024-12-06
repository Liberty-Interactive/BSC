# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(BSC)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES "src/*.c")

add_executable(bsc ${SOURCES})
