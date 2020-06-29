/*============================================================================
 * Problem : Implement Edmand-karp Algorithm for finding maximum flow in a graph.
 * Link    : https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/practice-problems/algorithm/find-the-flow/description/
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

bool bfs(unordered_map<char,unordered_map<char,int>> &adj, char source, char sink, set<char> nodes, int &flow)
{

	unordered_map<char,int> parent;
	for(auto x:nodes)
	{
		parent[x]=-1;
	}

	queue<char> q;
	q.push(source);
	parent[source] = 0;
	while(!q.empty())
	{
		char curr = q.front();
		q.pop();
		for(auto x:adj[curr])
		{
			if(parent[x.first] == -1 && x.second >0)
			{
				q.push(x.first);
				parent[x.first] = curr;
			}
		}
	}

	bool res = false;
	if(parent[sink]!=-1)
	{
		res=true;
		int min_wt = INT_MAX;
		for(char v = sink; v!=source ; v = parent[v])
		{
			char u = parent[v];
			if(adj[u][v] < min_wt)
				min_wt = adj[u][v];
		}

		flow += min_wt;

		for(char v = sink; v!=source ; v = parent[v])
		{
			char u = parent[v];
			adj[u][v] -= min_wt;
			if(adj[u][v]==0)
				adj[u].erase(v);
			adj[v][u] += min_wt;
		}

	}

	return res;

}

int max_flow(unordered_map<char,unordered_map<char,int>> adj, char source, char sink, set<char> nodes)
{
	int flow = 0;
	while(bfs(adj, source, sink, nodes, flow));
	return flow;
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

	cout<<"The maximum required flow is  = "<<max_flow(adj, 'S', 'T', nodes);

	return 0;

}
