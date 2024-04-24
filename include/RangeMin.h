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

	// Helper function to fill the array with random elements
	void fillRandomly();

	// Helper function to find the minimum value in each window
	void findMinInWindows();

	// Function to compute the Euler tour indices location pairs for each window
	void computeWindowETTour();

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

	void printWindowIndices(unsigned int windowIndex) const;
};

#endif /* RANGEMIN_H */