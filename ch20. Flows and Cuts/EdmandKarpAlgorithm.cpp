/*============================================================================
 * Problem : Implement Edmand-karp Algorithm for finding maximum flow in a graph.
 * NOTE    : Reverse flow is not implemented i.e., only the forward flow is enough to get the solution.
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<pair<int,int>> adj[], int nodes, int source, int sink, int* flow)
{

	bool visited[nodes]={false};
	int parent[nodes]={0};

	queue<int> q;
	q.push(source);

	while(!q.empty())
	{

		int curr = q.front();
		q.pop();

		for(auto next:adj[curr])
		{
			int x,wt;
			tie(x,wt) = next;
			if(visited[x] || wt==0)
				continue;
			else
			{
				visited[x]=true;
				parent[x] = curr;
				q.push(x);
			}
		}

	}

	bool res = false;
	vector<int> path;
	vector<int> capacity;
	if(visited[sink])
	{
		res = true;
		while(parent[sink]!=0)
		{
			for(auto x:adj[parent[sink]])
			{
				int a,b;
				tie(a,b) = x;
				if(a==sink)
				{
					capacity.push_back(b);
					path.push_back(a);
					break;
				}
			}
			sink = parent[sink];
		}

		int min_wt = *min_element(capacity.begin(),capacity.end());
		*flow += min_wt;

		while(!path.empty())
		{
			int item = path.back();
			path.pop_back();
			for(vector<pair<int,int>>::iterator it = adj[source].begin(); it!=adj[source].end();++it)
			{
				if(it->first == item)
				{
					it->second -= min_wt;
					break;
				}
			}
			source = item;
		}

	}

	return res;

}

int findMaxFlow(vector<pair<int,int>> adj[], int nodes,int source, int sink)
{
	int flow = 0;
	while(bfs(adj, nodes,source, sink, &flow));
	return flow;
}

int main()
{

	int no_of_Vertices = 6;
	vector<pair<int,int>> adj[no_of_Vertices+1];
	int count[no_of_Vertices+1]={0};

/*	adj[1].push_back({2,5});
	adj[1].push_back({4,4});
	adj[2].push_back({3,6});
	adj[3].push_back({6,5});
	adj[3].push_back({5,8});
	adj[4].push_back({2,3});
	adj[4].push_back({5,1});
	adj[5].push_back({6,2});*/


	adj[1].push_back({2,7});
	adj[1].push_back({4,4});
	adj[2].push_back({3,5});
	adj[2].push_back({5,3});
	adj[3].push_back({6,8});
	adj[4].push_back({2,3});
	adj[4].push_back({5,2});
	adj[5].push_back({3,3});
	adj[5].push_back({6,5});

	int source =-1;
	int sink = -1;

	for(int i=1;i<=no_of_Vertices;i++)
	{
		int outCount=0;
		for(auto x:adj[i])
		{
			count[x.first]++;
			outCount++;
		}
		if(outCount==0)
			sink = i;
	}

	for(int i=1;i<=no_of_Vertices;i++)
	{
		if(count[i]==0)
		{
			source=i;
			break;
		}
	}

	cout<<"Maximum possible flow for the given graph is = "<<findMaxFlow(adj,no_of_Vertices+1,source,sink);

	return 0;

}
