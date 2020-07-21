/*============================================================================
 * Problem : Implement code to find inverse of a matrix.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

#define N 4

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

void transpose(int mat[N][N], double temp[N][N], int n)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			temp[j][i] = mat[i][j];
}

void getCoFactor(int mat[N][N], int temp[N][N], int x, int y, int n)
{

	int x_index=0, y_index=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i!=x && j!=y)
				temp[x_index][y_index++] = mat[i][j];
			if(y_index == n-1)
			{
				y_index=0;
				x_index++;
			}
		}
	}

}

void copyMat(int mat[N][N], int temp[N][N], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			temp[i][j] = mat[i][j];
		}
	}
}

int main()
{

	int temp[N][N];
	int mat[N][N] = {{1, 1, 1, -1},
					 {1, 1, -1, 1},
					 {1, -1, 1, 1},
					 {-1, 1, 1, 1}};

	copyMat(mat, temp, N);
	int det = determinant(temp, N);

	if(det==0)
		cout<<"The given matrix is singular, therefore inverse doesn't exists...";
	else
	{

		memset(temp,0,sizeof(temp));
		int coFactor[N][N];
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				getCoFactor(mat, temp, i, j, N);
				coFactor[i][j] = pow(-1, i+j+2) * determinant(temp, N-1);
			}
		}

		double adjoint[N][N];
		transpose(coFactor, adjoint, N);

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				adjoint[i][j] /= det;
			}
		}

		cout<<"The inverse of matrix exists, and it is given by :::\n";

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				cout<<setw(2)<<adjoint[i][j]<<" ";
			}
			cout<<endl;
		}

	}

	return 0;

}
