cmake_minimum_required(VERSION 3.10)
project(MinArraysLibrary)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/MinArrays.cpp)

# Create a library target
add_library(MinArrays ${SOURCES})

# Specify include directory for the library target
target_include_directories(MinArrays PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
