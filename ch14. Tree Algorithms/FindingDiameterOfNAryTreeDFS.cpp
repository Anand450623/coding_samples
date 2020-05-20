/*============================================================================
 * Problem : Finding diameter of n-ary tree using DFS.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int  NO_OF_VERTICES = 5;

void dfs(int vertice, vector<int> adj[], int* maxCount, int count, int* maxDistVertice,bool visited[])
{

	count++;
	visited[vertice]=true;
	for(auto i:adj[vertice])
	{
		if(!visited[i])
		{
			if(count >= *maxCount)
			{
				*maxCount = count;
				*maxDistVertice = i;
			}
			dfs(i,adj,maxCount,count,maxDistVertice,visited);
		}
	}
}

void findDiameter(vector<int> adj[])
{

	int maxCount = INT32_MIN;
	int maxDistVertice = 0;
	bool visited[NO_OF_VERTICES] = {false};

	dfs(0,adj,&maxCount,1,&maxDistVertice,visited);

	for(int i=0; i<NO_OF_VERTICES; i++)
		visited[i]=false;

	dfs(maxDistVertice,adj,&maxCount,1,&maxDistVertice,visited);

	cout<<"The Diameter of tree is = "<<maxCount<<endl;

}


int main()
{

	vector<int> adj[NO_OF_VERTICES];

	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[0].push_back(2);
	adj[2].push_back(0);
	adj[1].push_back(3);
	adj[3].push_back(1);
	adj[1].push_back(4);
	adj[4].push_back(1);

	findDiameter(adj);

	return 0;

}
