/*
 * Problem: Given a set of n elements, find the length of longest increasing subsequence in that array.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int arr[] = {6,2,5,1,7,4,8,3};
	int arr_size=8;
	int max_len[arr_size] = {0};

	for(int i=0;i<arr_size;i++)
	{
		max_len[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				max_len[i] = max(max_len[i],max_len[j]+1);
			}
		}
	}

	int max = INT32_MIN;
	for(int i=0;i<arr_size;i++)
	{
		cout<<max_len[i]<<" ";
		if(max<max_len[i])
			max = max_len[i];
	}

	cout<<"\nThe length of longest increasing subsequence = "<<max<<endl;

	return 0;

}
