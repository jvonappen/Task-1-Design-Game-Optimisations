#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{

};

DoubleLinkedList::~DoubleLinkedList()
{
	
}
void DoubleLinkedList::pushFront(int newData)
{
	Node* newNode = new Node;
	newNode->data = newData;
	newNode->next = head;
	newNode->previous = nullptr;
	if (head != nullptr)
	{
		head->previous = newNode;
	}
	head = newNode;

}
void DoubleLinkedList::pushBack(int newData)
{
	Node* newNode = new Node;
	newNode->data = newData;
	newNode->next = nullptr;
	newNode->previous = tail;
	if (tail != nullptr)
	{
		tail->next = newNode;
	}
	tail = newNode;
}
void DoubleLinkedList::insert(Node* previous, int newData)
{
	Node* newNode = new Node;
	newNode->data = newData;
	newNode->next = previous->next;  //- sets next to newNode to next of previous Node
	previous->next = newNode;        //- sets next of previous Node to newNode
	newNode->previous = previous;    //- now sets previous of newNode to previous Node
	if (newNode->next != nullptr)
	{
		newNode->next->previous = newNode;
	}

}
auto DoubleLinkedList::begin()
{
}
auto DoubleLinkedList::end()
{
}
auto DoubleLinkedList::first()
{
}
auto DoubleLinkedList::last()
{
}
auto DoubleLinkedList::count()
{
}
auto DoubleLinkedList::erase(Node)
{
}
auto DoubleLinkedList::remove(int value)
{
}
auto DoubleLinkedList::popBack()
{
}
auto DoubleLinkedList::popFront()
{
}
;