#include<iostream>
#include<list>

using namespace std;

class Graph 
{
	int V;
	list<int> *adj;
	void DFSUtil(int v, bool *visited);
public:
	Graph(int v);
	void addEdge(int u, int v);
	void DFS(int s);
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph::DFSUtil(int s, bool *visited)
{
	visited[s] = true;

	cout << s << "\t";

	list<int>::iterator i;

	for (i = adj[s].begin(); i != adj[s].end(); i++)
	{
		if (!visited[*i])
			DFSUtil(*i, visited);
	}
}

void Graph::DFS(int s)
{
	bool *visited = new bool[V];

	for (int i = 0; i < V; i++)
		visited[i] = false;

	//Call the recursive helper function for traversal
	DFSUtil(s, visited);
}

int main()
{
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "DFS of the graph starting at vertex 2" << endl;
	g.DFS(2);
	cout << endl;

}