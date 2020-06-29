/*============================================================================
 * Problem : Find Maximum Count of internally disjoint paths in a directed graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

bool bfs(unordered_map<char,unordered_map<char,int>> &adj, char source, char sink, set<char> nodes, set<char> originalNodes, int &flow)
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

			if(originalNodes.find(v) != originalNodes.end())
				cout<<v<<"->";

		}

		cout<<source<<endl;

	}

	return res;

}

void transform(unordered_map<char,unordered_map<char,int>> &adj, set<char> &nodes, char source, char sink)
{

	set<char> to_be_transformed;
	int count = adj.size()+1;

	for(auto keys:adj)
		if(keys.first != sink)
			to_be_transformed.insert(keys.first);

	for(auto key:to_be_transformed)
	{

		vector<char> v;
		for(auto x: adj[key])
		{
			if(x.first != sink)
				v.push_back(x.first+count);
		}

		for(auto i:v)
		{
			adj[key][i] = 1;
			adj[key].erase(i-count);
			adj[i][i-count] = 1;
			nodes.insert(i);
		}

	}

}

int max_flow(unordered_map<char,unordered_map<char,int>> adj, char source, char sink, set<char> nodes, set<char> originalNodes)
{
	int flow = 0;
	while(bfs(adj, source, sink, nodes, originalNodes, flow));
	cout<<"Total number of paths = ";
	return flow;
}

int main()
{

	unordered_map<char,unordered_map<char,int>> adj;
	adj['1']['2']=1;
	adj['1']['4']=1;
	adj['2']['4']=1;
	adj['3']['2']=1;
	adj['3']['5']=1;
	adj['3']['6']=1;
	adj['4']['3']=1;
	adj['4']['5']=1;
	adj['5']['6']=1;

	set<char> nodes;
	nodes.insert('1');
	nodes.insert('2');
	nodes.insert('3');
	nodes.insert('4');
	nodes.insert('5');
	nodes.insert('6');

	set<char> originalNodes(nodes);

	transform(adj, nodes, '1', '6');

	cout<<"The internally disjoint paths are :::\n"<<max_flow(adj, '1', '6', nodes, originalNodes);

	return 0;

}
