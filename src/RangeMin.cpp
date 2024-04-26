#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include "RangeMin.h"
#include <vector>
#include <bitset>

RangeMin::RangeMin(unsigned int size) {
	n = size;
	arr.resize(n);
	fillRandomly();
	windowSize = static_cast<unsigned int>(std::log2(n) / 4); // Calculate window size as one-quarter of log2(n)
	numWindows = static_cast<unsigned int>(std::ceil(static_cast<double>(n) / windowSize)); // Calculate the number of windows
	findMinInWindows(); // Find the minimum value in each window
	minArrays = std::move(MinArrays(minInWindow)); // Using move assignment operator for MinArrays
	computeWindowETTour(); // Compute the Euler tour indices location pairs for each window
	computeLookupTable(); // Compute the lookup Table for the RangeMin queries within the windowSize
}

RangeMin::RangeMin(const std::vector<int>& values) {
	n = values.size();
	arr = values;
	windowSize = static_cast<unsigned int>(std::log2(n) / 4); // Calculate window size as one-quarter of log2(n)
	numWindows = static_cast<unsigned int>(std::ceil(static_cast<double>(n) / windowSize)); // Calculate the number of windows
	findMinInWindows(); // Find the minimum value in each window
	minArrays = std::move(MinArrays(minInWindow)); // Using move assignment operator for MinArrays
	computeWindowETTour(); // Compute the Euler tour indices location pairs for each window
	computeLookupTable(); // Compute the lookup Table for the RangeMin queries within the windowSize
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

// Function to return the size of the lookup table
std::size_t RangeMin::getLookupTableSize() const {
		return lookupTable.size();
	}

std::vector<int> RangeMin::getMinInWindow() const {
	return minInWindow;
}

void RangeMin::validate() const {
	int numTests = 100000;//rand();
	minArrays.validateFunctions(numTests);
}

// Function to compute the Euler tour indices location pairs for each window
void RangeMin::computeWindowETTour() {
	windowTourIndices.resize(numWindows); // Resize the vector to hold location pairs for each window
	windowEulerTours.resize(numWindows); // Resize the vector to hold the Euler tour for each window
	windowEncodedEulerTours.resize(numWindows); // Resize the vector to hold the encoded 64 bit Euler tour for each window

	// Iterate through each window
	for (unsigned int i = 0; i < numWindows; ++i) {
		// Calculate the start index of the current window
		unsigned int windowStartIndex = i * windowSize;

		// Create a new Cartesian tree for the current window
		CartesianTree cartesianTree(arr.begin() + windowStartIndex, arr.begin() + windowStartIndex + windowSize);

		// Get the appearance locations of nodes in the Cartesian tree
		std::vector<std::pair<int, int>> locationPairs = cartesianTree.getAppearanceLocations();

		// Get the Euler tour for the current window
		std::vector<int> eulerTour = cartesianTree.eulerTour();

		// Get the encoded 64-bit value of the Euler tour for the current window
		std::uint64_t encodedEulerTour = cartesianTree.encodeEulerTourTo64Bit();

		// Save the appearance locations of the current window
		windowTourIndices[i] = std::move(locationPairs);

		// Save the Euler tour for the current window
		windowEulerTours[i] = std::move(eulerTour);

		// Save the encoded value for the current window
		windowEncodedEulerTours[i] = encodedEulerTour;
	}
}

// Function to compute the lookup table for each window
void RangeMin::computeLookupTable() {
	unsigned int size = 2*static_cast<unsigned int>(sqrt(n));
	lookupTable.reserve(size); // Reserve space for n elements

	// Calculate the lookup table
	lookupTable.push_back(0);
	for (int i = 1; i < size; ++i) {
		int msbPos = 0;
		int num = i;
		while (num > 0) {
			msbPos++;
			num >>= 1;
		}

		// Count zeros and ones in the binary representation of i starting from msbPos
		num = i;
		int maxDiffPos = 0, maxDiff = -1, zeros = 0, ones = 0, diff;
		for (int currPos = msbPos-1; currPos >= 0; currPos--) {
			if (num & (1 << (currPos)))
				ones++;
			else
				zeros++;

			// Calculate the difference between zeros and ones
			diff = zeros - ones;

			// Update maxDiffPos if a higher difference is found
			if (diff > maxDiff) {
				maxDiff = diff;
				maxDiffPos = msbPos - currPos - 1;
			}
		}

		lookupTable.push_back(maxDiffPos);
	}
}

void RangeMin::printWindowIndices(unsigned int windowIndex) const {
	if (windowIndex >= numWindows) {
		std::cerr << "Error: Window index out of range." << std::endl;
		return;
	}

	std::cout << "Window ID: " << windowIndex << ":" << std::endl;
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
	std::cout << "Window Euler Tour: ";
	for (const auto& elem : windowEulerTours[windowIndex]) {
		std::cout << elem << ", ";
	}
	std::cout << std::endl;
	std::cout << "encoded64bit: " << windowEncodedEulerTours[windowIndex] << std::endl;
}

// Function to calculate the minimum value between two random indices within the same window
int RangeMin::calculateMinInRandomIndices(unsigned int i, unsigned int j) const {
	// Ensure that index1 is less than index2
	if (i > j) {
		std::swap(i, j);
	}

	// Calculate the window indices for i and j
	unsigned int windowIdx_i = i / windowSize;
	unsigned int windowIdx_j = j / windowSize;

	// If index1 and index2 are in the same window, calculate the minimum in the range
	if (windowIdx_i == windowIdx_j) {
		int minValue = arr[i];
		for (unsigned int idx = i + 1; idx <= j; ++idx) {
			minValue = std::min(minValue, arr[idx]);
		}
		return minValue;
	} else {
		std::cout << "Indices (" << i << ", " << j << ") are not within the same window." << std::endl;
	}

	// If index1 and index2 are in different windows, return -1
	return -1;
}

// Function to calculate the minimum value within the range of a given window
int RangeMin::calculateMinInWindowRange(unsigned int i, unsigned int j) const {
	unsigned int windowIdx_i = i / windowSize;
	unsigned int windowIdx_j = j / windowSize;

	i = i % windowSize;
	j = j % windowSize;

	if (i > j) {
		std::swap(i, j);
	}

	int minValue = -1;

	if (windowIdx_i == windowIdx_j) {
		unsigned int startIdx = windowTourIndices[windowIdx_i][i].first;
		unsigned int endIdx = windowTourIndices[windowIdx_j][j].first;
		unsigned int binaryLen = endIdx - startIdx;

		if (endIdx <= startIdx) {
			return windowEulerTours[windowIdx_i][endIdx];
		}

		int ETsize = 2 * windowSize - 1;
		uint64_t encodedInt64 = windowEncodedEulerTours[windowIdx_i] >> (ETsize - endIdx - 1);

		uint64_t bitmask = binaryLen ? (1ULL << binaryLen) - 1 : 0;
		uint64_t offset = encodedInt64 & bitmask;
		offset |= (1ULL << binaryLen);

		minValue = windowEulerTours[windowIdx_i][startIdx + lookupTable[offset]];
	} else {
		std::cout << "Indices (" << i << ", " << j << ") are not within the same window." << std::endl;
	}

	return minValue;
}

void RangeMin::performRandomTests(int numTests) const {
	int passedTests = 0;

	for (int i = 0; i < numTests; ++i) {

		// Generate a random window index
		unsigned int randomWindowIndex = rand() % numWindows;

		// Calculate the start and end indices of the window
		unsigned int startIdx = randomWindowIndex * windowSize;
		unsigned int endIdx = std::min(startIdx + windowSize, n);

		// Generate random indices within this window
		unsigned int index1 = rand() % (endIdx - startIdx) + startIdx;
		unsigned int index2 = rand() % (endIdx - startIdx) + startIdx;

		if (index1 > index2) {
			std::swap(index1, index2);
		}

		// Calculate the minimum value between the random indices using both methods
		int min1 = calculateMinInRandomIndices(index1, index2);
		int min2 = calculateMinInWindowRange(index1, index2);

		// Compare the results
		if (min1 == min2) {
			++passedTests;
		} else {
			std::cout << "Test failed: Indices (" << index1 % windowSize << ", " << index2 % windowSize << ") => "
					  << "Actual: " << min1 << ", Expected: " << min2 << std::endl;
		}
	}

	std::cout << "Passed tests: " << passedTests << "/" << numTests << std::endl;
}

void RangeMin::printLookupTable() const {
	std::cout << "Lookup Table:" << std::endl;
	for (size_t i = 0; i < lookupTable.size(); ++i) {
		std::cout << "Index " << " | " << i << " | " << std::bitset<std::numeric_limits<size_t>::digits>(i) << ": " 
				  << lookupTable[i] << std::endl;
	}
}