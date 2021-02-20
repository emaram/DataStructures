#include "SingleLinkedList.h"
#include "SortedSingleLinkedList.h"
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
	cout << "f) Clearing the list ... " << endl;
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

	return 0;
}