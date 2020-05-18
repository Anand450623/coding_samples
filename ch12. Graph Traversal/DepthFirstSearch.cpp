/*============================================================================
 * Problem : Implement Depth First Search Algorithm.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int NO_OF_VERTICES=5;

void dfs(int vertice,vector<int> adj[], bool visited[])
{
	if(visited[vertice])
		return;
	else
	{
		cout<<vertice<<" ";
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
	adj[1].push_back(4);
	adj[2].push_back(4);
	adj[0].push_back(3);

	cout<<"The dfs result for the given graph is as follows --->\n";
	//0,1,2,4,3

	dfs(0,adj,visited);

	return 0;

}
