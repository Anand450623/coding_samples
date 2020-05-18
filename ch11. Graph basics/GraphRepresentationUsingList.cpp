/*============================================================================
 * Problem : Represent a graph using List representation.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

	const int NO_OF_VERTICES = 4;

	// adjacency list representation

	vector<int> adj[NO_OF_VERTICES];
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(3);
	adj[3].push_back(0);


	// If the edges have weights associated with them, then the code can be modified as :

	vector<pair<int,int>> adjGraph[NO_OF_VERTICES];
	adjGraph[0].push_back({1,5});
	adjGraph[1].push_back({2,7});
	adjGraph[1].push_back({3,6});
	adjGraph[2].push_back({3,5});
	adjGraph[3].push_back({0,2});

	// Edge List Representation

	vector<pair<int,int>> edges;
	edges.push_back({0,1});
	edges.push_back({1,2});
	edges.push_back({1,3});
	edges.push_back({2,3});
	edges.push_back({3,0});

	// If the graph has weight

	vector<tuple<int,int,int>> edgeList;
	edgeList.push_back({0,1,5});
	edgeList.push_back({1,2,7});
	edgeList.push_back({1,3,6});
	edgeList.push_back({2,3,5});
	edgeList.push_back({3,0,2});

	return 0;

}
