/*============================================================================
 * Problem : Implement code to obtain transpose of a given matrix
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int m=3, n=4;
	int input[m][n] = {{6, 13, 7, 4}, {7, 0 ,8, 2}, {9, 5, 4, 18}};

	int transpose[n][m];
	memset(transpose, 0, sizeof(transpose));

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			transpose[j][i] = input[i][j];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<setw(2)<<transpose[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;

}
