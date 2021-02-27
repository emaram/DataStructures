#ifndef __DOUBLE_LINKED_LIST_H_
#define __DOUBLE_LINKED_LIST_H_

struct DoubleNode {
	int value;
	DoubleNode* next;
	DoubleNode* prev;
};


class DoubleLinkedList {
	
private:
	void init();
	DoubleNode* createNode(int value);

protected:				
	// Protected members accessible from child classes
	// e.g. SortedSingleLinkedList will have access to head, tail and _size
	//		but no access to private members

	DoubleNode* head;
	DoubleNode* tail;			// optional, but useful
	unsigned int _size;	// useful for keeping the number of nodes

public:
	DoubleLinkedList();
	DoubleLinkedList(int value);
	~DoubleLinkedList();

	void addFirst(int value);
	void addLast(int value);
	void addNodeAtPos(unsigned int pos, int value);

	unsigned int size() { return this->_size; }

	int  getValue(unsigned int pos);
	DoubleNode* getNode(unsigned int pos);
	void printList();

	void clearList();
	void deleteFirstNode();
	void deleteLastNode();

};

#endif
