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
	int sizeCount1 = 1;
	if (nextNode->getNext() != nullptr) {
		sizeCount1 += getCurrentSize340RecursiveHelper(nextNode->getNext());
		return sizeCount1;
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
	static Node<ItemType>* iteratePtr = headPtr;//skips static reassignment in successive calls
	if (iteratePtr->getNext() != nullptr) {
		sizeCount++;
		iteratePtr = iteratePtr->getNext();
		getCurrentSize340RecursiveNoHelper();
	}
	return sizeCount;
}

template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* nowNode, const ItemType& item) const {
	static int frequency = 0;//make global
	frequency = 0;//reassign to zero
	if (nowNode->getNext() != nullptr) {
		getFrequencyOf340RecursiveHelper(nowNode->getNext(), item);
	}
	if (nowNode->getItem() == item) {
		frequency++;
	}
	return frequency;
}// if needed

template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& item) const {
	int frequency = 0;
	frequency = getFrequencyOf340RecursiveHelper(headPtr, item);
	return frequency;
}

template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& item) const {
	if (isEmpty()) {
		return 0;
	}
	static int frequency = 0;
	static Node<ItemType>* curPtr = headPtr;
	if (curPtr == headPtr) {//reset when starting over
		frequency = 0;
	}
	if (curPtr->getItem() == item) {
		frequency++;
	}
	if (curPtr->getNext() != nullptr) {//loop
		curPtr = curPtr->getNext();
		getFrequencyOf340RecursiveNoHelper(item);
	}
	curPtr = headPtr;//reset at end
	return frequency;
}

template <typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
	ItemType itemRemoved;
	int max = getCurrentSize();
	int deleteIndex = rand() % max;
	Node<ItemType>* iteratePtr = headPtr;
	while (deleteIndex != 0) {
		iteratePtr = iteratePtr->getNext();
		deleteIndex--;
	}
	itemRemoved = iteratePtr->getItem();
	remove(iteratePtr->getItem());
	return itemRemoved;
}

