/*
 * Problem: Given a non-negative array, find the nearest smallest element in the left side of the array.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int arr[] = {1,6,4,10,2,5};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	stack<int> s;
	for(int i=0;i<arr_size;i++)
	{
		while(!s.empty() && arr[i]<s.top())
			s.pop();
		if(!s.empty())
			cout<<s.top()<<",";
		else
			cout<<"_,";
		s.push(arr[i]);
	}

	return 0;

}
