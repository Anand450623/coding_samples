/*
 * Problem: Given a non-negative array, find the pair which sums up to k.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int k = 12;
	int arr[] = {1,4,5,6,7,9,9,10};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	unordered_map<int,int> map;
	bool res = false;
	for(int i=0;i<arr_size;i++)
	{
		if(map.find(k-arr[i])!=map.end())
		{
			res=true;
			cout<<"The required numbers are = "<<arr[i]<<" and "<<k-arr[i]<<endl;
			break;
		}
		map[arr[i]] = 1;
	}

	if(!res)
		cout<<"No such pair exists"<<endl;

	return 0;

}
