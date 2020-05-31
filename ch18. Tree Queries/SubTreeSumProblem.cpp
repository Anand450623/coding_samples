/*============================================================================
 * Problem : Find the Sum of Subtree for a node in given tree using segment tree.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

/*
 *  Initial Call : searchInRange(segmentTree,1,arr_size,startIndex+1,endIndex+1,1)
 *  Parameters : SegmentTree[Segment Tree array]
 *  			 sr: start Index from where data is stored i.e., 1 for my implementation.
 *  			 er: end Index till where segment tree is generated.
 *  			 startIndex = queryStartRange, Here, 1 is added because data is shifted from 1 place
 *  			 endIndex = queryEndIndex, 1 added for same above reason.
 *  			 ci = current pointer of data, initially 1.
 */
int searchInRange(int segmentTree[], int sr, int er, int startIndex,int endIndex, int ci)
{

	//This "if" checks if the current range falls within given range and if yes return the sum of the range stored at current_index.
	if(startIndex <= sr && endIndex >= er)
		return segmentTree[ci];

	//This "if" checks if the current range is outside of the query range and if so, not eligible to be queried and thus return 0.
	if(er<startIndex || sr > endIndex)
		return 0;

	//Otherwise, split the total range into 2 equal parts and start querying both parts.
	int mid = sr+(er-sr)/2;
	return searchInRange(segmentTree,sr,mid,startIndex,endIndex,2*ci)+searchInRange(segmentTree,mid+1,er,startIndex,endIndex,2*ci+1);

}

void updateSegmentTree(int segmentTree[], int pos, int diff)
{
	while(pos>=1)
	{
		segmentTree[pos] += diff;
		pos/=2;
	}
}

void dfs(int node,vector<int> adj[], vector<int> &traversal)
{
	traversal.push_back(node);
	for(auto i:adj[node])
		dfs(i,adj,traversal);
	traversal.push_back(node);
}

int main()
{

	/*
	 * Problem : Adjacency list of "n" nodes/vertices is given. Each node is associated with some data/weight/info.
	 * 			 Create a suitable data structure which can query and update data values associated with a queried node in log(n) complexity.
	 * 			 I have used segment tree for the solution.
	 * 			 vector<int> adj[] is the above mentioned adjacency list.
	 * 			 vector<int> data is the above mentioned data associated.
	 * 			 vector<int> traversal contains tree traversal according to euler path algorithm.
	 * 			 The result of range query is divided by 2 as any element is twice added while calculating the solution.
	 */

	int NO_OF_NODES = 9;
	vector<int> adj[NO_OF_NODES+1];
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

	data.push_back(-1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(5);
	data.push_back(3);
	data.push_back(1);
	data.push_back(4);
	data.push_back(4);
	data.push_back(3);
	data.push_back(1);

	dfs(1,adj,traversal);

	int arr_size = traversal.size();
	if((arr_size&-arr_size) != arr_size)
	{
		arr_size -= (arr_size&-arr_size);
		arr_size *= 2;
	}

	size_t index=0;
	int segmentTree[arr_size*2] = {0};
	for(int i=arr_size;index<traversal.size();i++)
		segmentTree[i] = data[traversal[index++]];

	for(int i=arr_size-1;i>0;i--)
		segmentTree[i] = segmentTree[2*i]+segmentTree[2*i+1];

	int searchNode = 4;
	int startIndex=-1;
	int endIndex;

	for(size_t i=0;i<traversal.size();i++)
	{
		if(traversal[i]==searchNode && startIndex==-1)
			startIndex = i;
		else if(traversal[i]==searchNode && startIndex>-1)
			endIndex = i;
	}

	cout<<searchInRange(segmentTree,1,arr_size,startIndex+1,endIndex+1,1)/2<<endl;

	//update the same searchNode used earlier
	int value = 10;
	int diff = value - segmentTree[startIndex+arr_size];
	data[searchNode] = value;

	updateSegmentTree(segmentTree,startIndex+arr_size,diff);
	updateSegmentTree(segmentTree,endIndex+arr_size,diff);

	cout<<searchInRange(segmentTree,1,arr_size,startIndex+1,endIndex+1,1)/2<<endl;

	return 0;

}
