/*============================================================================
 * Problem : Implement Bellman Ford Algorithm for single source shortest path.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void bellmanFord(vector<tuple<int,int,int>> edgeList, int distance[], int noOfVertices, int noOfEdges)
{

	bool isNegativeCyclePresent=false;
	int NO_OF_VERTICES = noOfVertices;
	//int NO_OF_EDGES = noOfEdges;

	for(int i=0;i<NO_OF_VERTICES;i++)
		distance[i] = INT32_MAX;

	//Here, we are assuming 0th node to be the source vertex.
	distance[0]=0;

	for(int i=0;i<NO_OF_VERTICES;i++)
	{
		for(auto edge:edgeList)
		{
			int src,dest,wt;
			tie(src,dest,wt) = edge;
			if(distance[dest] > distance[src]+wt)
				distance[dest] = distance[src]+wt;
		}
	}

	for(auto edge:edgeList)
	{
		int src,dest,wt;
		tie(src,dest,wt) = edge;
		if(distance[dest] > distance[src]+wt)
		{
			isNegativeCyclePresent=true;
			break;
		}
	}

	if(!isNegativeCyclePresent)
	{
		for(int i=0;i<NO_OF_VERTICES;i++)
			cout<<"Node "<<i<<" ---> 0 = "<<distance[i]<<endl;
	}
	else
	{
		cout<<"Negative cycle is present in graph...";
	}

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

	bellmanFord(edgeList,distance,5,7); //No_of_vertices=5, No_of_edges=7

	cout<<"*********************************************************************************"<<endl;

	vector<tuple<int,int,int>> negativeCyclicEdge;
	negativeCyclicEdge.push_back({0,1,3});
	negativeCyclicEdge.push_back({0,2,5});
	negativeCyclicEdge.push_back({1,2,2});
	negativeCyclicEdge.push_back({2,3,-7});
	negativeCyclicEdge.push_back({3,1,1});

	int distanceMat[4]; //No_of_vertices=4

	bellmanFord(negativeCyclicEdge,distanceMat,4,5); //No_of_vertices=4, No_of_edges=5

	return 0;

}
