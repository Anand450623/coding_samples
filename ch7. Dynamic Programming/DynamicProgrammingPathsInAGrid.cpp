/*
 * Problem: find a path from the upper-left corner to lower-right corner of an n*n grid,such that we move only down or right.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int row=5;
	int col=5;

	int grid[][col] = {{3,7,9,2,7},{9,8,3,5,5},{1,7,9,8,5},{3,8,6,4,10},{6,3,9,7,8}};
	int sum[row][col];

	sum[0][0] = grid[0][0];

	for(int i=1;i<row;i++)
		sum[i][0] = sum[i-1][0]+grid[i][0];

	for(int i=1;i<col;i++)
		sum[0][i] = sum[0][i-1]+grid[0][i];

	for(int i=1;i<row;i++)
	{
		for(int j=1;j<col;j++)
		{
			sum[i][j] = max(sum[i-1][j],sum[i][j-1])+grid[i][j];
		}
	}

	vector<int> v;

	int i = row-1;
	int j = col-1;

	while(i>=0 && j>=0)
	{
		v.push_back(grid[i][j]);
		if(sum[i-1][j]>sum[i][j-1])
			i--;
		else
			j--;
	}

	v.push_back(grid[0][0]);

	cout<<"The path followed for getting maximum path ::: ";
	for(int i=v.size()-1;i>=1;i--)
		cout<<v[i]<<"->";
	cout<<v[0];
	cout<<endl;

	cout<<"The maximum sum obtained while traversing the path = "<<sum[row-1][col-1];

	return 0;

}
