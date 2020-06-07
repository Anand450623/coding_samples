/*============================================================================
 * Problem : Find the distance between two nodes using sparse table.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int startNode, vector<int> adj[], vector<int> &traversal, bool visited[], int depth[])
{

	if(visited[startNode])
		return;
	else
	{
		traversal.push_back(startNode);
		visited[startNode]=true;
		if(depth[startNode]==0)
			depth[startNode] = 1;
		for(auto i: adj[startNode])
		{
			if(!visited[i])
			{
				depth[i] = depth[startNode]+1;
				dfs(i,adj,traversal,visited,depth);
				traversal.push_back(startNode);
			}
		}
	}

}

int main()
{

	int NO_OF_VERTICES = 8;
	bool visited[NO_OF_VERTICES+1]={false};
	vector<int> adj[NO_OF_VERTICES+1];
	vector<int> traversal;
	int depth[NO_OF_VERTICES+1]={0};

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

	dfs(1,adj,traversal,visited,depth);

	vector<int> input_for_sparse;
	for(auto i:traversal)
		input_for_sparse.push_back(depth[i]);

	int row = input_for_sparse.size();
	int col = ((row&-row)==row)?log2(row):floor(log2(row))+1;

	int sparse_mat[row][col];
	memset(sparse_mat,0,sizeof(sparse_mat));

	for(int i=0;i<row;i++)
		sparse_mat[i][0] = i;


	for(int j=1;j<col;j++)
		for(int i=0;(i+(1<<j)-1)<row;i++)
			sparse_mat[i][j] = (input_for_sparse[sparse_mat[i+(1<<(j-1))][j-1]]>input_for_sparse[sparse_mat[i][j-1]])?sparse_mat[i][j-1]:sparse_mat[i+(1<<(j-1))][j-1];

	int node1 = 5;
	int node2 = 7;
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


	int queryStart = min(indexForNode1,indexForNode2);
	int queryEnd = max(indexForNode1,indexForNode2);
	int items = queryEnd-queryStart+1;
	int range = floor(log2(items));

	int min_index = min(sparse_mat[queryStart][range],sparse_mat[queryStart+items-(1<<range)][range]);

	cout<<"The distance between two nodes is given by = "<<depth[traversal[indexForNode1]]+depth[traversal[indexForNode2]] - (2*depth[traversal[min_index]]);

	return 0;

}
