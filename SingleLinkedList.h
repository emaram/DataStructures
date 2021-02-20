#ifndef __SINGLE_LINKED_LIST_H_
#define __SINGLE_LINKED_LIST_H_

class SingleLinkedList {
	
private:
	void init();

protected:				
	// Protected members accessible from child classes
	// e.g. SortedSingleLinkedList will have access to head, tail and _size
	//		but no access to private members

	struct Node {
		int value;
		Node* next;
	};

	Node* head;
	Node* tail;			// optional, but useful
	unsigned int _size;	// useful for keeping the number of nodes

public:
	SingleLinkedList();
	SingleLinkedList(int value);
	~SingleLinkedList();

	void addFirst(int value);
	void addLast(int value);
	void addNodeAtPos(unsigned int pos, int value);

	unsigned int size() { return this->_size; }

	int  getValue(unsigned int pos);
	void printList();

	void clearList();
	void deleteFirstNode();
	void deleteLastNode();

};

#endif
