cmake_minimum_required(VERSION 3.10)
project(MinArrays)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(test src/test.cpp src/MinArrays.cpp)