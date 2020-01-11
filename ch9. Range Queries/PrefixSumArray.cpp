/*
 * Problem : Given a array, find the sum for a given range of indexes.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int arr[] = {1,3,4,8,6,1,4,2};
	int query_begin = 3, query_end = 6;
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	int prefix_sum[arr_size];
	prefix_sum[0] = arr[0];
	for(int i=1;i<arr_size;i++)
		prefix_sum[i] = arr[i]+prefix_sum[i-1];

	for(int i=0;i<arr_size;i++)
		cout<<prefix_sum[i]<<" ";
	cout<<endl;

	cout<<"The required sum for given range is = "<<prefix_sum[query_end]-prefix_sum[query_begin-1]<<endl;

	return 0;

}
