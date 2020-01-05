/*
 * Problem: Given number of floors and egg, determine number of trails you need to find threshold floor after which egg will break.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int egg_count = 2;
	int floor_count = 100;

	int arr[egg_count+1][floor_count+1];

	for(int i=0;i<=egg_count;i++)
	{
		arr[i][0] = 0;
		arr[i][1] = 1;
	}

	for(int i=0;i<=floor_count;i++)
	{
		arr[0][i] = 0;
		arr[1][i] = i;
	}

	for(int i=2;i<=egg_count;i++)
	{
		for(int j=2;j<=floor_count;j++)
		{
			arr[i][j] = INT32_MAX;
			for(int k=1;k<=j;k++)
			{
				int res = 1 + max(arr[i-1][k-1],arr[i][j-k]);
				if(res<arr[i][j])
					arr[i][j] = res;
			}
		}
	}

	cout<<"Minimum number of trails required = "<<arr[egg_count][floor_count]<<endl;

	return 0;

}
