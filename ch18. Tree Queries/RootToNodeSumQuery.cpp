/*============================================================================
 * Problem : Find the Sum to node from root in a given tree and update incremental data for a given node.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

typedef struct node
{

	int nodeId;
	int subTreeSize;
	int pathSum;

	node()
	{
		this->nodeId=0;
		this->subTreeSize=0;
		this->pathSum=0;
	}

	node(int id,int size,int sum)
	{
		this->nodeId=id;
		this->subTreeSize=size;
		this->pathSum=sum;
	}

}node;

void dfs(int node, vector<int> adj[], vector<int> &traversal, int subTreeCount[], vector<int> data, int pathSum[])
{
	pathSum[node] += data[node];
	subTreeCount[node]=1;
	traversal.push_back(node);
	for(auto i:adj[node])
	{
		pathSum[i] += pathSum[node];
		dfs(i,adj,traversal,subTreeCount,data,pathSum);
		subTreeCount[node] += subTreeCount[i];
	}
}

int main()
{

	int NO_OF_VERTICES = 9;
	int pathSum[NO_OF_VERTICES+1]={0};
	int subTreeCount[NO_OF_VERTICES+1]={0};
	vector<int> adj[NO_OF_VERTICES+1];
	vector<int> data;
	vector<int> traversal;

	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(4);
	adj[1].push_back(5);
	adj[2].push_back(6);
	adj[4].push_back(7);
	adj[4].push_back(8);
	adj[4].push_back(9);

	data.push_back(-1); //dummy mocked up data to keep things in sync and start every indexing from 1.
	data.push_back(4);
	data.push_back(5);
	data.push_back(3);
	data.push_back(5);
	data.push_back(2);
	data.push_back(3);
	data.push_back(5);
	data.push_back(3);
	data.push_back(1);

	dfs(1,adj,traversal,subTreeCount,data,pathSum);

	vector<node> tree;
	for(auto i:traversal)
		tree.push_back({i,subTreeCount[i],pathSum[i]});

	int SearchNode = 4;
	for(auto i:tree)
		if(i.nodeId==SearchNode)
			cout<<i.pathSum<<endl;

	int Increment = 1;
	int children = 0;
	int index = -1;
	for(size_t i=0;i<tree.size();i++)
	{
		if(tree[i].nodeId==SearchNode)
		{
			children = tree[i].subTreeSize;
			tree[i].pathSum+=Increment;
			index=i;
		}
	}

	for(int i=index+1;i<index+children;i++)
		tree[i].pathSum += Increment;

	cout<<"The updated state is as below...\n";
	for(auto i:tree)
		cout<<i.nodeId<<" "<<i.subTreeSize<<" "<<i.pathSum<<endl;

	return 0;

}
