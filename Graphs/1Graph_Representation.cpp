#include<iostream>

using namespace std;

struct AdjListNode
{
	int dest;
	struct AdjListNode *next;
};

struct AdjList
{
	struct AdjListNode *head;
};

struct Graph
{
	int V;
	struct AdjList *array;
};

struct Graph *createGraph(int v)
{
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->V = v;
	graph->array = (struct AdjList *)malloc(v * sizeof(struct AdjList));

	for (int i = 0; i < v; i++)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

void addEdge(struct Graph *g, int src, int dest)
{
	struct AdjListNode *newnode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
	newnode->dest = dest;
	newnode->next = g->array[src].head;
	g->array[src].head = newnode;

	newnode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
	newnode->dest = src;
	newnode->next = g->array[dest].head;
	g->array[dest].head = newnode;
}

void printGraph(struct Graph *graph)
{
	int v;

	for (v = 0; v < graph->V; v++)
	{
		struct AdjListNode *temp = graph->array[v].head;

		while (temp != NULL)
		{
			cout << temp->dest;
			temp = temp->next;
		}
		cout << endl;
	}
}

int main()
{
	int v = 5;
	struct Graph *graph = createGraph(v);

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printGraph(graph);
}