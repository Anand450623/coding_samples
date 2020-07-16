/*============================================================================
 * Problem : Implement code to add two matrices.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int main()
{

	/*
	 * for two matrices to be eligible for addition, their dimensions should be exactly the same.
	 */

	int a[2][3] = {{6, 1, 4}, {3, 9, 2}};
	int b[2][3] = {{4, 9, 3}, {8, 1, 3}};

	int res[2][3];
	memset(res, 0, sizeof(res));

	for(int i=0; i<2; i++)
		for(int j=0; j<3; j++)
			res[i][j] = a[i][j] + b[i][j];

	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;

}
