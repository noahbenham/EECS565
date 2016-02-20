/*  Noah Benham
	Miniproject 2
	26 Feb 2015
	C++ */

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() { // Constructor
		
}

BinarySearchTree::BinarySearchTree(std::vector<std::string> incomingVector) { // Custom constructor
	root = CreateGivenSortedVector(incomingVector, 0, incomingVector.size() - 1);
}

Node<std::string>* BinarySearchTree::CreateGivenSortedVector(std::vector<std::string> vect, int start, int end) {
	/* Base Case */
	if (start > end)
		return nullptr;

	/* Get the middle element and make it root */
	int mid = (start + end) / 2;
	Node<std::string>* root = new Node<std::string>(vect[mid]);

	/* Recursively construct the left subtree and make it
	left child of root */
	root->setLeft(CreateGivenSortedVector(vect, start, mid - 1));

	/* Recursively construct the right subtree and make it
	right child of root */
	root->setRight(CreateGivenSortedVector(vect, mid + 1, end));

	return root;
}

BinarySearchTree::~BinarySearchTree() { // Destructor
	while (root != nullptr)
		remove(root->getData());
}

//void BinarySearchTree::insert(const std::string x) {
//	if (search(x) != nullptr) {
//		std::cout << "Cannot insert " << x << ", it already exists.\n";
//		return; // found in list; do not insert
//	}
//
//	Node* temp = new Node(x);
//
//	if (root == nullptr) {
//		root = temp;
//		return;
//	}
//
//	Node* current;
//	current = root;
//	Node* parent;
//	parent = root;
//
//	current = (temp->getData() < current->getData()) ? (current->getLeft()) : (current->getRight());
//	while (current != nullptr) {
//		parent = current;
//		current = (temp->getData() < current->getData()) ? (current->getLeft()) : (current->getRight());
//	}
//	if (temp->getData() < parent->getData()) {
//		parent->setLeft(temp);
//	}
//	if (temp->getData() > parent->getData()) {
//		parent->setRight(temp);
//	}
//}

bool BinarySearchTree::remove(const std::string str) {
	if (root == nullptr)
			return false;

	if (root->getData() == str) {
		Node<std::string> auxRoot(0);
		auxRoot.setLeft(root);
		Node<std::string>* removedNode = root->remove(str, &auxRoot);
		root = auxRoot.getLeft();
		if (removedNode != nullptr) {
			delete removedNode;
			return true;
		}
		else
			return false;
		}
		else {
			Node<std::string>* removedNode = root->remove(str, nullptr);
			if (removedNode != nullptr) {
				delete removedNode;
				return true;
			}
			else
				return false;
		}
}

bool BinarySearchTree::search(const std::string x) {
	Node<std::string>* temp = root;

	while (temp != nullptr) {
		if (temp->getData() == x)
			break;

		if (x > temp->getData())
			temp = temp->getRight();
		else if (x < temp->getData())
				temp = temp->getLeft();
	}

	if (temp == nullptr)
		return false;

	if (temp->getData() == x)
		return true;

	return false; // not found
}

void BinarySearchTree::preorder() {
	preorder(root);
}

void BinarySearchTree::preorder(Node<std::string>* n) {
	if (n != nullptr) {
		std::cout << n->getData() << "\n";
		preorder(n->getLeft());
		preorder(n->getRight());
	}
}
