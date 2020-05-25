/*============================================================================
 * Problem : Find the number of paths from source node to all other nodes in a Directed Acyclic Graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int NO_OF_VERTICES = 6;

//topological sort using kahn's algorithm
int* topologicalSort(vector<int> adj[], int freq[], int noOfVertices)
{

	int* topology = new int[noOfVertices];
	queue<int> q;
	int index=1;
	int nodeCount=1;

	for(int i=1;i<noOfVertices;i++)
	{
		if(freq[i]==0)
		{
			q.push(i);
			topology[index++]=i;
			nodeCount++;
		}
	}

	while(!q.empty())
	{

		int item = q.front();
		q.pop();

		for(auto i:adj[item])
		{
			freq[i]--;
			if(freq[i]==0)
			{
				q.push(i);
				topology[index++]=i;
				nodeCount++;
			}
		}
	}

	if(nodeCount!=noOfVertices)
		cout<<"warning: presence of cycle detected";

	return topology;

}

void calculateNumberOfPaths(int startingNode, vector<int> adj[], vector<int> inOrderList[], int noOfVertices)
{

	int freq[noOfVertices];
	for(int i=1;i<noOfVertices;i++)
		freq[i] = inOrderList[i].size();

	int* topology = topologicalSort(adj,freq,noOfVertices);
	int dp[noOfVertices]={0};
	dp[startingNode]=1;
	int index;

	for(int i=1;i<noOfVertices;i++)
		if(topology[i]==startingNode)
		{
			index=i;
			break;
		}

	//Logic to calculate the total possible count of path to other node from source node.
	for(int i=index;i<noOfVertices;i++)
	{
		for(auto item:inOrderList[topology[i]])
		{
			dp[topology[i]] += dp[item];
		}
	}

	for(int i=1;i<noOfVertices;i++)
		cout<<"Number of path from "<<startingNode<<" to "<<i<<" = "<<dp[i]<<endl;

}


int main()
{

	int noOfVertices = NO_OF_VERTICES+1;
	vector<int> adj[noOfVertices];
	vector<int> inOrderList[noOfVertices];
	int startingNode=1;

	adj[1].push_back(2);
	adj[1].push_back(4);
	adj[2].push_back(3);
	adj[3].push_back(6);
	adj[4].push_back(5);
	adj[5].push_back(2);
	adj[5].push_back(3);

	for(int i=1;i<noOfVertices;i++)
		for(auto item:adj[i])
			inOrderList[item].push_back(i);

	calculateNumberOfPaths(startingNode,adj,inOrderList,noOfVertices);

	return 0;

}
