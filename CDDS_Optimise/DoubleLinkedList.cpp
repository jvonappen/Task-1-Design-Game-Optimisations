#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{

};

DoubleLinkedList::~DoubleLinkedList()
{
	
}
int DoubleLinkedList::pushFront(struct Node** head, int newData)
{
	struct Node* newNode = new Node;
	newNode->data = newData;
	newNode->next = (*head);
	newNode->previous = nullptr;
	if ((*head) != nullptr)
	{
		(*head)->previous = newNode;
	}
	(*head) = newNode;

}
int DoubleLinkedList::pushBack(Node** tail, int newData)
{
	struct Node* newNode = new Node;
	struct Node* tail = nullptr;
	newNode->data = newData;
	newNode->next = nullptr;
	*tail = newNode;
	return;
}
void DoubleLinkedList::insert(Node* previous, int newData)
{
	struct Node* newNode = new Node;
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
;