#include "MinArrays.h"

MinArrays::MinArrays(int size) {
	n = size;
	logN = static_cast<int>(std::log2(n));
	arrays.resize(logN + 1, std::vector<int>(n));
	srand(10);
}

MinArrays::MinArrays(int size, const std::vector<int>& values) {
	n = size;
	logN = static_cast<int>(std::log2(n));
	arrays.resize(logN + 1, std::vector<int>(n));
	fillFirstArray(values);
}

MinArrays::MinArrays(const std::vector<int>& values) {
	n = values.size();
	logN = static_cast<int>(std::log2(n));
	arrays.resize(logN + 1, std::vector<int>(n));
	fillFirstArray(values);
}

void MinArrays::fillFirstArray(const std::vector<int>& values) {
	if (values.size() != n) {
		std::cerr << "Size of the given vector doesn't match the size of the array.\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		arrays[0][i] = values[i];
	}
}

void MinArrays::randomizeFirstArray() {
	for (int i = 0; i < n; ++i) {
		arrays[0][i] = rand() % 100; // Fill with random numbers between 0 and 99
	}
}

void MinArrays::calculateRemainingArrays() {
	for (int i = 1; i <= logN; ++i) {
		for (int j = 0; j < n; ++j) {
			int power = std::pow(2, i - 1);
			arrays[i][j] = std::min(arrays[i - 1][j], arrays[i - 1][std::min(j + power, n - 1)]);
		}
	}
}

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

void MinArrays::printArrays() const {
	for (int i = 0; i <= logN; ++i) {
		printArrayAtIndex(i);
	}
}

void MinArrays::setValue(int arrayIndex, int index, int value) {
	if (arrayIndex >= 0 && arrayIndex <= logN && index >= 0 && index < n) {
		arrays[arrayIndex][index] = value;
	} else {
		std::cout << "Invalid array index or index\n";
	}
}

int MinArrays::getValue(int arrayIndex, int index) const {
	if (arrayIndex >= 0 && arrayIndex <= logN && index >= 0 && index < n) {
		return arrays[arrayIndex][index];
	} else {
		std::cout << "Invalid array index or index\n";
		return -1; // return -1 to indicate error
	}
}

int MinArrays::calculateMinInRange(int i, int j) const {
	if (i >= 0 && i < n && j >= 0 && j < n) {
		int minVal = arrays[0][i];
		for (int index = i + 1; index <= j; ++index) {
			minVal = std::min(minVal, arrays[0][index]);
		}
		return minVal;
	} else {
		std::cout << "Invalid indices\n";
		return -1; // return -1 to indicate error
	}
}

int MinArrays::range_min(int i, int j) const {
	int size = j - i + 1;
	int nextPower = static_cast<int>(std::log2(size));
	int nextSmallestPowerSize = std::pow(2, nextPower);
	return std::min(arrays[nextPower][i], arrays[nextPower][j - nextSmallestPowerSize + 1]);
}

void MinArrays::validateFunctions(int numTests) const {
	for (int t = 0; t < numTests; ++t) {
		int i = rand() % n;
		int j = rand() % n;
		if (i > j) {
			std::swap(i, j);
		}
		int minInRange = calculateMinInRange(i, j);
		int rangeMin = range_min(i, j);
		if (minInRange != rangeMin) {
			std::cout << "Validation failed for indices " << i << " to " << j << "!" << std::endl;
			std::cout << "calculateMinInRange(): " << minInRange << ", range_min(): " << rangeMin << std::endl;
			return;
		}
	}
	std::cout << "All validations passed!" << std::endl;
}