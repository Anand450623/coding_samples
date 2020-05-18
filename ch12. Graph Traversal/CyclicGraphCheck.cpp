/*============================================================================
 * Problem : Implement Connectivity Check in a graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int NO_OF_VERTICES=6;

//function to check presence of cycle in graph
bool checkCyclic(int vertice, vector<int> adj[], bool visited[], bool recStack[])
{

	//if that node is not already visited then must check for that and child nodes
	if(!visited[vertice])
	{
		//mark this node as visited and include it in recursion tree.
		visited[vertice]=true;
		recStack[vertice]=true;

		//check cycle for sub-graphs
		for(auto i:adj[vertice])
		{
			//if node is not visited but on visiting contains cycle
			if(!visited[i] && checkCyclic(i,adj,visited,recStack)) //maybe !visited[i] is not required here
				return true;
			//if node contains self loop or parent still in recursion stack which indicates presence of cycle
			else if(recStack[i])
				return true;
		}

	}

	//if node is already visited then it and child must have been checked for cycle.
	recStack[vertice] = false;
	return false;

}

int main()
{

	vector<int> adj[NO_OF_VERTICES];
	bool visited[NO_OF_VERTICES]={false};
	bool recStack[NO_OF_VERTICES]={false};

	adj[0].push_back(1);
	adj[0].push_back(3);
	adj[1].push_back(2);
	adj[1].push_back(4);
	adj[2].push_back(5);
	adj[4].push_back(5);
	//adj[4].push_back(4); //including this line will result in formation of cycle in graph

	if(checkCyclic(0,adj,visited,recStack))
		cout<<"Cycle exists in graph...\n";
	else
		cout<<"Cycle doesn't exists in graph...\n";

	return 0;

}
