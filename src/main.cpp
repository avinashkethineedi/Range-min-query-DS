#include "RangeMin.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
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

	std::cout << "Window Size: " << rangeMin.getWindowSize() << std::endl;
	std::cout << "Number of Windows: " << rangeMin.getNumWindows() << std::endl;

	// rangeMin.printMinInWindow();

	rangeMin.validate();

	return 0;
}