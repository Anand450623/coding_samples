/*============================================================================
 * Problem : Implement Topological Sort in a Directed Acyclic Graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int NO_OF_VERTICES=6;

void topologicalSort(int vertice, vector<int> adj[], int noOfVertices, bool visited[], int state[], stack<int> &s)
{

	/*
	 * Here, State 0 for node denotes not visited
	 * State 1 for node denotes under process or inside recursion stack
	 * State 2 represents processed.
	*/

	visited[vertice]=true;
	state[vertice]=1;
	for(auto i:adj[vertice])
	{
		if(state[i]==1)
			cout<<"Warning : cycle found in graph\n";
		if(!visited[i])
			topologicalSort(i,adj, noOfVertices, visited, state,s);
	}

	state[vertice]=2;
	s.push(vertice);

}

int main()
{

	int noOfVertices = NO_OF_VERTICES+1;

	vector<int> adj[noOfVertices];
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(6);
	adj[4].push_back(1);
	adj[4].push_back(5);
	adj[5].push_back(2);
	adj[5].push_back(3);	//this edge is for normal topological sorting.
	//adj[3].push_back(5);	//this edge forms cycle

	bool visited[noOfVertices]={false};
	int state[noOfVertices]={0};
	stack<int> s;

	for(int i=1;i<noOfVertices;i++)
		if(!visited[i])
			topologicalSort(i,adj, noOfVertices, visited, state,s);

	cout<<"The topological sort is as below...\n";
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;

}
