/*============================================================================
 * Problem : Implement Shortest Path Faster Algorithm for single source shortest path.
 * NOTE    : This Algorithm will go into infinte loop if negative cycle is present.
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void spfa(vector<tuple<int,int,int>> edgeList, int distance[], int noOfVertices, int noOfEdges)
{

	int src = 0;
	int NO_OF_VERTICES = noOfVertices;

	bool inQueue[NO_OF_VERTICES]={false};

	queue <int> q;

	for(int i=0;i<NO_OF_VERTICES;i++)
		distance[i] = INT32_MAX;

	//Here, we are assuming 0th node to be the source vertex.
	distance[src]=0;

	q.push(src);
	inQueue[src]=true;

	while(!q.empty())
	{

		int cs = q.front();
		q.pop();
		inQueue[cs]=false;

		for(auto edge:edgeList)
		{
			int src,dest,wt;
			tie(src,dest,wt) = edge;

			//relax only if src was present in queue
			if(src==cs && distance[dest]>distance[src]+wt)
			{
				distance[dest] = distance[src]+wt;
				if(!inQueue[dest])
				{
					q.push(dest);
					inQueue[dest] = true;
				}

			}

		}

	}


	for(int i=0;i<NO_OF_VERTICES;i++)
		cout<<"Node "<<i<<" ---> 0 = "<<distance[i]<<endl;

}

int main()
{

	vector<tuple<int,int,int>> edgeList;

	edgeList.push_back({0,1,2});
	edgeList.push_back({0,2,3});
	edgeList.push_back({0,3,7});
	edgeList.push_back({1,3,3});
	edgeList.push_back({1,4,5});
	edgeList.push_back({2,3,-2});
	edgeList.push_back({3,4,2});

	int distance[5]; //No_of_vertices=5

	spfa(edgeList,distance,5,7); //No_of_vertices=5, No_of_edges=7

	cout<<"*********************************************************************************"<<endl;

	vector<tuple<int,int,int>> negativeCyclicEdge;
	negativeCyclicEdge.push_back({0,1,3});
	negativeCyclicEdge.push_back({0,2,5});
	negativeCyclicEdge.push_back({1,2,2});
	negativeCyclicEdge.push_back({2,3,-7});
	negativeCyclicEdge.push_back({3,1,1});

	int distanceMat[4]; //No_of_vertices=4

	//spfa(negativeCyclicEdge,distanceMat,4,5); //No_of_vertices=4, No_of_edges=5

	return 0;

}
