# Data Structures

This project presents in a simple form the concept of data structures dynamic memory allocation:
- Single Linked List
- Double Linked List
- Circular Single Linked List (tbd)
- Circular Double Linked List (tbd)
- Binary Tree (tbd)

> I've created this project for academic purposes, in order to allow studying potential ways of creating, manipulating, displaying and removing various data structures. There are plenty of libraries in github, as well as part of STL, boost, etc. They are better written, perform more tasks and own a stronger memory management. However, in order to become a professional user of e.g. std::list<T>, one must properly understand what's happening behind the scene. That is what I'm trying to cover.

## Single Linked List
In computer science, a linked list is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. (Wikipedia, https://en.wikipedia.org/wiki/Linked_list).

In a Single Linked List, a node is represented by its value, that could be of any type, and a pointer to the next node in the list.

| value | next | 
|-------|------| 

```
struct Node {
	int value;
	Node* next;
};
```

An example of Single Linked List could be the following:

```
5 -> 7 -> 12 -> 2 -> NULL
```

Two important nodes in the list are the first one (usually called head) and the last one (usually called tail). The tail will always point to NULL

> A special single linked list is, in my personal view, the sorted single linked list. It behaves exactly as a single linked list, but when added a new node, it makes sure it is added at the right place, in such way that the list is always sorted (ascending or descending).

## Double Linked List
In a Double Linked List, a node is represented by its value, that could be of any type, a pointer to the next node in the list, as well as a pointer to the previous node (if any).

| prev | value | next | 
|------|-------|------| 

```
struct DoubleNode {
	int value;
	DoubleNode* next;
	DoubleNode* prev;
};
```

An example of Double Linked List could be the following:

```
NULL <-> 5 <-> 7 <-> 12 <-> 2 <-> NULL
```
