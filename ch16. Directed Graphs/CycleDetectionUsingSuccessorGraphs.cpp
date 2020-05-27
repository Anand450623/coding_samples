/*============================================================================
 * Problem : Implement cycle Detection using successor graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

	int noOfVertices = 6;
	int u=2;
	int successor[u][noOfVertices+1];

	memset(successor,0,sizeof(successor));

	successor[0][1]=2;
	successor[0][2]=3;
	successor[0][3]=4;
	successor[0][4]=5;
	successor[0][5]=6;
	successor[0][6]=4;

	for(int i=1;i<u;i++)
		for(int j=1;j<=noOfVertices;j++)
			successor[i][j] = successor[i-1][successor[i-1][j]];

	int startingNode = 1;
	int a = successor[0][startingNode];
	int b = successor[1][startingNode];
	while(a!=b)
	{
		a = successor[0][a];
		b = successor[1][b];
	}

	a = startingNode;
	while(a!=b)
	{
		a = successor[0][a];
		b = successor[0][b];
	}

	cout<<"The cycle in graph starts at node : "<<a<<endl;

	b = successor[0][a];
	int lengthOfCycle=1;
	while(a!=b)
	{
		b = successor[0][b];
		lengthOfCycle++;
	}

	cout<<"The length of cycle in given graph is : "<<lengthOfCycle<<endl;

	return 0;

}
