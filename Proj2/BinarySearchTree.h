#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include <iostream>

#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>

#include "Node.h"

/*  Noah Benham
	Miniproject 2
	26 Feb 2015
	C++ */

class BinarySearchTree
{
private:
	Node<std::string>* root = nullptr;

public:
	/**
	@description Default constructor
	@param N/A
	@return N/A - is a constructor
	*/
	BinarySearchTree();

	/**
	@description Custom constructor
	@param N/A
	@return N/A - is a constructor
	*/
	BinarySearchTree(std::vector<std::string> incomingVector);

	/**
	@description Default destructor
	@param N/A
	@return N/A - is a destructor
	*/
	~BinarySearchTree();

	/**
	@description Resucrisve helper for constructor
	@param N/A
	@return Node<std::string>*
	*/
	Node<std::string>* CreateGivenSortedVector(std::vector<std::string> vect, int start, int end);

	/**
	@description Should insert x in the BST.
	@param
	@return N/A - is type void
	*/
	void insert(const std::string str);

	/**
	@description Should delete x from the BST. For consistency when removing a data that has two children, use the smallest data in the right subtree of the data that should be removed in order to replace the removed data.
	@param
	@return N/A - is type void
	*/
	bool remove(const std::string str);

	/**
	@description Should delete x from the BST. For consistency when removing a data that has two children, use the smallest data in the right subtree of the data that should be removed in order to replace the removed data.
	@param
	@return N/A - is type void
	*/
	Node<std::string>* remove(Node<std::string>* root, const int x);

	/**
	@description Should find x in the BST and return a pointer to it, NULL if not found.
	@param
	@return bool
	*/
	bool search(const std::string x);

	/**
	@description Should print out all the elements of the BST using preorder traversal.
	@param
	@return N/A - is type void
	*/
	void preorder();

	/**
	@description Should print out all the elements of the BST using preorder traversal.
	@param Node* n
	@return N/A - is type void
	*/
	void preorder(Node<std::string>* n);
};

#endif
