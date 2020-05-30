/*============================================================================
 * Problem : Implement a successor graph and perform queries on it.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

	int noOfVertices = 9;
	int u=5;
	int successor[u][noOfVertices+1];

	memset(successor,0,sizeof(successor));

	successor[0][1]=3;
	successor[0][2]=5;
	successor[0][3]=7;
	successor[0][4]=6;
	successor[0][5]=2;
	successor[0][6]=2;
	successor[0][7]=1;
	successor[0][8]=6;
	successor[0][9]=3;

	/*
	 * This matrix represents that if initially successor of a  node is given then after 2^k steps on which node you will end up.
	 * for Eg. successor[0][1] represents starting from 1 and after taking 2^0=1 steps on which node you will land up
	 * Similarly, successor[3][1] represents starting from node 1 and after taking 2^3=8 steps on which node you'll end up.
	 */

	for(int i=1;i<u;i++)
		for(int j=1;j<=noOfVertices;j++)
			successor[i][j] = successor[i-1][successor[i-1][j]];

	int noOfSteps=11;
	int sourceNode=4;

	// Aim is to find out starting from node 4 if we go 11 steps then on which node we'll end up ?
	// Since, we know matrix contain steps data in power of 2 so, we should break total steps in power of 2 as well.
	// 11 = 8+2+1, which is nothing but index 3, 1 and 0.
	// therefore, solution becomes successor[0][successor[1][successor[3][4]]] which can be easily calculated via loops.

	vector<int> binarySteps;
	while(noOfSteps>0)
	{
		int reductionAmount = noOfSteps&(-noOfSteps);
		binarySteps.push_back(log2(reductionAmount));
		noOfSteps -= reductionAmount;
	}

	int res = successor[binarySteps.size()-1][sourceNode];
	for(int i=binarySteps.size()-2;i>=0;i--)
		res = successor[i][res];
	
	/*
	* An alternate approach : added later
	int res=sourceNode;
	for(auto i:binarySteps)
		res = successor[i][res];
	*/

	cout<<res<<endl;

	return 0;

}
