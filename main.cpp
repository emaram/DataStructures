#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

#define __TEST__

int main() {
	SingleLinkedList list;
#ifdef __TEST__
	int val = 0;
	for (int i = 0; i < 30; i++) {
		val = rand() % 45;
		if (val % 3 == 0)
			list.addFirst(val);
		else if (val % 3 == 1)
			list.addLast(val);
		else
			list.insertNode(2, val);
		list.printList();
	}
#else
	int val = 0;
	while (val >= 0) {
		cout << "Input val (0 or negative for exit): ";
		cin >> val;
		list.addFirst(val);
		list.addLast(2*val);
		
		list.printList();
	}
	cout << "Now trying to add at pos 3. Please input val: ";
	cin >> val;
	list.insertNode(3, val);
	list.printList();
#endif

	cout << "Node at pos 3 is " << list.getValue(3) << endl;
 	cout << "Deleting 2 nodes ..." << endl;
	list.deleteFirstNode();
	list.printList();
	list.deleteLastNode();
	list.printList();

	cout << "Clearing the list ..." << endl;
	list.clearList();
	list.printList();
	return 0;
}