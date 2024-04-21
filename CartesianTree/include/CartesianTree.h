#ifndef CARTESIANTREE_H
#define CARTESIANTREE_H

#include <vector>

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

	Node* insert(Node* root, int value);
	void inorderTraversal(Node* root, std::vector<int>& result) const;
	void inorderTraversal(Node* root) const;
	void destroyTree(Node* root); // Custom destructor to delete the Cartesian tree
	void eulerTourTraversal(Node* root) const;
	void eulerTourTraversal(Node* root, std::vector<int>& result) const;
	void addEncodedSequence(Node* root, std::vector<int>& result) const;

public:
	CartesianTree();
	CartesianTree(const std::vector<int>& elements);
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
};

bool validateTrees(int numValidations, int maxElements);

#endif
