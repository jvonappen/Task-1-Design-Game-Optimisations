#include <vector>
#include "Graph.h"

class Graph
{
	class Node;

	class Edge										/* Defines an edge/link */
	{
	public:
		Edge(Node* t = nullptr) : target(t) {}
		virtual ~Edge() {}

		Node* target;

		void* userData = nullptr;
	};

	class Node
	{
	public:
		Node() {}
		virtual ~Node() {}

		std::vector<Edge*> edges;					/* List of edges */
		void* userData = nullptr;
	};
};