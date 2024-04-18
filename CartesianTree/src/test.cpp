#include <iostream>
#include "CartesianTree.h"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <numValidations> <maxElements>" << std::endl;
		return 1;
	}

	int numValidations = std::stoi(argv[1]);
	int maxElements = std::stoi(argv[2]);

	srand(time(nullptr));

	bool isValid = validateTrees(numValidations, maxElements);

	if (isValid) {
		std::cout << "All trees are valid!" << std::endl;
	} else {
		std::cout << "Some trees are not valid!" << std::endl;
	}

	// Create a Cartesian tree with some random number of elements
	CartesianTree tree;
	int numElements = 10;
	for (int i = 0; i < numElements; ++i) {
		int randomValue = rand() % 100;
		tree.addElement(randomValue);
	}

	// Print the Cartesian tree
	std::cout << "Tree (Inorder traversal): ";
	tree.printTree();
	std::cout << std::endl;

	std::cout << "Tree (Level by level traversal):" << std::endl;
	tree.printLevels();

	return 0;
}