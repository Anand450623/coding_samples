/*============================================================================
 * Problem : Implement tarzan's offline algorithm for calculating LCA.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int find(int node, int ancestor[])
{
	while(ancestor[node]!=node)
		node = ancestor[node];
	return node;
}

void dfs(int startNode, bool visited[], vector<int> adj[], vector<int> traversal, int ancestor[], map<int,int> queries)
{

	ancestor[startNode] = startNode;

	int node;
	int other;
	bool found = false;
	for(auto it:queries)
	{
		if(it.first==startNode)
		{
			node = it.first;
			other = it.second;
			found = true;
			break;
		}
		else if(it.second==startNode)
		{
			node = it.second;
			other = it.first;
			found = true;
			break;
		}
	}

	if(found && visited[other])
		cout<<"the lowest common ancestor of "<<node<<" and "<<other<<" is = "<<find(other,ancestor)<<endl;

	for(int i:adj[startNode])
	{
		dfs(i,visited,adj,traversal,ancestor,queries);
		visited[i] = true;
		ancestor[i] = startNode;
	}

	visited[startNode]=true;

}

int main()
{

	int NO_OF_VERTICES = 8;
	int ancestor[NO_OF_VERTICES+1] = {0};
	bool visited[NO_OF_VERTICES+1] = {false};
	vector<int> adj[NO_OF_VERTICES+1];
	vector<int> traversal;

	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(4);
	adj[2].push_back(5);
	adj[2].push_back(6);
	adj[6].push_back(8);
	adj[4].push_back(7);

	map<int,int> queries;
	queries.insert({5,8});
	queries.insert({2,7});

	int startNode = 1;
	dfs(startNode, visited, adj, traversal, ancestor, queries);

	return 0;

}
