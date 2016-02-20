#ifndef _NODE_H_
#define _NODE_H_

/*  Noah Benham
	Miniproject 2
	26 Feb 2015
	C++ */

#include <cstddef>

template <typename T>
class Node
{
private:
	T data; // A data item
	Node* leftChild; // Pointer to next node
	Node* rightChild; // Pointer to next node
   
public:
	Node();
	Node(const T& anItem);
	Node(const T& anItem, Node* leftChildPtr, Node* rightChildPtr);
	void setData(const T& anItem);
	void setLeft(Node* leftChildInt);
	void setRight(Node* rightChildInt);
	T getData();
	Node* getLeft();
	Node* getRight();
	Node* remove(T data, Node* parent);
	T minValue();
}; // end Node

#include "Node.cpp"

#endif
