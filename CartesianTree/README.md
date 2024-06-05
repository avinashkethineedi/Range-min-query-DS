# Cartesian Tree

## Overview

This directory contains an implementation of a Cartesian Tree, a binary tree derived from a sequence of numbers, where it is heap-ordered and has the structure of a binary search tree relative to the positions of the numbers in the original sequence. This can be useful for various applications, such as range minimum queries, lowest common ancestor and others. The provided implementation includes utility functions that allow for efficient tree construction in amortized linear time. This is achieved through a process where each new element is added to the tree's rightmost side and rotated upwards if it is smaller than its parent, continuing until the min-heap condition is satisfied.

## Directory Structure

```
CartesianTreeProject/
├── CMakeLists.txt          # Build script for CMake, creates a shared library.
├── src/
│   └── CartesianTree.cpp   # Source file for the Cartesian Tree implementation.
├── include/
│   └── CartesianTree.h     # Header file for the Cartesian Tree.
└── test/
    ├── test.cpp            # Test file for testing the Cartesian Tree functionality.
    └── CMakeLists.txt      # CMake file for building the test suite.
```

## Getting Started

### Prerequisites

Ensure you have CMake installed on your system to build the project. You can download and install CMake from [CMake.org](https://cmake.org/download/).

### Building the Project

1. Open a terminal and navigate to the CartesianTree directory.
2. Create a build directory and navigate into it:
   ```
   mkdir build && cd build
   ```
3. Run CMake to configure the project and generate the makefile:
   ```
   cmake ..
   ```
4. Build the project:
   ```
   cmake --build .
   ```
   This will create a shared library for the Cartesian Tree.

### Building and Running Tests

The tests also require building with CMake. Follow these steps to compile and run the tests:

1. Navigate to the `test` sub-directory within the CartesianTree directory.
2. Create a build directory for the tests and navigate into it:
   ```
   mkdir build && cd build
   ```
3. Configure the test build with CMake:
   ```
   cmake ..
   ```
4. Build the test executable:
   ```
   cmake --build .
   ```
5. Run the test executable:
   ```
   ./CartesianTreeTest <numValidations> <maxElements>
   ```
