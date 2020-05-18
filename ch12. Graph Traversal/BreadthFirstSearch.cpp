/*============================================================================
 * Problem : Implement Breadth First Search Algorithm.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int NO_OF_VERTICES=6;

void bfs(int vertice,vector<int> adj[],bool visited[],queue<int> q,int distance[])
{

	cout<<vertice<<" ";
	visited[vertice]=true;
	q.push(vertice);
	distance[vertice] = 0;
	while(!q.empty())
	{
		int s = q.front();
		q.pop();

		for(auto i:adj[s])
		{
			if(visited[i])
				continue;
			else
			{
				cout<<i<<" ";
				visited[i]=true;
				q.push(i);
				distance[i] = distance[s]+1;
			}
		}
	}

}

int main()
{

	vector<int> adj[NO_OF_VERTICES];
	bool visited[NO_OF_VERTICES]={false};
	int distance[NO_OF_VERTICES]={0};
	queue<int> q;

	adj[0].push_back(1);
	adj[0].push_back(3);
	adj[1].push_back(2);
	adj[1].push_back(4);
	adj[2].push_back(5);
	adj[4].push_back(5);

	cout<<"The bfs result for the given graph is as follows --->\n";
	//0,1,3,2,4,5

	bfs(0,adj,visited,q,distance);

	//Here, distance is defined as the number of edges to be traversed before reaching to destination node starting from initial node.
	cout<<"\nThe distance of every other node from the root node is as follows ---->\n";
	for(int i=0;i<NO_OF_VERTICES;i++)
		cout<<i<<" --- 0 = "<<distance[i]<<endl;

	return 0;

}
