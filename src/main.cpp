#include "RangeMin.h"
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <size>" << std::endl;
		return 1;
	}

	unsigned int size = std::stoul(argv[1]);

	if (size == 0) {
		std::cerr << "Size must be a positive integer." << std::endl;
		return 1;
	}

	RangeMin rangeMin(size);

	// rangeMin.printArray();

	std::cout << "Array Size: " << rangeMin.getArraySize() << std::endl;
	std::cout << "Window Size: " << rangeMin.getWindowSize() << std::endl;
	std::cout << "Number of Windows: " << rangeMin.getNumWindows() << std::endl;
	std::cout << "Lookup Table size: " << rangeMin.getLookupTableSize() << std::endl;

	// rangeMin.printMinInWindow();

	// rangeMin.printWindowIndices(rangeMin.getNumWindows()-1);

	// rangeMin.validate();
	// rangeMin.printLookupTable();
	rangeMin.performRandomWindowTests(1000);
	rangeMin.performRandomTests(100000);

	return 0;
}