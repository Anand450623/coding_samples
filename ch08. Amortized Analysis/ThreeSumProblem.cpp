/*
 * Problem: Given a non-negative array, find the triplet which sums up to k.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int required_sum = 22;
	int arr[] = {1,4,45,6,10,8};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	bool res = false;
	for(int l=0;l<arr_size-2;l++)
	{
		unordered_map<int,int> map;
		int k = required_sum - arr[l];
		for(int i=l+1;i<arr_size;i++)
		{
			if(map.find(k-arr[i])!=map.end())
			{
				res=true;
				cout<<"The required numbers are = "<<arr[i]<<", "<<k-arr[i]<<" and "<<arr[l]<<endl;
				break;
			}
			map[arr[i]] = 1;
		}
	}

	if(!res)
		cout<<"No such pair exists"<<endl;

	return 0;

}
