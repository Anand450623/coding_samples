/*============================================================================
 * Problem : Implement code to find determinant of a matrix without using recursion.
 * Ref     : https://www.geeksforgeeks.org/determinant-of-a-matrix/
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

#define N 3

int determinant(int mat[N][N], int n)
{

	int det=1, total=1;

	for(int i=0; i<n; i++)
	{

		int index=i;
		while(mat[index][i] == 0 && index < n)
			index++;

		if(index == n)
			break;

		if(index != i)
		{
			for(int x=0; x<n; x++)
			{
				int temp = mat[index][x];
				mat[index][x] = mat[i][x];
				mat[i][x] = temp;
			}
		}

		det *= pow(-1, (index-i));

		int temp[n] = {0};

		for(int x=0; x<n; x++)
			temp[x] = mat[i][x];

		for(int j=i+1; j<n; j++)
		{
			int mat1 = temp[i];
			int mat2 = mat[j][i];
			for(int x=i; x<n; x++)
				mat[j][x] = (mat[j][x]*mat1) - (mat[i][x]*mat2);
			total *= mat1;
		}

	}

	for(int i=0; i<n; i++)
		det *= mat[i][i];

	return (det/total);

}

int main()
{


	int mat[N][N] = {{1, 2, 3},
					{4, 5, 6},
					{7, 8, 9}};

	/*int mat[N][N] = {{6, 1, 1},
					{4, -2, 5},
					{2, 8, 7}};*/


/*
	int mat[N][N] = {{1, 0, 2, -1},
					{3, 0, 0, 5},
					{2, 1, 4, -3},
					{1, 0, 5, 0}
					};
*/

	printf("Determinant of the matrix is : %d", determinant(mat, N));
	return 0;

}
