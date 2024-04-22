#include "CartesianTree.h"
#include <iostream>
#include <cstdlib> // for rand
#include <ctime>   // for time
#include <queue>   // for std::queue

// Function to insert a new node with the given value into the Cartesian tree
Node* CartesianTree::insert(Node* root, int value) {
	// Create a new node with the given value
	Node* newNode = new Node(value);

	// If the tree is empty, make the new node as the root and rightmost
	if (root == nullptr) {
		rightmost = newNode;
		return newNode;
	}

	// Insert the new node as the right child of the rightmost node
	rightmost->right = newNode;
	newNode->parent = rightmost;
	rightmost = newNode;

	// Rotate the parent node if necessary
	Node* current = newNode;
	while (current->parent != nullptr && current->parent->data > current->data) {
		Node* parent = current->parent;
		Node* grandparent = parent->parent;

		// Rotate the parent node with its child and adjust the pointers
		parent->right = current->left;
		if (current->left != nullptr)
			current->left->parent = parent;
		current->left = parent;

		current->parent = grandparent;
		parent->parent = current;
		if (grandparent != nullptr) {
			grandparent->right = current;
		} else {
			root = current; // Update root if current node becomes new root
		}
	}

	return root;
}

// Helper function to print the Cartesian tree in inorder traversal
void CartesianTree::inorderTraversal(Node* root) const {
	if (root != nullptr) {
		inorderTraversal(root->left);
		std::cout << root->data << " ";
		inorderTraversal(root->right);
	}
}

// Helper function to perform inorder traversal and fill elements into a vector
void CartesianTree::inorderTraversal(Node* root, std::vector<int>& result) const {
	if (root != nullptr) {
		inorderTraversal(root->left, result);
		result.push_back(root->data);
		inorderTraversal(root->right, result);
	}
}

// Helper function for Euler tour traversal
void CartesianTree::eulerTourTraversal(Node* root) const {
	if (root != nullptr) {
		std::cout << root->data << " "; // Visit current node
		
		if (root->left != nullptr) {
			eulerTourTraversal(root->left); // Visit left subtree
			std::cout << root->data << " "; // Visit current node again
		}
		
		if (root->right != nullptr) {
			eulerTourTraversal(root->right); // Visit right subtree
			std::cout << root->data << " "; // Visit current node again
		}
	}
}

// Helper function for Euler tour traversal
void CartesianTree::eulerTourTraversal(Node* root, std::vector<int>& result) const {
	if (root != nullptr) {
		result.push_back(root->data); // Visit current node
		
		if (root->left != nullptr) {
			eulerTourTraversal(root->left, result); // Visit left subtree
			result.push_back(root->data); // Visit current node again
		}
		
		if (root->right != nullptr) {
			eulerTourTraversal(root->right, result); // Visit right subtree
			result.push_back(root->data); // Visit current node again
		}
	}
}

// Helper function to add encoded sequences during Euler tour traversal
void CartesianTree::addEncodedSequence(Node* root, std::vector<int>& result) const {
	if (root != nullptr) {
		if (root->left != nullptr) {
			result.push_back(1); // Encode path down as 1
			addEncodedSequence(root->left, result); // Visit left subtree
			result.push_back(0); // Encode path up as 0
		}

		if (root->right != nullptr) {
			result.push_back(1); // Encode path down as 1
			addEncodedSequence(root->right, result); // Visit right subtree
			result.push_back(0); // Encode path up as 0
		}
	}
}

// Helper function for Euler tour traversal to calculate appearance locations of nodes
void CartesianTree::calculateAppearanceLocations(Node* root, int &index, std::vector<std::pair<int, int>>& appearanceLocations) const {
	if (root != nullptr) {
		std::pair<int, int> nodeAppearance(index, index);
		int loc;
		index++;

		if (root->left != nullptr) {
			calculateAppearanceLocations(root->left,  index,  appearanceLocations); // Visit left subtree
			nodeAppearance.second = index++;
		}
		loc = appearanceLocations.size();
		appearanceLocations.push_back(nodeAppearance);
		if (root->right != nullptr) {
			calculateAppearanceLocations(root->right, index,  appearanceLocations); // Visit right subtree
			appearanceLocations[loc].second = index++;
		}
	}
}

// Destructor to delete the Cartesian tree
void CartesianTree::destroyTree(Node* root) {
	if (root != nullptr) {
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
	}
}

