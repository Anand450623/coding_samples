/*
 * Problem: Given a non-negative array, find a contiguous sub-array whose sum is equal is given k
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int k = -1;
	int arr[] = {1,3,2,5,1,1,2,33};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	int start_pointer = 0;
	int last_pointer = start_pointer;

	bool check = true;
	int sum = -1;

	if(k<0)
	{
		cout<<"invalid input...\n";
		return 0;
	}
	else
	{
		while(check)
		{
			if((start_pointer==arr_size))
				check = false;
			else if(sum==k-1)
				check = false;
			else if((sum>k-1 && start_pointer<arr_size) || (last_pointer == arr_size && sum !=k-1))
			{
				sum -= arr[start_pointer];
				start_pointer++;
			}
			else if(sum<k-1 && last_pointer<arr_size)
			{
				sum += arr[last_pointer];
				last_pointer++;
			}
		}
	}

	if(sum==k-1 && last_pointer>start_pointer)
	{
		cout<<"Required sub-array found, the contents of which are :::\n";
		for(int i=start_pointer;i<last_pointer;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	else
		cout<<"Required sub-array not found...";

	return 0;

}
