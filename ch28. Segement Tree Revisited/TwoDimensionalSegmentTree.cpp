/*
 * Problem   : Given a 2-dimensional array construct a 2-dimensional segment tree out of it.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
# define N 4
using namespace std;

int seg_array_size;

int final_range_sum(int segment_matrix[8][8], int x1, int x2, int y, int x_min, int x_max, int x_curr)
{

	if(x_min>x_max or x_min>x2 or x1>x_max)
		return 0;
	if(x1 <= x_min and x_max <= x2)
		return segment_matrix[x_curr][y];
	int  mid = x_min - (x_min-x_max)/2;
	return final_range_sum(segment_matrix, x1, x2, y, x_min, mid, 2*x_curr) +
			final_range_sum(segment_matrix, x1, x2, y, mid+1, x_max, 2*x_curr+1);
}

int range_sum(int segment_matrix[8][8], int x1, int y1, int x2, int y2, int y_min, int y_max, int y_curr, int x_max)
{
	if(y_min>y_max or y_min>y2 or y1>y_max)
		return 0;
	if(y1 <= y_min and y_max <= y2)
		return final_range_sum(segment_matrix, x1, x2, y_curr, 1, x_max, 1);
	int mid = y_min - (y_min-y_max)/2;
	return range_sum(segment_matrix, x1, y1, x2, y2, y_min, mid, 2*y_curr, x_max) +
			range_sum(segment_matrix, x1, y1, x2, y2, mid+1, y_max, 2*y_curr+1, x_max);
}

void point_update(int segment_matrix[8][8], int x1, int y1, int value)
{
	int prev = segment_matrix[x1][y1];
	int diff = value - prev;
	for(int i=x1; i>0; i/=2)
		for(int j=y1; j>0; j/=2)
			segment_matrix[i][j] += diff;
}

int main()
{


	int data[N][N] = {
						{1, 2, 3, 4},
						{5, 6, 7, 8},
						{1, 7, 5, 9},
						{3, 0, 6, 2},
					 };

	int temp = N;
	if((temp&-temp)!=temp)
	{
		while((temp&-temp)!=temp)
			temp -= (temp&-temp);
		temp *= 2;
	}

	seg_array_size = 2*temp;
	int segment_matrix[8][8] = {0};

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			segment_matrix[i+N][j+N] = data[i][j];
		}
	}

	for(int i=0; i<N; i++)
	{
		for(int j=seg_array_size-1; j>0; j--)
		{
			segment_matrix[i+N][j/2] += segment_matrix[i+N][j];
		}
	}

	for(int i = seg_array_size-1; i>0; i--)
	{
		for(int j=0; j<seg_array_size; j++)
		{
			segment_matrix[i/2][j] += segment_matrix[i][j];
		}
	}


	cout<<"Segment Matrix Contents are as follows:::\n\n";
	for(int i=1; i<seg_array_size; i++)
	{
		for(int j=1; j<seg_array_size; j++)
			cout<<setw(2)<<segment_matrix[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl;
	cout<<"Range sum for the range[(1,1), (4,4)] = "<<range_sum(segment_matrix, 1, 1, 4, 4, 1, N, 1, N);

	int x=0, y=0, value=10;
	point_update(segment_matrix, x+N, y+N, value);

	cout<<"\n\nUpdated Segment Matrix Contents are as follows:::\n\n";
	for(int i=1; i<seg_array_size; i++)
	{
		for(int j=1; j<seg_array_size; j++)
			cout<<setw(2)<<segment_matrix[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl;

	return 0;

}
