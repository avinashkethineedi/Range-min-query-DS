#ifndef RANGEMIN_H
#define RANGEMIN_H

#include <vector>
#include "MinArrays.h"
#include "CartesianTree.h" // Include CartesianTree header for using its data structures

class RangeMin {
private:
	unsigned int n; // Size of the array
	std::vector<int> arr; // Array to store elements
	std::vector<int> minInWindow; // Vector to store minimum value in each window
	unsigned int windowSize; // Size of each window
	unsigned int numWindows; // Number of windows
	MinArrays minArrays; // MinArrays object to store and compute minimum values in the range of two window
	std::vector<std::vector<std::pair<int, int>>> windowTourIndices; // Vector to store location pairs in Euler tour for each window
	std::vector<std::vector<int>> windowEulerTours; // Vector to store the Euler tour of each window
	std::vector<std::uint64_t> windowEncodedEulerTours; // Vector to store the encoded 64-bit value of Euler tour for each window
	std::vector<int> lookupTable; // Vector to store the lookup table


	// Helper function to fill the array with random elements
	void fillRandomly();

	// Helper function to find the minimum value in each window
	void findMinInWindows();

	// Function to compute the Euler tour indices location pairs for each window
	void computeWindowETTour();

	// Function to compute the lookup table
	void computeLookupTable();

public:
	// Constructors
	RangeMin(unsigned int size);
	RangeMin(const std::vector<int>& values);

	// Function to print array elements
	void printArray() const;

	// Function to print the minimum value in each window
	void printMinInWindow() const;

	// Function to get Array size
	unsigned int getArraySize() const;

	// Function to get window size
	unsigned int getWindowSize() const;

	// Function to get the number of windows
	unsigned int getNumWindows() const;

	// Function to get the lookup table size
	std::size_t getLookupTableSize() const;

	// Function to get the minimum value in each window as a vector of mins
	std::vector<int> getMinInWindow() const;

	// Function to validate the minArrays object
	void validate() const;

	// Function to print the element of a window
	void printWindowIndices(unsigned int windowIndex) const;

	// Function to calculate random indices within a random window and find the minimum
	int calculateMinInRandomIndices(unsigned int index1, unsigned int index2) const;

	// Function to calculate the minimum value within the range of a given window
	int calculateMinInWindowRange(unsigned int i, unsigned int j) const;

	// Function to perform a random number of tests and compare the results obtained from two functions
	void performRandomWindowTests(int numTests) const;

	// Function to print the lookuptable
	void printLookupTable() const;

	// Function to perform the range min queries in O(1)
	int rangeMinQuery(unsigned int i, unsigned int j) const;

	// Function to perform a random number of tests and compare the results obtained from two functions
	void performRandomTests(int numTests) const;
};

#endif /* RANGEMIN_H */