#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include "RangeMin.h"
#include <vector>

RangeMin::RangeMin(unsigned int size) {
	n = size;
	arr.resize(n);
	fillRandomly();
	windowSize = static_cast<unsigned int>(std::log2(n) / 4); // Calculate window size as one-quarter of log2(n)
	numWindows = static_cast<unsigned int>(std::ceil(static_cast<double>(n) / windowSize)); // Calculate the number of windows
	findMinInWindows(); // Find the minimum value in each window
	minArrays = std::move(MinArrays(minInWindow)); // Using move assignment operator for MinArrays
	computeWindowETTourIndices(); // Compute the Euler tour indices location pairs for each window
}

RangeMin::RangeMin(const std::vector<int>& values) {
	n = values.size();
	arr = values;
	windowSize = static_cast<unsigned int>(std::log2(n) / 4); // Calculate window size as one-quarter of log2(n)
	numWindows = static_cast<unsigned int>(std::ceil(static_cast<double>(n) / windowSize)); // Calculate the number of windows
	findMinInWindows(); // Find the minimum value in each window
	minArrays = std::move(MinArrays(minInWindow)); // Using move assignment operator for MinArrays
	computeWindowETTourIndices(); // Compute the Euler tour indices location pairs for each window
}

void RangeMin::fillRandomly() {
	for (unsigned int i = 0; i < n; ++i) {
		arr[i] = rand() % 100; // Generate random elements (0 to 99)
	}
}

void RangeMin::findMinInWindows() {
	minInWindow.resize(numWindows, std::numeric_limits<int>::max()); // Initialize minInWindow vector with maximum values

	for (unsigned int i = 0; i < n; ++i) {
		unsigned int windowIndex = i / windowSize; // Calculate the index of the window containing the current element
		minInWindow[windowIndex] = std::min(minInWindow[windowIndex], arr[i]); // Update the minimum value in the window
	}
}

void RangeMin::printArray() const {
	std::cout << "Array Elements: ";
	for (unsigned int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void RangeMin::printMinInWindow() const {
	std::cout << "Minimum value in each window:" << std::endl;
	for (unsigned int i = 0; i < numWindows; ++i) {
		std::cout << "Window " << i+1 << ": " << minInWindow[i] << std::endl;
	}
}

unsigned int RangeMin::getWindowSize() const {
	return windowSize;
}

unsigned int RangeMin::getNumWindows() const {
	return numWindows;
}

std::vector<int> RangeMin::getMinInWindow() const {
	return minInWindow;
}

void RangeMin::validate() const {
	int numTests = 100000;//rand();
	minArrays.validateFunctions(numTests);
}

// Function to compute the Euler tour indices location pairs for each window
void RangeMin::computeWindowETTourIndices() {
	windowTourIndices.resize(numWindows); // Resize the vector to hold location pairs for each window

	// Iterate through each window
	for (unsigned int i = 0; i < numWindows; ++i) {
		// Calculate the start index of the current window
		unsigned int windowStartIndex = i * windowSize;

		// Create a new Cartesian tree for the current window
		CartesianTree cartesianTree(arr.begin() + windowStartIndex, arr.begin() + windowStartIndex + windowSize);

		// Get the appearance locations of nodes in the Cartesian tree
		std::vector<std::pair<int, int>> locationPairs = cartesianTree.getAppearanceLocations();

		// Store the appearance locations of the current window
		windowTourIndices[i] = std::move(locationPairs);
	}
}

void RangeMin::printWindowIndices(unsigned int windowIndex) const {
	if (windowIndex >= numWindows) {
		std::cerr << "Error: Window index out of range." << std::endl;
		return;
	}

	std::cout << "Window " << windowIndex << ":" << std::endl;
	std::cout << "Window Elements: ";
	for (unsigned int j = 0; j < windowSize; ++j) {
		std::cout << arr[windowIndex * windowSize + j] << " ";
	}
	std::cout << std::endl;

	std::cout << "Window Euler Tour Indices: ";
	for (const auto& pair : windowTourIndices[windowIndex]) {
		std::cout << "(" << pair.first << ", " << pair.second << ") ";
	}
	std::cout << std::endl;
}
