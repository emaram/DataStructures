#ifndef __SINGLE_LINKED_LIST_H_
#define __SINGLE_LINKED_LIST_H_

class SingleLinkedList {
	
private:
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
	void insertNode(int pos, int value);

	unsigned int size() { return this->_size; }

	int  getValue(int pos);
	void printList();

	void clearList();
	void deleteFirstNode();
	void deleteLastNode();

private:
	void init();

};

#endif
