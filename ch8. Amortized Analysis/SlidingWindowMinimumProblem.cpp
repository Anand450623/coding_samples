/*
 * Problem: Given a numeric array and a window size, the problem is to report the smallest value within each window.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int arr[] = {2,1,4,5,3,4,1,2};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int window_size = 3;

	deque<int> dq;
	for(int i=0;i<window_size;i++)
	{
		while(!dq.empty() && arr[dq.back()]>arr[i])
			dq.pop_back();
		dq.push_back(i);
	}

	for(int i=window_size;i<arr_size;i++)
	{
		cout<<arr[dq.front()]<<" ";
		while(!dq.empty() && dq.front()<=(i-window_size))
			dq.pop_front();
		while(!dq.empty() && arr[dq.back()]>arr[i])
			dq.pop_back();
		dq.push_back(i);
	}

	cout<<arr[dq.front()]<<" ";

	return 0;

}
