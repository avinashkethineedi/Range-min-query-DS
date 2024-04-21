#ifndef RANGEMIN_H
#define RANGEMIN_H

#include <vector>
#include "MinArrays.h"

class RangeMin {
private:
	unsigned int n; // Size of the array
	std::vector<int> arr; // Array to store elements
	std::vector<int> minInWindow; // Vector to store minimum value in each window
	unsigned int windowSize; // Size of each window
	unsigned int numWindows; // Number of windows
	MinArrays minArrays; // MinArrays object to store and compute minimum values in the range of two window

	// Helper function to fill the array with random elements
	void fillRandomly();

	// Helper function to find the minimum value in each window
	void findMinInWindows();

public:
	// Constructors
	RangeMin(unsigned int size);
	RangeMin(const std::vector<int>& values);

	// Function to print array elements
	void printArray() const;

	// Function to print the minimum value in each window
	void printMinInWindow() const;

	// Function to get window size
	unsigned int getWindowSize() const;

	// Function to get the number of windows
	unsigned int getNumWindows() const;

	// Function to get the minimum value in each window
	std::vector<int> getMinInWindow() const;

	// Function to validate the minArrays object
	void validate() const;
};

#endif /* RANGEMIN_H */