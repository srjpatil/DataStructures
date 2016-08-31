#include<stdio.h>
#include<malloc.h>

struct Edge
{
	int src, dest;
};

struct Graph
{
	int V, E;

	struct Edge *edge;
};

struct Graph *createGraph(int v, int e)
{
	struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
	g->V = v;
	g->E = e;
	g->edge = (struct Edge*)malloc(sizeof(struct Edge) * (g->E));

	return g;
}

int find(int *parent, int i)
{
	if (parent[i] == -1)
		return i;

	return find(parent, parent[i]);
}

void Union(int *parent, int x, int y)
{
	int xset = find(parent, x);
	int yset = find(parent, y);

	parent[xset] = yset;
}

int isCycle(struct Graph *g)
{
	//create V subsets.
	int *parent = (int *)malloc(sizeof(int) * (g->V));

	//Initialize all subsets as single element subsets.
	memset(parent, -1, sizeof(int) * (g->V));

	for (int i = 0; i < g->E; i++)
	{
		int x = find(parent, g->edge[i].src);
		int y = find(parent, g->edge[i].dest);

		if (x == y)
			return 1;

		Union(parent, x, y);
	}

	return 0;
}

int main()
{
	int v = 3, e = 3;
	struct Graph *g = createGraph(v, e);

	g->edge[0].src = 0;
	g->edge[0].dest = 1;

	g->edge[1].src = 1;
	g->edge[1].dest = 2;

	g->edge[2].src = 0;
	g->edge[2].dest = 2;

	if (isCycle(g))
		printf("Graph contains cycles\n");
	else
		printf("Graph does not contain cycles\n");
}