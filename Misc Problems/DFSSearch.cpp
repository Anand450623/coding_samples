/*
 * Problem : Given a graph, use Depth First Search to traverse it.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int N;
	list<int> *adj;

	public:

	Graph()
	{
		N=0;
		adj = NULL;
	}

	Graph(int N)
	{
		this->N=N;
		this->adj = new list<int>[N];
	}

	void addEdge(int v,int n)
	{
		this->adj[v].push_back(n);
	}

	void DFSUtils(bool visited[],int node)
	{
		visited[node] = true;
		cout<<node<<" ";
		for(auto i:adj[node])
			if(!visited[i])
				DFSUtils(visited,i);
	}

	void DFSSearch(int start_node)
	{
		bool visited[this->N];
		for(int i=0;i<N;i++)
			visited[i] = false;

		DFSUtils(visited,start_node);// if given start node

		for (int i = 0; i < this->N; i++) // if start node is not known and graph has some disconnected component
			if (!visited[i])
				DFSUtils(visited,i);
	}

};


int main()
{

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFSSearch(2);
	return 0;
}
