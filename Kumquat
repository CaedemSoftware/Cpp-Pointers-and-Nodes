//	LinkedBag340.cpp
//	Created by: Ze Lei and Jimmy Nguyen CSC340

#include "LinkedBag.h"
#include <iostream>
#include <time.h>
#include <memory>
using namespace std;

template <typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
	Node<ItemType>* entryNodePtr = headPtr->getNext();
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

	if (canRemoveItem) {
		entryNodePtr->setItem(headPtr->getItem());
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		itemCount--;
	}

	return canRemoveItem;
}

template <typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newItem) {
	Node<ItemType>* nextNodePtr = new Node<ItemType>();
	nextNodePtr->setItem(newItem);
	Node<ItemType>* iteratePtr = headPtr;
	while (iteratePtr->getNext() != nullptr) {//stops at last Node
		iteratePtr = iteratePtr->getNext();
	}
	iteratePtr->setNext(nextNodePtr);
	itemCount++;
	return true;
}

template <typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
	if (isEmpty()) {
		return 0;
	}
	int sizeCount = 1;
	Node<ItemType>* iteratePtr = headPtr;
	while (iteratePtr->getNext() != nullptr) {//stops at last Node
		sizeCount++;
		iteratePtr = iteratePtr->getNext();
	}
	return sizeCount;
}

template <typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* nextNode) const {
	if (nextNode->getNext() != nullptr) {
		getCurrentSize340RecursiveHelper(nextNode->getNext());
	}
	return 1;
}

template <typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
	if (isEmpty()) {
		return 0;
	}
	int sizeCount = 1;
	Node<ItemType>* iteratePtr = headPtr;
	sizeCount += getCurrentSize340RecursiveHelper(iteratePtr->getNext());
	return sizeCount;
}

template <typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
	if (isEmpty()) {
		return 0;
	}
	static int sizeCount = 1;
	static Node<ItemType>* iteratePtr = headPtr;
	if (iteratePtr->getNext() != nullptr) {
		sizeCount++;
		iteratePtr = iteratePtr->getNext();
		getCurrentSize340RecursiveNoHelper();
	}
	return sizeCount;
}
//int getFrequencyOf340Recursive(const ItemType&) const {
//	return 0;
//}
//int getFrequencyOf340RecursiveNoHelper(const ItemType&) const{
//	return 0;}
//ItemType removeRandom340() {
//	return 0;
//}
//int getCurrentSize340RecursiveHelper(Node<ItemType>*) const {
//	return 0;
//}// if needed
//int getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType&) const {
//	return 0;
//}// if needed