// Constructor
CartesianTree::CartesianTree() : root(nullptr), rightmost(nullptr), size(0){}

// Constructor to build tree from vector
CartesianTree::CartesianTree(const std::vector<int>& elements) : root(nullptr), rightmost(nullptr), size(0) {
	for (int elem : elements) {
		addElement(elem);
	}
}

// Constructor to build tree from vector iterators
CartesianTree::CartesianTree(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) : root(nullptr), rightmost(nullptr), size(0) {
	while (begin != end) {
		addElement(*begin);
		++begin;
	}
}

// Custom destructor to delete the Cartesian tree
CartesianTree::~CartesianTree() {
	destroyTree(root);
}

// Function to add a new element to the Cartesian tree
void CartesianTree::addElement(int value) {
	root = insert(root, value);
	++size; // Increment the size after adding an element
}

// Function to return all elements in the tree in a vector after inorder traversal
std::vector<int> CartesianTree::getElementsInOrder() const {
	std::vector<int> result;
	inorderTraversal(root, result);
	return result;
}

// Function to build a vector of random elements, add them to the Cartesian tree,
// retrieve elements from the inorder traversal, and check if they match the initial vector
bool CartesianTree::buildAndCheck(int numElements) {
	std::vector<int> randomElements;
	for (int i = 0; i < numElements; ++i) {
		int randomValue = rand() % 100;
		randomElements.push_back(randomValue);
	}
	for (int elem : randomElements) {
		addElement(elem);
	}

	std::vector<int> inorderElements = getElementsInOrder();

	if (randomElements.size() != inorderElements.size()) {
		return false;
	}
	for (int i = 0; i < randomElements.size(); ++i) {
		if (randomElements[i] != inorderElements[i]) {
			return false;
		}
	}

	return true;
}

// Function to print the Cartesian tree in inorder traversal
void CartesianTree::printTree() const {
	inorderTraversal(root);
	std::cout << std::endl;
}

// Function to print the Cartesian tree level by level
void CartesianTree::printLevels() const {
	if (root == nullptr)
		return;

	std::queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		int levelSize = q.size();
		for (int i = 0; i < levelSize; ++i) {
			Node* node = q.front();
			q.pop();
			std::cout << node->data << " ";
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
		}
		std::cout << std::endl;
	}
}

// Function to perform Euler tour traversal
std::vector<int> CartesianTree::eulerTour() const {
	std::vector<int> result;
	eulerTourTraversal(root, result);
	return result;
}

// Function to print the Euler tour traversal sequence
void CartesianTree::printEulerTour() const {
	std::cout << "Euler Tour Traversal Sequence: ";
	eulerTourTraversal(root);
	std::cout << std::endl;
}

// Function to encode the Euler tour traversal
std::vector<int> CartesianTree::encodeEulerTour() const {
	std::vector<int> result;
	addEncodedSequence(root, result);
	return result;
}

// Function to print the encoded Euler tour
void CartesianTree::printEncodedEulerTour() const {
	std::vector<int> encodedTour = encodeEulerTour();
	for (int value : encodedTour) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}

// Function to get the vector of pairs indicating appearance locations of nodes in Euler tour traversal
std::vector<std::pair<int, int>> CartesianTree::getAppearanceLocations() const {
	std::vector<std::pair<int, int>> appearanceLocations;
	int index = 0;
	calculateAppearanceLocations(root, index, appearanceLocations);
	return appearanceLocations;
}

// Function to print the appearance locations of nodes in the Cartesian tree
void CartesianTree::printAppearanceLocations() const {
	std::vector<std::pair<int, int>> appearanceLocations;
	int index = 0;
	calculateAppearanceLocations(root, index, appearanceLocations);
	std::cout << "Node Appearance Locations:" << std::endl;
	for (const auto& pair : appearanceLocations) {
		std::cout << "(" << pair.first << ", " << pair.second << ") ";
	}
	std::cout << std::endl;
}

// Function to validate the CartesianTree by creating a new tree and calling build and validate function
bool validateTrees(int numValidations, int maxElements) {
	for (int i = 0; i < numValidations; ++i) {
		{
			CartesianTree tree;
			// int numElements = rand() % maxElements + 1; // Random number of elements (1 to maxElements)
			int numElements = maxElements + 1;
			if (!tree.buildAndCheck(numElements)) {
				return false;
			}
		}
	}
	return true;
}