/*
 * Problem: Given a set of n elements, find the length of longest increasing subsequence in that array.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int arr[] = {2,5,3,7,11,8,10,13,6};
	int arr_size = sizeof(arr)/sizeof(arr[0]) ;
	int max_len[arr_size] = {0};
	int subarray_index[arr_size] = {-1};

	for(int i=0;i<arr_size;i++)
	{
		max_len[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				int max = (max_len[i]>max_len[j]+1)?i:j;
				if(max!=i)
				{
					max_len[i] = max_len[j]+1;
					subarray_index[i]=j;
				}
			}
		}
	}

	int max = INT32_MIN;
	int max_index = -1;
	for(int i=0;i<arr_size;i++)
	{
		if(max<max_len[i])
		{
			max = max_len[i];
			max_index=i;
		}
	}

	cout<<"The length of longest increasing subsequence = "<<max<<endl;
	cout<<"The longest increasing subsequence is :::\n";
	vector<int> required_sequence;
	while(subarray_index[max_index]!=-1)
	{
		required_sequence.push_back(arr[max_index]);
		max_index = subarray_index[max_index];
	}
	required_sequence.push_back(arr[max_index]);

	for(int i=required_sequence.size()-1;i>=0;i--)
	{
		cout<<required_sequence[i]<<" ";
	}
	cout<<endl;

	return 0;

}
