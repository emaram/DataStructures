#ifndef __SORTED_SINGLE_LINKED_LIST_H_
#define __SORTED_SINGLE_LINKED_LIST_H_

#include "SingleLinkedList.h"

class SortedSingleLinkedList : public SingleLinkedList {

private:
	bool _ascending;

public:
	SortedSingleLinkedList(bool asc = true);
	SortedSingleLinkedList(int value, bool asc = true);
	~SortedSingleLinkedList();

	void insertNode(int value);

};

#endif