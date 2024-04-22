#include <iostream>
#include "CartesianTree.h"

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <numValidations> <maxElements>" << std::endl;
		return 1;
	}

	int numValidations = std::stoi(argv[1]);
	int maxElements = std::stoi(argv[2]);

	srand(10);//time(nullptr));

	bool isValid = validateTrees(numValidations, maxElements);

	if (isValid) {
		std::cout << "All trees are valid!" << std::endl;
	} else {
		std::cout << "Some trees are not valid!" << std::endl;
	}

	// Create a Cartesian tree with some random number of elements
	// CartesianTree tree;
	int numElements = 10;//rand() % 10 + 1; // Random number of elements (1 to 10)
	// for (int i = 0; i < numElements; ++i) {
	// 	int randomValue = rand() % 100;
	// 	tree.addElement(randomValue);
	// }
	CartesianTree tree({3, 2, 1, 8, 5, 9, 7, 12, 4, 6, 10, 7, 11, 12});

	// Print the Cartesian tree
	std::cout << "\nTree (Inorder traversal): ";
	tree.printTree();

	std::cout << "Tree (Level by level traversal):" << std::endl;
	tree.printLevels();

	// Print the Euler tour traversal sequence
	tree.printEulerTour();

	// Print the encoded Euler tour
	tree.printEncodedEulerTour();

	// Print the vector of pairs
	tree.printAppearanceLocations();

	// Create a Cartesian tree from a randomly generated vector
	std::vector<int> elements;
	numElements = 10;//rand() % 10 + 1; // Random number of elements (1 to 10)
	for (int i = 0; i < numElements; ++i) {
		int randomValue = rand() % 100;
		elements.push_back(randomValue);
	}
	CartesianTree treeFromVector(elements);

	// Print the Cartesian tree created from the vector
	std::cout << "\nTree from vector (Inorder traversal): ";
	treeFromVector.printTree();

	std::cout << "Tree from vector (Level by level traversal):" << std::endl;
	treeFromVector.printLevels();

	// Print the Euler tour traversal sequence
	treeFromVector.printEulerTour();

	// Print the encoded Euler tour
	treeFromVector.printEncodedEulerTour();

	// Print the vector of pairs
	tree.printAppearanceLocations();
	
	return 0;
}