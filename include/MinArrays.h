#ifndef MINARRAYS_H
#define MINARRAYS_H

#include <iostream>
#include <vector>
#include <cmath>

class MinArrays {
private:
	std::vector<std::vector<int>> arrays;
	int n; // size of each array
	int logN; // number of arrays = log base 2 of N

public:
	MinArrays(int size);
	MinArrays(int size, const std::vector<int>& values);
	MinArrays(const std::vector<int>& values);
	void fillFirstArray(const std::vector<int>& values);
	void randomizeFirstArray();
	void calculateRemainingArrays();
	void printArrayAtIndex(int arrayIndex) const;
	void printArrays() const;
	void setValue(int arrayIndex, int index, int value);
	int getValue(int arrayIndex, int index) const;
	int calculateMinInRange(int i, int j) const;
	int range_min(int i, int j) const;
	void validateFunctions(int numTests) const;
	int getSize() const { return n; }
};

#endif // MINARRAYS_H