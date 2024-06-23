# MinArrays Data Structure

This directory contains the implementation of the `MinArrays` data structure, a simple C++ implementation designed for efficient range minimum queries (RMQs) on static array. By preprocessing an array of size \( n \) using \( O(n \log n) \) time and space, the data strucutre enables the retrieval of minimum values within any specified subarray range \( i \) to \( j \) in constant time \( O(1) \). This preprocessing approach constructs logarithmic auxiliary arrays, each designed to facilitate quick minimum value extraction for various subarray sizes. Ideal for computational scenarios with frequent RMQ requirements.

## Directory Structure

```
MinArrays/
├── CMakeLists.txt          # Build script for CMake, creates a static library.
├── src/
│   └── MinArrays.cpp       # Source file for the MinArrays data structure.
├── include/
│   └── MinArrays.h         # Header file for the MinArrays data structure.
└── test/ 
    ├── test.cpp            # Test file for testing the MinArrays data structure functionality.
    └── CMakeLists.txt      # CMake file for building the test suite.
```

## Getting Started

### Prerequisites

Ensure you have CMake installed on your system to build the project. You can download and install CMake from [CMake.org](https://cmake.org/download/).

### Building the Static Library

1. Open a terminal and navigate to the MinArrays directory.
2. Create a build directory and navigate into it:
   ```
   mkdir build && cd build
   ```
3. Run CMake to configure the project and generate the makefile:
   ```
   cmake ..
   ```
4. Compile the Library:
   ```
   cmake --build .
   ```
   These steps compiles the source code into a static library for the MinArrays data strucutre, resulting in a `.a` file which can be linked with other applications.

### Building and Running Tests

The tests also require building with CMake. Follow these steps to compile and run the tests:

1. Navigate to the `test` sub-directory within the MinArrays directory.
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
   ./MinArraysTest <array_size> <num_tests>
   ```

## Usage

### Construction

- **Random Initialization:**

  ```cpp
  int size = 10000; // Specify the desired size of the array
  MinArrays minArr(size);
  ```

- **Initialization with Values:**

  ```cpp
  std::vector<int> initialValues = {10, 5, 2, 14, 3, 7};
  MinArrays minArr(initialValues);
  ```

### Operations

- **Print Auxiliary Arrays:**

  ```cpp
  minArr.printArrays();
  ```

- **Compute Minimum in a Range:**

  ```cpp
  int minimum = minArr.range_min(startIndex, endIndex);
  ```

- **Validate Function:**
  This function validates the correctness of the `range_min` function by performing a series of random tests.
  ```cpp
  int numTests = 100; // Number of random tests to perform
  minArr.validateFunctions(numTests);
  ```

### Detailed Behavior

For an array `A` of size `n` elements, `log n` auxiliary arrays are created, where the i<sup>th</sup> array contains the minimum in every contiguous subarray of length 2<sup>i</sup>. This structure allows for efficient range minimum queries:

- **Range Minimum Query Optimization:** Now we can compute the value of `range_min(i, j)` by taking the minimum of at most two precomputed window minimums (whose sizes are the next-smallest power of 2 less than the size of our query window `A[i] … A[j]`).

## Example

Here's a simple example demonstrating how to use the `MinArrays` library:

```cpp
#include <iostream>
#include "MinArrays.h"

int main() {
    // Initialize with predefined values
    std::vector<int> data = {15, 6, 9, 10, 2, 16, 8, 3};
    MinArrays array(data);

    // Print all auxiliary arrays
    array.printArrays();

    // Perform a range minimum query
    int minInRange = array.range_min(2, 5);
    std::cout << "Minimum in range [2, 5]: " << minInRange << std::endl;

    // Validate the correctness of the range minimum functions
    array.validateFunctions(100); // Performs 100 random tests to validate

    return 0;
}

```
