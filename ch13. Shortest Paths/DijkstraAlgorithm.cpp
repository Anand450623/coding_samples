/*============================================================================
 * Problem : Implement Dijkstra's Algorithm for single source shortest path.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void dijkstra(int source,vector<pair<int,int>> adj[], int noOfVertices)
{

	int distance[noOfVertices];
	bool processed[noOfVertices]={false};
	priority_queue<pair<int,int>> pq;

	for(int i=0;i<noOfVertices;i++)
		distance[i]=INT32_MAX;

	distance[source]=0;
	pq.push({0,source});

	while(!pq.empty())
	{

		int newSrc = pq.top().second;
		pq.pop();

		if(processed[newSrc])
			continue;
		else
			processed[newSrc]=true;

		for(auto adjVer: adj[newSrc])
		{

			int dest,wt,newWt;
			tie(dest,wt) = adjVer;

			newWt = distance[newSrc]+wt;

			if(distance[dest] > newWt)
			{
				distance[dest] = newWt;
				pq.push({-newWt,dest});
			}

		}

	}

	for(int i=0;i<noOfVertices;i++)
		cout<<"Node "<<i<<" ---> 0 = "<<distance[i]<<endl;

}

int main()
{

	int NO_OF_VERTICES = 5;
	vector<pair<int,int>> adj[NO_OF_VERTICES];

	adj[0].push_back({1,5});
	adj[0].push_back({4,1});
	adj[0].push_back({3,9});
	adj[1].push_back({2,2});
	adj[3].push_back({2,6});
	adj[4].push_back({3,2});

	dijkstra(0,adj,NO_OF_VERTICES);

	return 0;

}
