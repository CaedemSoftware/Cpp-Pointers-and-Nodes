//	LinkedBag340.cpp
//	Created by: CSC340

/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===
*/
#include "LinkedBag.h"
#include <iostream>
#include <time.h>
#include <memory>
using namespace std;

template <typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
	ItemType item = headPtr->getNext()->getItem();
	remove(item);
	return 0;
	//Node<ItemType>* entryPtr = headPtr->getNext();//second node
	//entryPtr.data = head.data;//remove second’s data
	//deletePtr = head;
	//head = head.next;
	//deletePtr.next = nullptr;
	//delete deletePtr;
	//deletePtr = nullptr;

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
//	int getCurrentSize340Iterative() const {
//		return 0;
//	}
//	int getCurrentSize340Recursive() const {
//		return 0;
//	}
//int getCurrentSize340RecursiveNoHelper() const {
//	return 0;}
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
