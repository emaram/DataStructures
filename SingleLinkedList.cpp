#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

// ========================================================
SingleLinkedList::SingleLinkedList() {
	this->init();
}

// ========================================================
SingleLinkedList::SingleLinkedList(int value) {
	this->init();
	this->addFirst(value);
}

// ========================================================
void SingleLinkedList::init() {
	this->head = NULL;
	this->tail = NULL;
	this->_size = 0;
	cout << "Init, all NULL ..." << endl;
}

// ========================================================
SingleLinkedList::~SingleLinkedList() {
	cout << "Destructor ..." << endl;
	this->clearList();
}

// ========================================================
void SingleLinkedList::addFirst(int value) {
	// Create node
	Node* temp = new Node;
	temp->value = value;
	temp->next = NULL;
	if (this->_size == 0) {
		// this is the very first node in the list
		this->head = temp;
		this->tail = temp;
	}
	else {
		// insert before head
		temp->next = this->head;
		this->head = temp;
	}
	this->_size ++;
}

// ========================================================
void SingleLinkedList::addLast(int value) {
	// Create node
	Node* temp = new Node;
	temp->value = value;
	temp->next = NULL;
	if (this->_size == 0) {
		// this is the very first node in the list
		this->head = temp;
	}
	else {
		// add after tail
		this->tail->next = temp;
	}
	this->tail = temp;
	this->_size ++;
}

// ========================================================
void SingleLinkedList::addNodeAtPos(unsigned int pos, int value) {
	if (pos == 0) {
		this->addFirst(value);
		return;
	}
	if (pos >= this->_size) {
		this->addLast(value);
		return;
	}

	// Create node
	Node* temp = new Node;
	temp->value = value;
	temp->next = NULL;
	
	// Traverse the list until the pos
	Node* current = this->head;
	while (--pos > 0) {
		current = current->next;
	}

	// Add the node after current
	temp->next = current->next;
	current->next = temp;
	this->_size++;
}

// ========================================================
int SingleLinkedList::getValue(unsigned int pos) {
	int retval = __INT_MAX__;
	if (this->head == NULL)
		return retval;
	
	if (pos == 0)
		return this->head->value;
	if (pos >= this->_size - 1)
		return this->tail->value;
	
	// Traverse the list until the pos
	Node* current = this->head;
	while (--pos > 0) {
		current = current->next;
	}
	// It is not the current node, but the next one
	retval = current->next->value;
	return retval;
}

// ========================================================
void SingleLinkedList::printList() {
	if (this->head == NULL) {
		cout << "The list is empty" << endl;
		return;
	}
	Node* temp = this->head;
	while (temp != NULL) {
		cout << temp->value << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

// ========================================================
void SingleLinkedList::clearList() {
	while (this->head != NULL) {
		this->deleteFirstNode();
	}
}

// ========================================================
void SingleLinkedList::deleteFirstNode() {
	if (this->head != NULL) {
		Node* temp = this->head;
		this->head = this->head->next;
		delete temp;
		temp = NULL;
		if (this->_size > 0)
			this->_size--;
	}
}

// ========================================================
void SingleLinkedList::deleteLastNode() {
	if (this->tail != NULL) {
		Node* temp = this->head;
		Node* prev = temp;
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

