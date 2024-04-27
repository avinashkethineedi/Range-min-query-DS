#include "RangeMin.h"
#include <iostream>
#include <vector>
#include <chrono>

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

	std::cout << "Array Size: " << rangeMin.getArraySize() << std::endl;
	std::cout << "Window Size: " << rangeMin.getWindowSize() << std::endl;
	std::cout << "Number of Windows: " << rangeMin.getNumWindows() << std::endl;
	std::cout << "Lookup Table size: " << rangeMin.getLookupTableSize() << std::endl;

	// rangeMin.printArray();
	// rangeMin.printMinInWindow();
	// rangeMin.printWindowIndices(rangeMin.getNumWindows()-1);
	// rangeMin.validate();
	// rangeMin.printLookupTable();
	rangeMin.performRandomWindowTests(1000);
	rangeMin.performRandomTests(1000);

	// Vector to store the number of queries
	std::vector<int> numQueriesVec = {10, 100, 1000, 10000, 100000, 1000000, 10000000};

	// Vector to store timings
	std::vector<long long> timings;

	// Perform timing for different numbers of queries
	for (int numQueries : numQueriesVec) {
		// Time the range minimum queries and store the timing
		auto start = std::chrono::steady_clock::now(); // Start the timer
		rangeMin.timeRangeMinQueries(numQueries);
		auto end = std::chrono::steady_clock::now(); // Stop the timer

		// Calculate the elapsed time
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		
		// Store the timing
		timings.push_back(duration.count());
	}

	// Print the timings
	std::cout << "Timings for different numbers of queries:" << std::endl;
	for (size_t i = 0; i < numQueriesVec.size(); ++i) {
		std::cout << "Queries: " << numQueriesVec[i] << ", Time: " << timings[i] << " milliseconds" << std::endl;
	}

	return 0;
}