/*============================================================================
 * Problem : Implement an algorithm to find Eulerian path in a Undirected Graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void findEulerianPath(int startingNode, vector<int> adj[])
{

	while(adj[startingNode].size())
	{

		int next = adj[startingNode].back();

		cout<<startingNode<<" "<<next<<endl;

		adj[startingNode].pop_back();
		auto it = find(adj[next].begin(), adj[next].end(), startingNode);
		adj[next].erase(it);

		startingNode = next;

	}

}

void checkForEulerianPath(vector<int> adj[], int noOfVertices)
{

	int degree[noOfVertices] = {0};

	for(int i=1;i<noOfVertices;i++)
		for(auto x:adj[i])
			degree[x]++;

	int oddCount = 0;
	int startingNode = 1;
	for(int i=1;i<noOfVertices;i++)
	{
		if(degree[i]%2)
		{
			oddCount++;
			startingNode = i;
		}
	}

	if(oddCount==0)
	{
		cout<<"Eulerian path & circuit possible for given graph\n";
		findEulerianPath(startingNode, adj);
	}
	else if(oddCount ==2)
	{
		cout<<"Only eulerian path possible for given graph\n";
		findEulerianPath(startingNode, adj);
	}
	else
		cout<<"Eulerian Path not possible";

}

int main()
{

	int NO_OF_VERTICES = 7;
	vector<int> adj[NO_OF_VERTICES+1];

	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[1].push_back(3);
	adj[3].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(2);
	adj[2].push_back(5);
	adj[5].push_back(2);
	adj[2].push_back(6);
	adj[6].push_back(2);
	adj[5].push_back(6);
	adj[6].push_back(5);
	adj[3].push_back(4);
	adj[4].push_back(3);
	adj[3].push_back(6);
	adj[6].push_back(3);
	adj[6].push_back(7);
	adj[7].push_back(6);
	adj[4].push_back(7);
	adj[7].push_back(4);

	//checkForEulerianPath(adj, NO_OF_VERTICES+1);

	vector<int> adj1[6];
	adj1[1].push_back(2);
	adj1[2].push_back(1);
	adj1[1].push_back(4);
	adj1[4].push_back(1);
	adj1[2].push_back(4);
	adj1[4].push_back(2);
	adj1[3].push_back(2);
	adj1[2].push_back(3);
	adj1[5].push_back(2);
	adj1[2].push_back(5);
	adj1[3].push_back(5);
	adj1[5].push_back(3);

	//checkForEulerianPath(adj1, 6);

	vector<int> adj2[6];

	adj2[1].push_back(2);
	adj2[2].push_back(1);
	adj2[1].push_back(4);
	adj2[4].push_back(1);
	adj2[2].push_back(3);
	adj2[3].push_back(2);
	adj2[3].push_back(5);
	adj2[5].push_back(3);
	adj2[4].push_back(5);
	adj2[5].push_back(4);
	adj2[2].push_back(5);
	adj2[5].push_back(2);

	checkForEulerianPath(adj2, 6);

	vector<int> adj3[6];

	adj3[1].push_back(2);
	adj3[2].push_back(1);
	adj3[1].push_back(3);
	adj3[3].push_back(1);
	adj3[3].push_back(2);
	adj3[2].push_back(3);
	adj3[4].push_back(2);
	adj3[2].push_back(4);
	adj3[5].push_back(2);
	adj3[2].push_back(5);
	adj3[4].push_back(5);
	adj3[5].push_back(4);

	//checkForEulerianPath(adj3, 6);

	return 0;

}
