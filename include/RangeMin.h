#ifndef RANGEMIN_H
#define RANGEMIN_H

#include <vector>

class RangeMin {
private:
	std::vector<int> arr; // Array to store elements
	unsigned int n; // Size of the array
	unsigned int windowSize; // Size of each window
	unsigned int numWindows; // Number of windows
	std::vector<int> minInWindow; // Vector to store minimum value in each window

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
};

#endif /* RANGEMIN_H */