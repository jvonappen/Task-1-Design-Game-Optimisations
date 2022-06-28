//#include "DoubleLinkedList.h"
//
//DoubleLinkedList::DoubleLinkedList()
//{
//
//};
//
//DoubleLinkedList::~DoubleLinkedList()
//{
//	for (Node* node = head; node != nullptr;)
//	{
//		//Node* next = 
//	}
//}
//void DoubleLinkedList::pushFront(int newData)		//- add a new value to the front of the list 
//{
//	Node* newNode = new Node;
//	newNode->data = newData;
//	newNode->next = head;
//	newNode->previous = nullptr;
//	if (head != nullptr)
//	{
//		head->previous = newNode;
//	}
//	head = newNode;
//
//}
//void DoubleLinkedList::pushBack(int newData)		//- add a new value to the end of the list	
//{
//	Node* newNode = new Node;
//	newNode->data = newData;
//	newNode->next = nullptr;
//	newNode->previous = tail;
//	if (tail != nullptr)
//	{
//		tail->next = newNode;
//	}
//	tail = newNode;
//}
//void DoubleLinkedList::insert(Node* previous, int newData)		//- add a new value one-past the specified iterator location
//{
//	Node* newNode = new Node;
//	newNode->data = newData;
//	newNode->next = previous->next;  //- sets next to newNode to next of previous Node
//	previous->next = newNode;        //- sets next of previous Node to newNode
//	newNode->previous = previous;    //- now sets previous of newNode to previous Node
//	if (newNode->next != nullptr)
//	{
//		newNode->next->previous = newNode;
//	}
//
//}
//auto DoubleLinkedList::begin()				//- return an iterator to the first element
//{
//	return head;
//}
//auto DoubleLinkedList::end()				//– return an iterator to a null element
//{
//	return nullptr;
//}
//auto DoubleLinkedList::first()				//– return the first element by value, assert if no elements
//{
//}
//auto DoubleLinkedList::last()				//– return the last element by value, assert if no elements
//{
//}
//auto DoubleLinkedList::count()				//– return how many elements exist in the list
//{
//}
////auto DoubleLinkedList::erase(Node)			//– remove an element by its iterator
////{
////}
//auto DoubleLinkedList::remove(int value)	//– remove all elements with matching value
//{
//}
//auto DoubleLinkedList::popBack()			//– remove the last element
//{
//}
//auto DoubleLinkedList::popFront()			//– remove the first element
//{
//}
//auto DoubleLinkedList::empty()				//– return a Boolean, true if the list is empty, false otherwise
//{
//}
//auto DoubleLinkedList::clear()				//– remove all elements from the list
//{
//}
//;