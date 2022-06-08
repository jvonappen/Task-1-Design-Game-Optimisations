#pragma once
#include <vector>
#include <list> /* Need to change and use the DoubleLinkedList when done */

class Graph
{
	class Node;


	class Edge										/* Defines an edge/link */
	{
	public:
		Edge(Node* t = nullptr) : target(t) {}
		virtual ~Edge() {}
		Node* target;
		void* userData;
	};


	class Node
	{
	public:
		Node(){}
		virtual ~Node() {}
		std::vector<Edge*> edges;			/* List of edges */
		void* userData;
	};
};
