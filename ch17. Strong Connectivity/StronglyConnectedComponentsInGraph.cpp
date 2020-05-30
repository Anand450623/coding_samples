/*============================================================================
 * Problem : Implement kosaraju's algorithm for strongly connected components.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int startIndex, vector<int> adj[], bool visited[], stack<int> &s)
{
	if(visited[startIndex])
		return;
	else
	{
		visited[startIndex]=true;
		for(auto k:adj[startIndex])
			dfs(k,adj,visited,s);
		s.push(startIndex);
	}
}

void  revDfs(int startIndex, vector<int> revAdj[], bool visited[])
{
	if(visited[startIndex])
		return;
	else
	{
		cout<<startIndex<<" ";
		visited[startIndex]=true;
		for(auto i:revAdj[startIndex])
			revDfs(i,revAdj,visited);
	}
}

int main()
{

	int NO_OF_VERTICES=8;
	bool visited[NO_OF_VERTICES+1]={false};
	vector<int> adj[NO_OF_VERTICES+1];
	vector<int> revAdj[NO_OF_VERTICES+1];

	adj[1].push_back(6);
	adj[2].push_back(1);
	adj[6].push_back(2);
	adj[2].push_back(3);
	adj[7].push_back(3);
	adj[6].push_back(7);
	adj[5].push_back(6);
	adj[3].push_back(4);
	adj[3].push_back(8);
	adj[8].push_back(7);

	for(int i=1;i<=NO_OF_VERTICES;i++)
		for(auto k:adj[i])
			revAdj[k].push_back(i);

	stack<int> s;
	for(int startIndex = 1; startIndex<=NO_OF_VERTICES; startIndex++)
		dfs(startIndex,adj,visited,s);

	for(int i=1;i<=NO_OF_VERTICES;i++)
		visited[i]=false;

	while(!s.empty())
	{
		int startIndex = s.top();
		s.pop();
		if(!visited[startIndex])
		{
			revDfs(startIndex,revAdj,visited);
			cout<<endl;
		}

	}

	return 0;

}
