#include "SingleLinkedList.h"
#include "SortedSingleLinkedList.h"
#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

#define __TEST__

void Test_SingleLinkedList() {
	SingleLinkedList sll;
	cout << "a) Generating 30 random values (0..100) ... " << endl;
	cout << "   - value -> add first" << endl;
	cout << "   - 2*value -> add last" << endl;
	int val = 0, pos = 0;
	for (int i = 0; i < 10; i++) {
		val = rand() % 40;
		sll.addFirst(val);
		sll.addLast(2 * val);
	}
	sll.printList();

	pos = rand() % 15;
	val = rand() % 50;
	cout << "b) Adding " << val << " at position " << pos << " ... " << endl;
	sll.addNodeAtPos(pos, val);
	sll.printList();
	pos = rand() % 15;
	val = rand() % 50;
	cout << "c) Adding " << val << " at position " << pos << " ... " << endl;
	sll.addNodeAtPos(pos, val);
	sll.printList();
	cout << "d) Removing last node ... " << endl;
	sll.deleteLastNode();
	sll.printList();
	cout << "e) Removing first node ... " << endl;
	sll.deleteFirstNode();
	sll.printList();
	cout << "f) Element at position  0 has value: " << sll.getValue(0) << endl;
	cout << "   Element at position  4 has value: " << sll.getValue(4) << endl;
	cout << "   Element at position 99 has value: " << sll.getValue(99) << endl;
	cout << "   Last element has value:           " << sll.getValue(sll.size() - 1) << endl;
 	cout << "g) Clearing the list ... " << endl;
	sll.clearList();
	sll.printList();
}

void Test_SortedSingleLinkedList(bool asc) {
	SortedSingleLinkedList sll(asc);
	cout << "a) Generating 30 random values (0..100) ... " << endl;
	int val = 0;
	for (int i = 0; i < 10; i++) {
		val = rand() % 40;
		sll.insertNode(val);
	}
	sll.printList();
	val = rand() % 50;
	cout << "b) Adding a new value: " << val << " ... " << endl;
	sll.insertNode(val);
	sll.printList();
	cout << "c) Removing last node ... " << endl;
	sll.deleteLastNode();
	sll.printList();
	cout << "d) Removing first node ... " << endl;
	sll.deleteFirstNode();
	sll.printList();
	cout << "e) Clearing the list ... " << endl;
	sll.clearList();
	sll.printList();
}

void Test_DoubleLinkedList() {
	DoubleLinkedList dll;
	cout << "a) Generating 30 random values (0..100) ... " << endl;
	cout << "   - value -> add first" << endl;
	cout << "   - 2*value -> add last" << endl;
	int val = 0, pos = 0;
	for (int i = 0; i < 10; i++) {
		val = rand() % 40;
		dll.addFirst(val);
		dll.addLast(2 * val);
	}
	dll.printList();

	pos = rand() % 15;
	val = rand() % 50;
	cout << "b) Adding " << val << " at position " << pos << " ... " << endl;
	dll.addNodeAtPos(pos, val);
	dll.printList();
	pos = rand() % 15;
	val = rand() % 50;
	cout << "c) Adding " << val << " at position " << pos << " ... " << endl;
	dll.addNodeAtPos(pos, val);
	dll.printList();
	cout << "d) Removing last node ... " << endl;
	dll.deleteLastNode();
	dll.printList();
	cout << "e) Removing first node ... " << endl;
	dll.deleteFirstNode();
	dll.printList();
	cout << "f) Element at position  0 has value: " << dll.getValue(0) << endl;
	cout << "   Element at position  4 has value: " << dll.getValue(4) << endl;
	cout << "   Element at position 99 has value: " << dll.getValue(99) << endl;
	cout << "   Last element has value:           " << dll.getValue(dll.size() - 1) << endl;
 	cout << "g) Clearing the list ... " << endl;
	dll.clearList();
	dll.printList();
}



int main() {
	cout << "-----------------------------------------------------------" << endl;
	cout << "Testing Single Linked List ..." << endl;
	cout << "-----------------------------------------------------------" << endl;
	Test_SingleLinkedList();

	cout << "-----------------------------------------------------------" << endl;
	cout << "Testing Sorted Single Linked List ... ASCENDING ..." << endl;
	cout << "-----------------------------------------------------------" << endl;
	Test_SortedSingleLinkedList(true);

	cout << "-----------------------------------------------------------" << endl;
	cout << "Testing Sorted Single Linked List ... DESCENDING ..." << endl;
	cout << "-----------------------------------------------------------" << endl;
	Test_SortedSingleLinkedList(false);
	
	cout << "-----------------------------------------------------------" << endl;
	cout << "Testing Double Linked List ..." << endl;
	cout << "-----------------------------------------------------------" << endl;
	Test_DoubleLinkedList();

	return 0;
}