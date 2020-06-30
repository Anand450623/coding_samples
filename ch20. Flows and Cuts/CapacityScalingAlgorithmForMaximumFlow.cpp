/*============================================================================
 * Problem : Implement Capacity Scaling Algorithm for finding maximum flow in a graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int dfs(unordered_map<char, unordered_map<char, int>> adj, unordered_map<char, int> &parent, char source,char source_parent, int delta, char sink, int minimum)
{

	if(source == sink)
	{
		parent[source] = source_parent;
		return minimum;
	}

	parent[source] = source_parent;
	for(auto x:adj[source])
	{
		if(parent[x.first] == -1 && x.second >= delta)
			if(int minm = dfs(adj, parent, x.first, source, delta, sink, min(minimum, x.second)))
				return minm;
	}

	return 0;

}

int find_max_flow(unordered_map<char, unordered_map<char, int>> adj, set<char> nodes)
{

	int max = INT_MIN;
	char source = 'S';
	char sink = 'T';

	for(auto x:nodes)
	{
		for(auto i:adj[x])
		{
			if(max<i.second)
				max = i.second;
		}
	}

	int delta = 1<<int(floor(log2(max)));
	int max_flow = 0;

	while(delta>0)
	{

		unordered_map<char, int> parent;
		int minimum = INT_MAX;
		for(auto x:nodes)
			parent[x] = -1;

		int min_value = dfs(adj, parent, source, 0, delta, sink, minimum);
		max_flow += min_value;

		if(parent[sink] == -1)
		{
			delta /= 2;
		}
		else
		{
			for(char v = sink; v!=source; v = parent[v])
			{
				char u = parent[v];
				adj[u][v] -= min_value;
				if(adj[u][v]==0)
					adj[u].erase(v);
				adj[v][u] += min_value;
				cout<<v<<" ";
			}
			cout<<source<<" -> "<<min_value<<endl;

		}

	}

	cout<<"The maximum flow is given by = ";
	return max_flow;

}


int main()
{

	unordered_map<char,unordered_map<char,int>> adj;
	adj['S']['A']=8;
	adj['S']['B']=10;
	adj['A']['C']=8;
	adj['A']['B']=4;
	adj['A']['D']=5;
	adj['B']['C']=5;
	adj['B']['D']=2;
	adj['C']['D']=3;
	adj['C']['T']=4;
	adj['D']['T']=12;

	set<char> nodes;
	nodes.insert('S');
	nodes.insert('A');
	nodes.insert('B');
	nodes.insert('C');
	nodes.insert('D');
	nodes.insert('T');

	cout<<"various possible paths with associated weights are :::\n"<<find_max_flow(adj, nodes);

	return 0;

}
