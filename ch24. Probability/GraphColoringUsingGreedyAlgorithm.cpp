/*============================================================================
 * Problem : Given a graph, assign color to every vertex such that no two adjacent vertex has same color.
 * 			 Use Welsh–Powell Algorithm.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

void assignEdge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

void findColoring(vector<int> adj[], int processing_order[], int n)
{

	bool avialable[n];
	for(int i=0; i<n; i++)
		avialable[i] = true;

	int result[n];
	for(int i=0; i<n; i++)
		result[i] = -1;

	for(int i=0; i<n; i++)
	{

		int node = processing_order[i];

		/*
		 * if adjacent node has been given color, then make that color unavailable
		 */
		for(auto x: adj[node])
			if(result[x] != -1)
				avialable[result[x]] = false;

		for(int i=0; i<n; i++)
		{
			if(avialable[i])
			{
				result[node] = i;
				break;
			}
		}

		/*
		 * make all the colors available again
		 */
		for(auto x: adj[node])
			if(result[x] != -1)
				avialable[result[x]] = true;

	}

	for(int i=0; i<n; i++)
		cout<<"Node "<<i<<" has been assigned "<<result[i]<<" color"<<endl;


}

int main()
{

	int n = 5;
	vector<int> adj[n];
	assignEdge(adj, 0, 1);
	assignEdge(adj, 0, 2);
	assignEdge(adj, 1, 2);
	assignEdge(adj, 1, 4);
	assignEdge(adj, 2, 4);
	assignEdge(adj, 4, 3);

	// processing_order array contains nodes in decreasing order of degree.
	multimap<int, int> degree;
	int processing_order[n];

	for(int i=0; i<n; i++)
		degree.insert({int(adj[i].size())*-1, i});

	int idx = 0;
	for(auto x:degree)
		processing_order[idx++] = x.second;

	findColoring(adj, processing_order, n);

	return 0;

}
