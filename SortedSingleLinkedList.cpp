#include "SortedSingleLinkedList.h"
#include <iostream>
using namespace std;

// ========================================================
SortedSingleLinkedList::SortedSingleLinkedList(bool asc) : SingleLinkedList() {
	this->_ascending = asc;
	cout << "Constructor - (Sorted) ..." << endl;
}

// ========================================================
SortedSingleLinkedList::SortedSingleLinkedList(int value, bool asc) : SingleLinkedList(value) {
	this->_ascending = asc;
	cout << "Constructor(" << value << ") - (Sorted) ..." << endl;
}

// ========================================================
SortedSingleLinkedList::~SortedSingleLinkedList() {
	cout << "Destructor - (Sorted) ..." << endl;
}

// ========================================================
void SortedSingleLinkedList::insertNode(int value) {
	if (this->_size == 0) {
		this->addFirst(value);
	}
	else {
		Node * current = this->head;
		if (this->_ascending) {
			if (current->value > value)				// check if bigger
				this->addFirst(value);
			else {
				int pos = 0;
				while (current->next != NULL) {
					current = current->next;
					pos++;
					if (current->value > value) {	// check if bigger
						this->addNodeAtPos(pos, value);
						break;
					}
				}
				if (pos == this->_size - 1)
					this->addLast(value);
			}
		}
		else {
			if (current->value < value)				// check if smaller
				this->addFirst(value);
			else {
				int pos = 0;
				while (current->next != NULL) {
					current = current->next;
					pos++;
					if (current->value < value) {	// check if smaller
						this->addNodeAtPos(pos, value);
						break;
					}
				}
				if (pos == this->_size - 1)
					this->addLast(value);
			}
		}
	}
}