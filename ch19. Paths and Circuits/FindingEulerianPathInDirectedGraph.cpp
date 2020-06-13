/*============================================================================
 * Problem : Implement an algorithm to find Eulerian path in a directed Graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void findEulerianPath(int startingNode, vector<int> adj[], int noOfVertices)
{

	stack<int> curNode, circuit;

	curNode.push(startingNode);
	while(!curNode.empty())
	{

		while(adj[startingNode].size())
		{
			int next = adj[startingNode].back();
			curNode.push(next);
			adj[startingNode].pop_back();
			startingNode = next;
		}

		circuit.push(startingNode);
		curNode.pop();

		if(!curNode.empty())
			startingNode = curNode.top();

	}

	while(!circuit.empty())
	{
		cout<<circuit.top();
		if(circuit.size()>1)
			cout<<"->";
		circuit.pop();
	}


}

void checkForEulerianPath(vector<int> adj[], int noOfVertices)
{

	int indegree[noOfVertices] = {0};
	int outdegree[noOfVertices] = {0};
	int mismatch[noOfVertices] = {0};

	for(int i=0; i<noOfVertices; i++)
	{
		for(auto x:adj[i])
		{
			indegree[x]++;
			outdegree[i]++;
		}
	}

	int count = 0;
	int startNode  = 0;
	bool notPossible = false;

	for(int i=0; i<noOfVertices; i++)
	{
		mismatch[i] = outdegree[i] - indegree[i];
		if(mismatch[i]==1)
		{
			count++;
			startNode = i;
		}
		else if(mismatch[i] == -1)
			count++;

		if(mismatch[i] > 1 || mismatch[i] < -1)
		{
			notPossible = true;
		}

	}

	if((count !=0 && count!=2 )|| notPossible)
		cout<<"Finding Eulerian Path is not possible for this graph"<<endl;
	else
		findEulerianPath(startNode, adj, noOfVertices);

}

int main()
{

	int NO_OF_VERTICES = 4;
	vector<int> adj[NO_OF_VERTICES+1];

	adj[0].push_back(1);
	adj[1].push_back(3);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[3].push_back(4);
	adj[4].push_back(1);

	//checkForEulerianPath(adj, NO_OF_VERTICES+1);

	vector<int> adj1[3];

	adj1[0].push_back(1);
	adj1[1].push_back(2);
	adj1[2].push_back(0);

	checkForEulerianPath(adj1, 3);

	vector<int> adj2[7];

	adj2[0].push_back(1);
	adj2[0].push_back(6);
	adj2[1].push_back(2);
	adj2[2].push_back(0);
	adj2[2].push_back(3);
	adj2[3].push_back(4);
	adj2[4].push_back(2);
	adj2[4].push_back(5);
	adj2[5].push_back(0);
	adj2[6].push_back(4);

	//checkForEulerianPath(adj2, 7);

	return 0;

}
