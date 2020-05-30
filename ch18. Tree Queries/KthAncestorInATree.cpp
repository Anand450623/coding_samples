/*============================================================================
 * Problem : Find the kth ancestor for a node in a tree.
 * Link	   : Same as  sucessor graph problem : https://github.com/Anand450623/coding_samples/blob/master/ch16.%20Directed%20Graphs/SuccessorGraphs.cpp
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;


int main()
{

	int NO_OF_NODES = 8;
	int ancestor[4][NO_OF_NODES+1];

	memset(ancestor,0,sizeof(ancestor));

	ancestor[0][1]=0;
	ancestor[0][2]=1;
	ancestor[0][3]=4;
	ancestor[0][4]=1;
	ancestor[0][5]=1;
	ancestor[0][6]=2;
	ancestor[0][7]=4;
	ancestor[0][8]=7;

	for(int i=1;i<4;i++)
		for(int j=0;j<=NO_OF_NODES;j++)
			ancestor[i][j] = ancestor[i-1][ancestor[i-1][j]];

	for(int i=0;i<4;i++)
	{
		for(int j=1;j<=NO_OF_NODES;j++)
			cout<<ancestor[i][j]<<" ";
		cout<<endl;
	}

	int k=2;
	int node=8;
	vector<int> index;

	while(k>0)
	{
		int nm = k&-k;
		index.push_back(log2(nm));
		k-=nm;
	}

	int res=node;
	for(auto i:index)
		res = ancestor[i][res];
	cout<<res;

	return 0;

}
