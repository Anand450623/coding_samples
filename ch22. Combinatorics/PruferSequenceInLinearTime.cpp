/*============================================================================
 * Problem : Implement code to obtain prufer's sequence for a given tree with n nodes in linear time.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int n, int parent[], vector<int> adj[])
{
	for(int u: adj[n])
	{
		if(u != parent[n])
		{
			parent[u] = n;
			dfs(u, parent, adj);
		}
	}
}

void pruferSequence(vector<int> adj[], int size)
{

	int parent[size] = {0};
	parent[size-1] = -1;
	dfs(size-1, parent, adj);

	int ptr = -1;
	int degree[size] = {0};
	for(int i=1; i<size; i++)
	{
		degree[i] = adj[i].size();
		if(degree[i] == 1 && ptr == -1)
			ptr = i;
	}

	vector<int> code;
	for(int i=1; i<size-2; i++)
	{
		int next = parent[ptr];
		code.push_back(next);

		if(--degree[next]==1 && next<ptr)
			ptr = next;
		else
		{
			ptr++;
			while(degree[ptr] != 1)
				ptr++;
		}

	}

	for(auto x: code)
		cout<<x<<" ";
	cout<<endl;

}

int main()
{

	int n =  6;
	vector<int> adj[n];

	adj[1].push_back(4);
	adj[2].push_back(4);
	adj[2].push_back(5);
	adj[3].push_back(4);
	adj[4].push_back(1);
	adj[4].push_back(2);
	adj[4].push_back(3);
	adj[5].push_back(2);

	pruferSequence(adj, n);

	return 0;

}
