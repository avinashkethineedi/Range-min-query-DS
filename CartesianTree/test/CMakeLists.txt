cmake_minimum_required(VERSION 3.10)
project(CartesianTreeTest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add test.cpp and CartesianTree.cpp to the sources
set(SOURCES test.cpp ../src/CartesianTree.cpp)

# Add executable
add_executable(CartesianTreeTest ${SOURCES})

# Include header files
target_include_directories(CartesianTreeTest PRIVATE ../include)