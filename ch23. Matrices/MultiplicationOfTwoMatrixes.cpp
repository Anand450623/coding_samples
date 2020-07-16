/*============================================================================
 * Problem : Implement code to multiply two matrices.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int m1=3, n1=2;
	int m2=2, n2=2;

	int a[m1][n1] = {{1, 4}, {3, 9}, {8, 6}};
	int b[m2][n2] = {{1, 6}, {2, 9}};

	if(n1 != m2)
		cout<<"multiplication not possible"<<endl;
	else
	{

		int result[m1][n2];
		memset(result, 0, sizeof(result));

		for(int i=0; i<m1; i++)
			for(int j=0; j<n2; j++)
				for(int k=0; k<n1; k++)
					result[i][j] += a[i][k] * b[k][j];

		for(int i=0; i<m1; i++)
		{
			for(int j=0; j<n2; j++)
				cout<<setw(2)<<result[i][j]<<" ";
			cout<<endl;
		}

	}

	return 0;

}
