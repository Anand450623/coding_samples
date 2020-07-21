/*============================================================================
 * Problem : Implement code to find determinant of a matrix using recursion.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
#define N 4
using namespace std;

void findCoFactor(int temp[N][N], int mat[N][N], int r, int c, int n)
{

	int i=0, j=0;
	for(int row = 0; row<n; row++)
	{
		for(int col = 0; col<n; col++)
		{

			if(row != r && col != c)
				temp[i][j++] = mat[row][col];

			if(j == n-1)
			{
				j = 0;
				i++;
			}

		}
	}

}

int determinant(int mat[N][N], int n)
{
	if(n == 1)
	{
		return mat[0][0];
	}
	else
	{
		int temp[N][N];
		int sum = 0;
		int sign  = 1;
		for(int i=0; i<n; i++)
		{
			findCoFactor(temp, mat,  0, i, n);
			sum += mat[0][i]*sign*determinant(temp, n-1);
			sign *= -1;
		}
		return sum;
	}
}

int main()
{

	int mat[N][N] = {{1, 0, 2, -1},
					 {3, 0, 0, 5},
					 {2, 1, 4, -3},
					 {1, 0, 5, 0}};

/*
	int mat[N][N] = {{1, 2, 3},
					 {4, 5, 6},
					 {7, 8, 9}};
*/


	// recursive implementation
	cout<<determinant(mat, N);

	return 0;

}
