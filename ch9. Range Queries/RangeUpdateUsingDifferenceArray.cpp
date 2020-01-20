/*
 * Problem : Given an array of integers, implement an efficient technique for range updates
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int arr[] = {3,3,1,1,1,5,2,2};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int darr[arr_size] = {arr[0]};
	
	for(int i=1;i<arr_size;i++)
		darr[i] = arr[i]-arr[i-1];
		
	cout<<"Before update :::\n";
	for(int i=0;i<arr_size;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	int qs=1,qe=4,val=5;
	
	darr[qs] += val;
	darr[qe+1] -= val;
	
	cout<<"\nAfter update :::\n";
	
	int sum = darr[0];
	for(int i=1;i<arr_size;i++)
	{
		cout<<sum<<" ";
		sum += darr[i];
	}
	cout<<sum;
	
	return 0;
	
}
