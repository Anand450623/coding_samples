/*
 * Problem : Given a matrix, find the sum for a given sub-rectangle.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int row=4;
	int col=5;
	int x1=2,y1=2;
	int x2=3,y2=4;

	int matrix[][col] = {{1,2,3,4,6},{5,3,8,1,2},{4,6,7,5,5},{2,4,8,9,4}};
	int prefix_sum_matrix[row][col];

	memset(prefix_sum_matrix,0,sizeof(prefix_sum_matrix));

	prefix_sum_matrix[0][0] =matrix[0][0];
	for(int i=1;i<row;i++)
		prefix_sum_matrix[i][0] = prefix_sum_matrix[i-1][0] + matrix[i][0];
	for(int j=1;j<col;j++)
			prefix_sum_matrix[0][j] = prefix_sum_matrix[0][j-1] + matrix[0][j];

	for(int i=1;i<row;i++)
		for(int j=1;j<col;j++)
			prefix_sum_matrix[i][j] = matrix[i][j]+prefix_sum_matrix[i-1][j]+prefix_sum_matrix[i][j-1]-prefix_sum_matrix[i-1][j-1];

	cout<<"The original array -->\n";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}

	cout<<"The prefix sum array -->\n";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			cout<<prefix_sum_matrix[i][j]<<" ";
		cout<<endl;
	}

	int sum = prefix_sum_matrix[x2][y2];

	sum -= ((x1)>0?prefix_sum_matrix[x1-1][y2]:0);
	sum -= ((y1>0)?prefix_sum_matrix[x2][y1-1]:0);
	sum += ((x1>0 && y1>0)?prefix_sum_matrix[x1-1][y1-1]:0);

	cout<<"The required sum is = "<<sum<<endl;

	return 0;

}
