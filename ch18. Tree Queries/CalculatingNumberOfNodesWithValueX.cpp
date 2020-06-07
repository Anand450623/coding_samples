/*============================================================================
 * Problem : Calculate the number of nodes with value X in subtree of given node s.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void merge(map<int,int> &m1, map<int,int> m2)
{

	if(m1.size()<m2.size())
		m1.swap(m2);

	for(auto i:m2)
	{
		auto it = m1.find(i.first);
		if(it!=m1.end())
			it->second += i.second;
		else
			m1.insert(i);
	}

}

void dfs(int startNode, vector<int> adj[], int data[], map<int,int> dataCount[], bool visited[])
{

	if(visited[startNode])
		return;
	else
	{
		dataCount[startNode].insert({data[startNode], 1});
		visited[startNode] = true;
		for(int i:adj[startNode])
		{
			dfs(i,adj,data,dataCount,visited);
			merge(dataCount[startNode],dataCount[i]);
		}
	}

}

int main()
{

	int NO_OF_VERTICES = 9;
	int data[NO_OF_VERTICES+1] = {0};
	bool visited[NO_OF_VERTICES+1] = {false};
	vector<int> adj[NO_OF_VERTICES+1];

	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(4);
	adj[1].push_back(5);
	adj[2].push_back(6);
	adj[4].push_back(7);
	adj[4].push_back(8);
	adj[4].push_back(9);

	data[1] = 2;
	data[2] = 3;
	data[3] = 5;
	data[4] = 3;
	data[5] = 1;
	data[6] = 4;
	data[7] = 4;
	data[8] = 3;
	data[9] = 1;

	map<int,int> dataCount[NO_OF_VERTICES+1];

	int startNode = 1;
	dfs(startNode, adj, data, dataCount, visited);

	int targetNode=4;
	int targetValue=3;

	auto it = dataCount[targetNode].find(targetValue);
	if(it==dataCount[targetNode].end())
		cout<<"Target value not found\n";
	else
		cout<<"Number of times target value appeared = "<<it->second<<endl;

	return 0;

}

