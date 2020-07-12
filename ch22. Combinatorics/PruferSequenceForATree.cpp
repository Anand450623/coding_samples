/*============================================================================
 * Problem : Implement code to obtain prufer's sequence for a given tree with n nodes.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

void pruferSequence(vector<int> adj[], int size)
{

	set<int> leafs;
	int degree[size] = {0};
	for(int i=1; i<size; i++)
	{
		degree[i] = adj[i].size();
		if(degree[i] == 1)
			leafs.insert(i);
	}

	vector<bool> killed(size, false);
	vector<int> code;

	for(int i=1; i<(size-2); i++)
	{

		int node = *leafs.begin();
		leafs.erase(leafs.begin());
		killed[node] = true;

		int data;
		for(auto x: adj[node])
			if(!killed[x])
				data = x;

		code.push_back(data);
		if(--degree[data] == 1)
			leafs.insert(data);

	}

	cout<<"The required Prufer Sequence for the given tree is :::\n";
	for(auto x: code)
		cout<<x<<" ";
	cout<<endl;

}

int main()
{

	int n =  8;
	vector<int> adj[n];

	adj[1].push_back(2);
	adj[1].push_back(6);
	adj[1].push_back(7);

	adj[2].push_back(1);

	adj[3].push_back(7);

	adj[4].push_back(6);

	adj[5].push_back(6);

	adj[6].push_back(1);
	adj[6].push_back(4);
	adj[6].push_back(5);

	adj[7].push_back(1);
	adj[7].push_back(3);

	pruferSequence(adj, n);

	return 0;

}
