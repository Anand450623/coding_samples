/*
 * Problem   : Find sum of maximum sub array from given input array.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int arr[] = {-1,2,4,-3,5,2,-5,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	int sum = 0;
	int best = INT32_MIN;
	for(int i=0; i<size; i++)
	{
		sum = max(arr[i], sum+arr[i]);
		best = max(best, sum);
	}

	cout<<"The sum of maximum sub array is = "<<best<<endl;
	return 0;

}
