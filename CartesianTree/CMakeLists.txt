cmake_minimum_required(VERSION 3.10)
project(CartesianTree)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(CartesianTree src/test.cpp src/CartesianTree.cpp)