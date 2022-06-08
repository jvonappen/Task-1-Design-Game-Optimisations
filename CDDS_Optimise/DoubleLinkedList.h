#pragma once

class DoubleLinkedList
{
	class Node
	{
	public:
		int data;
		
		struct Node *previous;
		struct Node *next;
	};

private:
	Node *head;
	Node *tail;

public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void pushFront(int newData);						//- add a new value to the front of the list 
	void pushBack(int newData);							//- add a new value to the end of the list
	void insert(Node* previous, int newData);			//- add a new value one-past the specified iterator location
	auto begin();										//- return an iterator to the first element
	auto end();											//– return an iterator to a null element
	auto first();										//– return the first element by value, assert if no elements
	auto last();										//– return the last element by value, assert if no elements
	auto count();										//– return how many elements exist in the list
	auto erase(Node*);									//– remove an element by its iterator
	auto remove(int value);								//– remove all elements with matching value
	auto popBack();										//– remove the last element
	auto popFront();									//– remove the first element
	auto empty();										//– return a Boolean, true if the list is empty, false otherwise
	auto clear();										//– remove all elements from the list

	/* Need to add Sorting */





};