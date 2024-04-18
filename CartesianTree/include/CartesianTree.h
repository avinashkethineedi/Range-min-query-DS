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
	void inorderTraversal(Node* root, std::vector<int>& result);
	void inorderTraversal(Node* root);

public:
	CartesianTree();
	~CartesianTree() = default; // Destructor
	void addElement(int value);
	std::vector<int> getElementsInOrder();
	bool buildAndCheck(int numElements);
	void printTree();
	void printLevels();
};

bool validateTrees(int numValidations, int maxElements);

#endif
