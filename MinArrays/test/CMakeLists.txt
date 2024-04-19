cmake_minimum_required(VERSION 3.10)
project(MinArraysTest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add test.cpp and MinArrays.cpp to the sources
set(SOURCES test.cpp ${CMAKE_SOURCE_DIR}/../src/MinArrays.cpp)

# Add the executable
add_executable(MinArraysTest ${SOURCES})

# Include directories
target_include_directories(MinArraysTest PRIVATE ${CMAKE_SOURCE_DIR}/../include)
