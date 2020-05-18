/*
 * Problem: find the mimumum number of editing operations needed to transform a string into another string.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string first = "LOVE";
	string second = "MOVIE";

	int row = first.length()+1;
	int col = second.length()+1;
	int distance[row][col];

	distance[0][0]=0;

	for(int i=1;i<row;i++)
		distance[i][0] = i;

	for(int i=1;i<col;i++)
		distance[0][i] = i;

	for(int i=1;i<row;i++)
	{
		for(int j=1;j<col;j++)
		{
			int min = distance[i-1][j-1];

			if(min>distance[i-1][j])
				min = distance[i-1][j];

			if(min>distance[i][j-1])
				min = distance[i][j-1];

			if(min==distance[i-1][j-1])
				distance[i][j] = min + !(first[i-1]==second[j-1]);
			else
				distance[i][j] = min+1;

		}

	}


	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<distance[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"\nThe minimum number of edit operations needed is = "<<distance[row-1][col-1];

	return 0;

}
