cmake_minimum_required(VERSION 3.10)
project(CartesianTreeTest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add test.cpp and CartesianTree.cpp to the sources
set(SOURCES test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../src/CartesianTree.cpp)

# Add executable
add_executable(CartesianTreeTest ${SOURCES})

# Include header files
target_include_directories(CartesianTreeTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)