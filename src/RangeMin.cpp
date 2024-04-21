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
}

RangeMin::RangeMin(const std::vector<int>& values) {
	n = values.size();
	arr = values;
	windowSize = static_cast<unsigned int>(std::log2(n) / 4); // Calculate window size as one-quarter of log2(n)
	numWindows = static_cast<unsigned int>(std::ceil(static_cast<double>(n) / windowSize)); // Calculate the number of windows
	findMinInWindows(); // Find the minimum value in each window
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
