/*
 * Problem: Given a non-negative array, find the number of contiguous sub-arrays whose sum is equal is given k
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int k = 10;
	int arr[] = {10,2,-2,-20,10};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	unordered_map<int,int> m;
	int curr_sum=0;
	int count = 0;

	for(int i=0;i<arr_size;i++)
	{
		curr_sum += arr[i];
		if(curr_sum == k)
			count++;
		if(m.find(curr_sum-k)!=m.end())
			count += m[curr_sum-k];
		m[curr_sum]++;
	}

	cout<<"total no of required sub arrays found = "<<count<<endl;

	return 0;

}
