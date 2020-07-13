/*============================================================================
 * Problem : Implement code to generate edge list representation of tree using prufer's code in linear time.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

void generateTree(vector<int> code)
{

	int size = code.size()+3; // since, for our example nodes are indexed from 1 so, size will get increased by 1.
	int degree[size];

	for(int i=1; i<size; i++)
		degree[i] = 1;

	for(auto i: code)
		degree[i]++;

	int ptr = 1;
	while(degree[ptr] != 1)
		ptr++;

	vector<pair<int, int>> edges;

	for(auto x: code)
	{
		edges.emplace_back(ptr, x);
		if(--degree[x]==1 && x<ptr)
			ptr = x;
		else
		{
			ptr++;
			while(degree[ptr] != 1)
				ptr++;
		}
	}

	edges.emplace_back(ptr, size-1);

	for(auto x:edges)
		cout<<x.first<<" "<<x.second<<endl;

}

int main()
{

	vector<int> code({1, 7, 6, 6, 1});
	generateTree(code);
	return 0;

}
