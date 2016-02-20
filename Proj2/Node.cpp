/*  Noah Benham
	Miniproject 2
	26 Feb 2015
	C++ */

template <typename T>
Node<T>::Node() {
	data = nullptr;
	leftChild = nullptr;
	rightChild = nullptr;
}

template <typename T>
Node<T>::Node(const T& anItem) {
	data = anItem;
	leftChild = nullptr;
	rightChild = nullptr;
}

template <typename T>
Node<T>::Node(const T& anItem, Node<T>* leftChildPtr, Node<T>* rightChildPtr) {
	data = anItem;
	leftChild = leftChildPtr;
	rightChild = rightChildPtr;
}

template <typename T>
void Node<T>::setData(const T& anItem) {
	data = anItem;
}

template <typename T>
void Node<T>::setLeft(Node<T>* leftChildPtr) {
	leftChild = leftChildPtr;
}

template <typename T>
void Node<T>::setRight(Node<T>* rightChildPtr) {
	rightChild = rightChildPtr;
}

template <typename T>
T Node<T>::getData() {
	return data;
}

template <typename T>
Node<T>* Node<T>::getLeft() {
	return leftChild;
}

template <typename T>
Node<T>* Node<T>::getRight() {
	return rightChild;
}

template <typename T>
Node<T>* Node<T>::remove(T data, Node<T>* parent) {
      if (data < this->data) {
            if (leftChild != nullptr)
                  return leftChild->remove(data, this);
            else
                  return nullptr;
      } else if (data > this->data) {
            if (rightChild != nullptr)
                  return rightChild->remove(data, this);
            else
                  return nullptr;
      } else {
            if (leftChild != nullptr && rightChild != nullptr) {
                  this->data = rightChild->minValue();
                  return rightChild->remove(this->data, this);
            } else if (parent->leftChild == this) {
                  parent->leftChild = (leftChild != nullptr) ? leftChild : rightChild;
                  return this;
            } else if (parent->rightChild == this) {
                  parent->rightChild = (leftChild != nullptr) ? leftChild : rightChild;
                  return this;
            }
      }
}

template <typename T>
T Node<T>::minValue() {
	if (leftChild == nullptr)
		return data;
	else
		return leftChild->minValue();
}
