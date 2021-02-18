#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

int main() {
	SingleLinkedList list;
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