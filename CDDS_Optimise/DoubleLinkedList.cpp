#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{

};

DoubleLinkedList::~DoubleLinkedList()
{
	
}
void DoubleLinkedList::pushFront(struct Node** head, int newData)
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
void DoubleLinkedList::pushBack(Node** head, int newData)
{
	struct Node* newNode = new Node;
	struct Node* tail = *head;
	newNode->data = newData;
	newNode->next = nullptr;
	if (*head == nullptr)
	{
		newNode->previous = nullptr;
		*head = newNode;
	}
	while (tail->next != nullptr)
	{
		tail = tail->next;
		tail->next = newNode;
		newNode->previous = tail;
		return;
	}
	
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