cmake_minimum_required(VERSION 3.10)
project(RangeMin)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
	src/RangeMin.cpp
	src/main.cpp
)

# Generate executable
add_executable(RangeMin ${SOURCES})

# Include directories
target_include_directories(RangeMin PUBLIC include)

# Link MinArrays library
add_subdirectory(MinArrays)
target_link_libraries(RangeMin MinArrays)

# Link CartesianTree library
add_subdirectory(CartesianTree)
target_link_libraries(RangeMin CartesianTree)