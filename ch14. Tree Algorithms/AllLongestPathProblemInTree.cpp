/*============================================================================
 * Problem : Finding longest path to leaf for all nodes in a tree.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int  NO_OF_VERTICES = 6;

void dfs(int startIndex, int currDepth, int* maxDepth, vector<int> adj[], bool visited[])
{

	currDepth++;
	visited[startIndex]=true;
	for(auto i:adj[startIndex])
	{
		if(!visited[i])
		{
			if(currDepth>*maxDepth)
				*maxDepth=currDepth;
			dfs(i,currDepth,maxDepth,adj,visited);
		}

	}

}

void allLongestPath(vector<int> adj[])
{

	int distance[NO_OF_VERTICES]={0};

	for(int startIndex=0;startIndex<NO_OF_VERTICES;startIndex++)
	{
		bool visited[NO_OF_VERTICES]={false};
		int maxDepth=INT32_MIN;
		int currDepth=0;
		dfs(startIndex,currDepth,&maxDepth,adj,visited);
		distance[startIndex]=maxDepth;
	}

	for(int i=0;i<NO_OF_VERTICES;i++)
		cout<<"longest path till leaf from node "<<i<<" is = "<<distance[i]<<endl;

}

int main()
{

	vector<int> adj[NO_OF_VERTICES];

	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[0].push_back(2);
	adj[2].push_back(0);
	adj[0].push_back(3);
	adj[3].push_back(0);

	adj[1].push_back(4);
	adj[4].push_back(1);
	adj[1].push_back(5);
	adj[5].push_back(1);

	allLongestPath(adj);

	return 0;

}
