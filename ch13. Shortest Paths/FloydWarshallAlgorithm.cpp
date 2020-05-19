/*============================================================================
 * Problem : Implement floyd warshall Algorithm for all pair shortest path.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
#define NO_OF_VERTICES  5
using namespace std;

void floydWarshall(int wt[][NO_OF_VERTICES])
{

	//initial state
	for(int i=0;i<NO_OF_VERTICES;i++)
	{
		for(int j=0;j<NO_OF_VERTICES;j++)
		{
			cout<<wt[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"***************************************************************************"<<endl<<endl;

	for(int k=0;k<NO_OF_VERTICES;k++)
		for(int i=0;i<NO_OF_VERTICES;i++)
			for(int j=0;j<NO_OF_VERTICES;j++)
				wt[i][j] = min(wt[i][j],wt[i][k]+wt[k][j]);


	//final state -- after floyd warshall implementation
	for(int i=0;i<NO_OF_VERTICES;i++)
	{
		for(int j=0;j<NO_OF_VERTICES;j++)
		{
			cout<<wt[i][j]<<" ";
		}
		cout<<endl;
	}

}

int main()
{

	/*
	 * 	 Here, 999 is used as INT32_MAX
	 * 		   because if original INT32_MAX is used in code then while adding it with any positive number will lead to overflow
	 * 		   and which will result in largest negative number ideally, INT32_MIN
	 * 		   and therefore, the algo will never produce correct result.
	 */

	int wt[][NO_OF_VERTICES] = {{0,5,999,9,1},
							    {5,0,2,999,999},
							    {999,2,0,7,999},
							    {9,999,7,0,2},
							    {1,999,999,2,0}};

	floydWarshall(wt);

	return 0;

}
