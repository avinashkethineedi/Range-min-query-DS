cmake_minimum_required(VERSION 3.10)
project(CartesianTreeLibrary)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add CartesianTree.cpp to create a library
add_library(cartesian_tree INTERFACE)

# Specify include directories for the library target
target_include_directories(cartesian_tree INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)