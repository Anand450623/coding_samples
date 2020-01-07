/*
 * Problem : Given a graph, use Breadth First Search to traverse it.
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

	void BFSUtils(bool visited[],int start_index)
	{

		queue<int> q;
		q.push(start_index);
		visited[start_index]=true;

		while(!q.empty())
		{
			int curr_ele = q.front();
			cout<<curr_ele<<" ";


			q.pop();

			for(auto i:this->adj[curr_ele])
				if(!visited[i])
				{
					visited[i]=true;
					q.push(i);
				}

		}

	}

	void BFS(int start_index)
	{
		bool visited[this->N];
		for(int i=0;i<this->N;i++)
			visited[i] = false;

		BFSUtils(visited,start_index); // if starting index is there

		for(int i=0;i<this->N;i++)
			if(!visited[i])
				BFSUtils(visited,i);

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

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
	return 0;
}
