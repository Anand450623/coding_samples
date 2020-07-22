/*============================================================================
 * Problem : Implement code to find the count of minimum spanning tree using krichoff's theorem.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

# define N 5

void constructMatrix(vector<int> adj[], int mat[N][N])
{

	int degree[N] = {0};
	for(int i=0; i<N; i++)
	{
		for(auto x: adj[i])
		{
			mat[i][x] = -1;
			degree[i]++;
		}
	}

	for(int i=0; i<N; i++)
		mat[i][i] = degree[i];

}

void getCoFactorMatrix(int mat[N][N], int temp[N][N], int x, int y, int n)
{
	int x_index = 0, y_index = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{

			if(i != x && j != y)
				temp[x_index][y_index++] = mat[i][j];

			if(y_index == n-1)
			{
				y_index = 0;
				x_index++;
			}

		}
	}
}

int determinant(int data[N][N], int n)
{

	if(n==1)
		return data[0][0];

	int temp[N][N];
	int det = 0;
	int sign = 1;

	for(int i=0; i<n; i++)
	{
		getCoFactorMatrix(data, temp, 0, i, n);
		det +=  sign*data[0][i]*determinant(temp, n-1);
		sign *= -1;
	}

	return det;

}

int main()
{

	vector<int> adj[N];

	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(4);

	adj[2].push_back(1);

	adj[3].push_back(1);
	adj[3].push_back(4);

	adj[4].push_back(1);
	adj[4].push_back(3);

	int mat[N][N];
	int temp[N][N];
	memset(mat, 0, sizeof(mat));

	constructMatrix(adj, mat);

	// ignoring the first row and first column
	getCoFactorMatrix(mat, temp, 1, 1, N);

	// removing all non-required terms because for this matrix the required data is in range [1, N-1)
	int kirchoffMat[N][N];

	for(int i=1, x=0; i<N-1; i++, x++)
		for(int j=1, y=0; j<N-1; j++, y++)
			kirchoffMat[x][y] = temp[i][j];

	cout<<"The total number of spanning trees for the given graph is = "<<determinant(kirchoffMat, N-2)<<endl;

	return 0;

}
