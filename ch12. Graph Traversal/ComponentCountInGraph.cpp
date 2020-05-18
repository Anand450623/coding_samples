/*============================================================================
 * Problem : Implement Connectivity Check in a graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int NO_OF_VERTICES=6;

void dfs(int vertice, vector<int> adj[], bool visited[])
{
	if(visited[vertice])
		return;
	else
	{
		visited[vertice]=true;
		for(auto i:adj[vertice])
			dfs(i,adj,visited);
	}
}


int main()
{

	vector<int> adj[NO_OF_VERTICES];
	bool visited[NO_OF_VERTICES]={false};

	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(0);

	adj[3].push_back(4);

	int count = 0;
	for(int i=0;i<NO_OF_VERTICES;i++)
	{
		if(!visited[i])
			count++;
		dfs(i,adj,visited);
	}

	cout<<"Number  of components in graph is = "<<count<<endl;

	return 0;

}
