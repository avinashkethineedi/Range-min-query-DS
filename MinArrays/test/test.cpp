#include <iostream>
#include "MinArrays.h"

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <array_size> <num_tests>\n";
		return 1;
	}

	int size = std::stoi(argv[1]);
	int numTests = std::stoi(argv[2]);

	MinArrays minArrays(size);
	// minArrays.printArrays();
	minArrays.validateFunctions(numTests);

	return 0;
}