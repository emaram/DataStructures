#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;

// ========================================================
DoubleLinkedList::DoubleLinkedList() {
	this->init();
}

// ========================================================
DoubleLinkedList::DoubleLinkedList(int value) {
	this->init();
	this->addFirst(value);
}

// ========================================================
void DoubleLinkedList::init() {
	this->head = NULL;
	this->tail = NULL;
	this->_size = 0;
	cout << "Init, all NULL ..." << endl;
}

// ========================================================
DoubleNode* DoubleLinkedList::createNode(int value) {
	// Create node
	DoubleNode* temp = new DoubleNode;
	temp->value = value;
	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}

// ========================================================
DoubleLinkedList::~DoubleLinkedList() {
	cout << "Destructor ..." << endl;
	this->clearList();
}

// ========================================================
void DoubleLinkedList::addFirst(int value) {
	DoubleNode* temp = this->createNode(value);
	if (this->_size == 0) {
		// this is the very first node in the list
		this->head = temp;
		this->tail = temp;
	}
	else {
		// insert before head ... temp->prev remains NULL
		temp->next = this->head;
		this->head = temp;
	}
	this->_size ++;
}

// ========================================================
void DoubleLinkedList::addLast(int value) {
	DoubleNode* temp = this->createNode(value);
	if (this->_size == 0) {
		// this is the very first node in the list
		this->head = temp;
	}
	else {
		// add after tail ... temp->next remains NULL
		this->tail->next = temp;
		temp->prev = this->tail;
	}
	this->tail = temp;
	this->_size ++;
}

// ========================================================
void DoubleLinkedList::addNodeAtPos(unsigned int pos, int value) {
	if (pos == 0) {
		this->addFirst(value);
		return;
	}
	if (pos >= this->_size) {
		this->addLast(value);
		return;
	}

	DoubleNode* temp = this->createNode(value);
	
	// Traverse the list until the pos
	DoubleNode* current = this->head;
	while (--pos > 0) {
		current = current->next;
	}

	// Add the node after current
	temp->next = current->next;
	temp->prev = current;
	current->next = temp;
	this->_size++;
}

// ========================================================
int DoubleLinkedList::getValue(unsigned int pos) {
	// int retval = __INT_MAX__;
	if (this->head == NULL)
		return __INT_MAX__;
	
	return this->getNode(pos)->value;
}

// ========================================================
DoubleNode* DoubleLinkedList::getNode(unsigned int pos) {
	if (this->head == NULL)
		return NULL;
	if (pos == 0)
		return this->head;
	if (pos >= this->size() - 1)
		return this->tail;

	// Traverse the list until the pos
	DoubleNode* current = this->head;
	while (--pos > 0) {
		current = current->next;
	}
	// It is not the current node, but the next one
	return current->next;
}

// ========================================================
void DoubleLinkedList::printList() {
	if (this->head == NULL) {
		cout << "The list is empty" << endl;
		return;
	}
	cout << "NULL <-> ";
	DoubleNode* temp = this->head;
	while (temp != NULL) {
		cout << temp->value << " <-> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

// ========================================================
void DoubleLinkedList::clearList() {
	while (this->head != NULL) {
		this->deleteFirstNode();
	}
}

// ========================================================
void DoubleLinkedList::deleteFirstNode() {
	if (this->head != NULL) {
		DoubleNode* temp = this->head;
		this->head = this->head->next;
		if (this->head != NULL)
			this->head->prev = NULL;
		delete temp;
		temp = NULL;
		if (this->_size > 0)
			this->_size--;
	}
}

// ========================================================
void DoubleLinkedList::deleteLastNode() {
	if (this->tail != NULL) {
		DoubleNode* temp = this->head;
		DoubleNode* prev = temp;
		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		tail = prev;
		delete temp;
		temp = NULL;
		if (this->_size > 0)
			this->_size--;
	}
}

