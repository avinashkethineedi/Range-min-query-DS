#ifndef CARTESIANTREE_H
#define CARTESIANTREE_H

#include <vector>
#include <cstdint> // For uint64_t

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node* parent;

	Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

class CartesianTree {
private:
	Node* root;
	Node* rightmost; // Pointer to the rightmost node in the tree
	int size; // Variable to hold the size of the Cartesian tree

	Node* insert(Node* root, int value);
	void inorderTraversal(Node* root) const;
	void inorderTraversal(Node* root, std::vector<int>& result) const;
	void eulerTourTraversal(Node* root) const;
	void eulerTourTraversal(Node* root, std::vector<int>& result) const;
	void addEncodedSequence(Node* root, std::vector<int>& result) const;
	void calculateAppearanceLocations(Node* root, int &index, std::vector<std::pair<int, int>>& appearanceLocations) const;
	void destroyTree(Node* root); // Custom destructor to delete the Cartesian tree

public:
	CartesianTree();
	CartesianTree(const std::vector<int>& elements);
	CartesianTree(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
	~CartesianTree();
	void addElement(int value);
	std::vector<int> getElementsInOrder() const;
	bool buildAndCheck(int numElements);
	void printTree() const;
	void printLevels() const;
	std::vector<int> eulerTour() const;
	void printEulerTour() const;
	std::vector<int> encodeEulerTour() const; // Function to encode the Euler tour traversal
	void printEncodedEulerTour() const; // Function to print the encoded Euler tour
	std::vector<std::pair<int, int>> getAppearanceLocations() const;
	void printAppearanceLocations() const;
	uint64_t encodeEulerTourTo64Bit() const;
};

bool validateTrees(int numValidations, int maxElements);

#endif
