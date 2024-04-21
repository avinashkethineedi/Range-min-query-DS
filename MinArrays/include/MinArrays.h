#ifndef MINARRAYS_H
#define MINARRAYS_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib> // for rand()

class MinArrays {
private:
	std::vector<std::vector<int>> arrays; // Vector to store logN + 1 arrays
	int n; // Size of each array
	int logN; // Number of arrays = log base 2 of N

	// Calculate the remaining arrays using the first array
	void calculateRemainingArrays();

	// Randomly initialize the first array and calculate the remaining arrays
	void randomizeFirstArray();

public:
	// Constructors
	MinArrays() = default;
	MinArrays(int size);
	MinArrays(const std::vector<int>& values);

	// Special member functions
	MinArrays(const MinArrays& other) = default; // Default copy constructor
	MinArrays& operator=(const MinArrays& other) = default; // Default copy assignment operator
	MinArrays(MinArrays&& other) noexcept = default; // Default move constructor
	MinArrays& operator=(MinArrays&& other) noexcept = default; // Default move assignment operator
	~MinArrays() = default; // Default destructor

	// Member functions
	void fillAndCalculate(const std::vector<int>& values); // Fill the first array with values and calculate remaining arrays
	void printArrays() const; // Print all the arrays
	void printArrayAtIndex(int arrayIndex) const; // Print the array at index i
	void setValue(int arrayIndex, int index, int value); // Set value at array index i and index j
	int getValue(int arrayIndex, int index) const; // Get value at array index i and index j
	int calculateMinInRange(int i, int j) const; // Calculate minimum in range [i, j]
	int range_min(int i, int j) const; // Calculate range min using precomputed values
	void validateFunctions(int numTests) const; // Validate the functions calculateMinInRange and range_min on randomly generated indices
	int getSize() const { return n; } // Get the size of the arrays
};

#endif // MINARRAYS_H