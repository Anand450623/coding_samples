/*============================================================================
 * Problem : Implement Prim's Algorithm to find minimum spanning tree from a given graph.
 * Link    : https://www.hackerrank.com/challenges/primsmstsub/problem
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int prims(int startNode, vector<pair<int,int>> adj[], unsigned int noOfVertice)
{

	bool visited[noOfVertice+1]={false};
	vector<int> selectedEdgeWeights;
	priority_queue<pair<int,int>> q;
	visited[startNode]=true;
	unsigned sum = 0;

	for(auto i: adj[startNode])
		q.push({-i.second,i.first});
	selectedEdgeWeights.push_back(startNode);

	while(!q.empty() || selectedEdgeWeights.size()==noOfVertice-1)
	{

		int wt,dest;
		tie(wt,dest) = q.top();
		q.pop();

		if(visited[dest])
			continue;
		else
		{

			visited[dest] = true;
			selectedEdgeWeights.push_back(dest);
			sum += (-wt);
			for(auto i:adj[dest])
				q.push({-i.second,i.first});

		}

	}

	return sum;

}

int main()
{

	unsigned int NO_OF_VERTICES;
	unsigned int NO_OF_EDGES;
	int startNode;

	cin>>NO_OF_VERTICES>>NO_OF_EDGES;

	vector<pair<int,int>> adj[NO_OF_VERTICES+1];

	for(int i=0;i<NO_OF_EDGES;i++)
	{

		int a,b,c;
		cin>>a>>b>>c;

		adj[a].push_back({b,c});
		adj[b].push_back({a,c});

	}

	cin>>startNode;

	cout<<prims(startNode,adj,NO_OF_VERTICES);

	return 0;

}
