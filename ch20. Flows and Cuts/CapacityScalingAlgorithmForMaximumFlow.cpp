/*============================================================================
 * Problem : Implement Capacity Scaling Algorithm for finding maximum flow in a graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
#define V 7
using namespace std;

int dfs(int adj[][V], bool visited[], int source, int sink, int minimum, vector<int> &path, int delta)
{

	visited[source]=true;
	if(source==sink)
		return minimum;

	for(int i=1;i<V;i++)
	{
		if(adj[source][i]>0 && !visited[i])
		{
			int flow = adj[source][i] - adj[i][source];
			if(flow < delta)
				continue;
			if(int val = dfs(adj,visited,i,sink,min(minimum,flow), path, delta))
			{
				path.push_back(i);
				return val;
			}
		}
	}

	return 0;

}

void initialize(bool visited[], vector<int> &path, int *min)
{
	*min = INT_MAX;
	path.clear();
	for(int i=0;i<V;i++)
		visited[i] = false;
}


void showGraph(int adj[][V])
{

	cout<<"\n********************************\n";
	for(int i=1;i<V;i++)
	{
		for(int j=1;j<V;j++)
		{
			cout<<setw(2)<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n********************************\n";

}

int maxFlow(int adj[][V], int nodes, int source, int sink)
{

	int max=0;
	for(int i=1;i<nodes;i++)
		for(int j=1;j<nodes;j++)
			if(max<adj[i][j])
				max=adj[i][j];

	int delta = pow(2,int(log2(max)));
	bool visited[nodes]={0};
	vector<int> path;
	int minimum = INT_MAX;
	int max_flow = 0;

	cout<<"Input graph :::\n";
	showGraph(adj);
	cout<<"Trying with initial delta value = "<<delta<<endl;

	while(delta > 0)
	{
		initialize(visited, path, &minimum);
		while(int val = dfs(adj,visited,source,sink,minimum,path,delta))
		{
			max_flow += val;
			path.push_back(source);
			for(int i=path.size()-2; i>=0;i--)
				adj[path[i]][path[i+1]] += val;

			cout<<"\n********************************\n";
			cout<<"path found with minimum value = "<<val<<", path = ";
			for(int x = path.size()-1; x>=0; x--)
				cout<<path[x]<<" ";

			showGraph(adj);
			initialize(visited, path, &minimum);
			cout<<"trying again with delta "<<delta<<endl;

		}

		showGraph(adj);
		cout<<"\nchanging delta to "<<delta/2<<endl;

		delta /= 2;
	}

	return max_flow;

}

int main()
{

	int no_of_nodes =  6;
	/*int adj[no_of_nodes+1][V]={{0,0,0,0,0,0,0},
							   {0,0,10,0,10,0,0},
							   {0,0,0,25,0,0,0},
							   {0,0,0,0,0,0,10},
							   {0,0,0,0,0,15,0},
							   {0,0,6,0,0,0,10},
							   {0,0,0,0,0,0,0}};*/

	int adj[no_of_nodes+1][V]={{0,0,0,0,0,0,0},
							   {0,0,5,0,4,0,0},
							   {0,0,0,6,0,0,0},
							   {0,0,0,0,0,8,5},
							   {0,0,3,0,0,1,0},
							   {0,0,0,0,0,0,2},
							   {0,0,0,0,0,0,0}};

	int source=0, sink=0;
	int in_count[V] = {0};
	int out_count[V] = {0};

	for(int i=1;i<V; i++)
	{
		for(int j=1;j<V;j++)
		{
			if(adj[i][j])
			{
				out_count[i]++;
				in_count[j]++;
			}
		}
	}

	for(int i=1; i<V; i++)
	{
		if(in_count[i]==0)
			source = i;
		if(out_count[i]==0)
			sink = i;
	}

	cout<<"Source for given graph = "<<source<<endl;
	cout<<"Sink for given graph = "<<sink<<endl;

	int max_flow = maxFlow(adj,V,source,sink);
	cout<<"\n\nMaximum flow for the given graph = "<<max_flow<<endl;

	return 0;

}
