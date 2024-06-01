#include "MinArrays.h"

// Constructor with size parameter
MinArrays::MinArrays(int size) {
	n = size;
	logN = static_cast<int>(std::log2(n));
	arrays.resize(logN + 1, std::vector<int>(n));
	randomizeFirstArray(); // Randomly initialize the first array and calculate the remaining arrays
}

// Constructor with initial values
MinArrays::MinArrays(const std::vector<int>& values) {
	n = values.size();
	logN = static_cast<int>(std::log2(n));
	arrays.resize(logN + 1, std::vector<int>(n));
	fillAndCalculate(values);
}

// Fill the first array with values and calculate the remaining arrays
void MinArrays::fillAndCalculate(const std::vector<int>& values) {
	if (values.size() != n) {
		std::cerr << "Size of the given vector doesn't match the size of the array.\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		arrays[0][i] = values[i];
	}
	calculateRemainingArrays();
}

// Calculate the remaining arrays using the first array
void MinArrays::calculateRemainingArrays() {
	for (int i = 1; i <= logN; ++i) {
		for (int j = 0; j < n; ++j) {
			int power = std::pow(2, i - 1);
			arrays[i][j] = std::min(arrays[i - 1][j], arrays[i - 1][std::min(j + power, n - 1)]);
		}
	}
}

// Randomly initialize the first array and calculate the remaining arrays
void MinArrays::randomizeFirstArray() {
	for (int i = 0; i < n; ++i) {
		arrays[0][i] = rand() % 100; // Generate random numbers between 0 and 99
	}
	calculateRemainingArrays(); // Calculate the remaining arrays
}

// Print all the arrays
void MinArrays::printArrays() const {
	for (int i = 0; i <= logN; ++i) {
		printArrayAtIndex(i);
	}
}

// Print the array at index i
void MinArrays::printArrayAtIndex(int arrayIndex) const {
	if (arrayIndex >= 0 && arrayIndex <= logN) {
		std::cout << "Array " << arrayIndex << ": ";
		for (int j = 0; j < n; ++j) {
			std::cout << arrays[arrayIndex][j] << " ";
		}
		std::cout << std::endl;
	} else {
		std::cout << "Invalid array index\n";
	}
}

// Set value at array index i and index j
void MinArrays::setValue(int arrayIndex, int index, int value) {
	if (arrayIndex >= 0 && arrayIndex <= logN && index >= 0 && index < n) {
		arrays[arrayIndex][index] = value;
	} else {
		std::cout << "Invalid array index or index\n";
	}
}

// Get value at array index i and index j
int MinArrays::getValue(int arrayIndex, int index) const {
	if (arrayIndex >= 0 && arrayIndex <= logN && index >= 0 && index < n) {
		return arrays[arrayIndex][index];
	} else {
		std::cout << "Invalid array index or index\n";
		return -1; // Return a default value indicating failure
	}
}

// Calculate minimum in range [i, j]
int MinArrays::calculateMinInRange(int i, int j) const {
	if (i < 0 || j < 0 || i >= n || j >= n || i > j) {
		std::cout << "Invalid range\n";
		return -1; // Return a default value indicating failure
	}
	int minVal = arrays[0][i];
	for (int k = i + 1; k <= j; ++k) {
		minVal = std::min(minVal, arrays[0][k]);
	}
	return minVal;
}

// Calculate range min using precomputed values
int MinArrays::range_min(int i, int j) const {
	if (i < 0 || j < 0 || i >= n || j >= n || i > j) {
		std::cout << "Invalid range\n";
		return -1; // Return a default value indicating failure
	}
	int size = j - i + 1;
	int nextPower = 31 - __builtin_clz(size); // static_cast<int>(std::log2(size)); // Find the power of 2 less than or equal to size
	int nextSmallestPowerSize = 1<<nextPower; // std::pow(2, nextPower); // Size of the next-smallest power of 2
	return std::min(arrays[nextPower][i], arrays[nextPower][j - nextSmallestPowerSize + 1]); // Return the minimum
}

// Validate the functions calculateMinInRange and range_min on randomly generated indices
void MinArrays::validateFunctions(int numTests) const {
	std::cout << "Validating functions...\n";
	// Perform numTests random tests
	for (int i = 0; i < numTests; ++i) {
		int index1 = rand() % n;
		int index2 = rand() % n;
		if (index1 > index2) {
			std::swap(index1, index2);
		}
		int calculatedMin = calculateMinInRange(index1, index2);
		int rangeMin = range_min(index1, index2);
		if (calculatedMin != rangeMin) {
			std::cout << "Test " << i + 1 << ": Range [" << index1 << ", " << index2 << "]\n";
			std::cout << "Validation failed!\n";
			std::cout << "calculateMinInRange result: " << calculatedMin << ", range_min result: " << rangeMin << std::endl;
			return;
		}
	}
	std::cout << "All validations passed!" << std::endl;
}