/*============================================================================
 * Problem : Find the lowest common ancestor for given nodes.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int startNode, vector<int> adj[], vector<int> &traversal, bool visited[])
{

	if(visited[startNode])
		return;
	else
	{
		traversal.push_back(startNode);
		visited[startNode]=true;
		for(auto i: adj[startNode])
		{
			if(!visited[i])
			{
				dfs(i,adj,traversal,visited);
				traversal.push_back(startNode);
			}
		}
	}

}

int rangeMinimumInSegmentTree(int segmentTree[], int qs, int qe, int as, int ae, int ci)
{

	if(qs<=as && qe>=ae)
		return segmentTree[ci];

	if(qs>ae || qe<as)
		return INT_MAX;

	else
	{
		int mid = ae - (ae-as)/2;
		return min(rangeMinimumInSegmentTree(segmentTree,qs,qe,as,mid-1,ci*2),rangeMinimumInSegmentTree(segmentTree,qs,qe,mid,ae,ci*2+1));
	}

}

int main()
{

	int NO_OF_VERTICES = 8;
	bool visited[NO_OF_VERTICES+1]={false};
	vector<int> adj[NO_OF_VERTICES+1];
	vector<int> traversal;

	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[1].push_back(3);
	adj[3].push_back(1);
	adj[1].push_back(4);
	adj[4].push_back(1);
	adj[2].push_back(5);
	adj[5].push_back(2);
	adj[2].push_back(6);
	adj[6].push_back(2);
	adj[4].push_back(7);
	adj[7].push_back(4);
	adj[6].push_back(8);
	adj[8].push_back(6);

	int startNode = 1;
	dfs(startNode, adj, traversal, visited);

	int size = traversal.size();
	if((size&-size)!=size)
	{
		size = ceil(log2(size));
		size = (1<<size);
	}

	int segmentTree[2*size];

	for(int i=0;i<2*size;i++)
		segmentTree[i] = INT_MAX;

	size_t index = 0;
	for(int i=size;index<traversal.size();i++)
		segmentTree[i] = traversal[index++];

	for(int i=size-1; i>0; i--)
		segmentTree[i] = min(segmentTree[2*i],segmentTree[2*i+1]);

	int node1 = 5;
	int node2 = 6;
	bool isNode1Found = false;
	bool isNode2Found = false;
	int indexForNode1 = -1;
	int indexForNode2 = -1;

	for(size_t i=0;i<traversal.size();i++)
	{
		if(!isNode1Found && traversal[i]==node1)
		{
			indexForNode1 = i;
			isNode1Found = true;
			continue;
		}

		if(!isNode2Found && traversal[i]==node2)
		{
			indexForNode2 = i;
			isNode2Found = true;
			continue;
		}

		if(isNode1Found && isNode2Found)
			break;

	}

	//cout<<indexForNode1<<" "<<indexForNode2<<endl;
	cout<<rangeMinimumInSegmentTree(segmentTree,indexForNode1,indexForNode2+1,1,size,1);
	return 0;

}
