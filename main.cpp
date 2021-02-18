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
	// list.printList();
	// list.addFirst(3);
	// list.printList();
	// list.addLast(10);
	// list.printList();
	// list.addLast(11);
	// list.printList();
	// list.addLast(12);
	// list.printList();
	// list.addLast(13);
	// list.printList();	
	list.deleteFirstNode();
	list.printList();
	list.deleteLastNode();
	list.printList();
	return 0;
}