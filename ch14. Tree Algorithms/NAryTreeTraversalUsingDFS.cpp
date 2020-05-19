/*============================================================================
 * Problem : Implement n-ary Tree traversal and sub-node count using dfs algorithm.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int NO_OF_VERTICES = 9;

//isVisited Array is not required as we know tree doesn't contains cycle.
void dfs(int vertice,int src,vector<int> tree[],int count[])
{

	cout<<vertice<<" ";
	count[vertice]=1;

	for(auto i:tree[vertice])
	{
		//this condition will come into picture if and only if child of a node is somehow related to parent, else this can be removed.
		if(i==src)
			continue;
		dfs(i,vertice,tree,count);
		count[vertice] += count[i];
	}

}

int main()
{

	vector<int> tree[NO_OF_VERTICES];
	int count[NO_OF_VERTICES]={0};

	tree[1].push_back(2);
	tree[1].push_back(3);
	tree[1].push_back(4);

	tree[2].push_back(5);
	tree[2].push_back(6);

	tree[4].push_back(7);

	tree[6].push_back(8);

	dfs(1,0,tree,count);

	cout<<endl<<endl;

	//count[i] gives the count of a nodes in it's subtree including that node also.
	for(int i=1;i<NO_OF_VERTICES;i++)
		cout<<i<<" Node has "<<count[i]<<" sub-nodes including itself\n";

	return 0;

}
