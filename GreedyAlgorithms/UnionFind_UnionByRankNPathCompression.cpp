#include<iostream>

using namespace std;

struct Edge
{
	int src;
	int dest;
};

struct Graph
{
	int V, E;
	struct Edge *edge;
};

struct subset
{
	int parent;
	int rank;
};

struct Graph *createGraph(int v, int e)
{
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

	graph->V = v;
	graph->E = e;

	graph->edge = (struct Edge *)malloc(sizeof(struct Edge) * graph->E);

	return graph;
}

int find(struct subset *subsets, int i)
{
	if (subsets[i].parent == i)
		return subsets[i].parent;

	subsets[i].parent = find(subsets, subsets[i].parent);
}

void Union(struct subset *subsets, int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}

}

int isCycle(struct Graph *graph)
{
	int V = graph->V;
	int E = graph->E;

	struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));

	for (int v = 0; v < V; v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	for (int e = 0; e < E; e++)
	{
		int x = find(subsets, graph->edge[e].src);
		int y = find(subsets, graph->edge[e].dest);

		if (x == y)
			return 1;

		Union(subsets, x, y);
	}

	return 0;
}

int main()
{
	int v = 3, e = 3;

	struct Graph *graph = createGraph(v, e);

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	if (isCycle(graph))
		cout << "Graph contains cycles" << endl;
	else
		cout << "Graph does not contain cycles" << endl;


}