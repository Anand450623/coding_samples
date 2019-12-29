/*
 * Problem: Given a list of weights determine all sums that can be constructed using the weights.
 * Author: Anand Kumar
 */

#include <iostream>
#include <set>
#include <utility>

using namespace std;

set<int> sums;

void generateSubset(int arr[],int low,int arr_len,int sum)
{
	if(low==arr_len)
	{
		sums.insert(sum);
		return;
	}
	else
	{
		generateSubset(arr,low+1,arr_len,sum+arr[low]);
		generateSubset(arr,low+1,arr_len,sum);
	}
}

int main()
{

	int arr[] = {1,3,3,5};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	generateSubset(arr,0,arr_size,0);	// recursive approach
	for(auto i:sums)
		cout<<i<<" ";
	cout<<endl;

	// DP Approach for any most common knapsack problem...

	int sum = 0;
	for(auto i:arr)
		sum+= i;

	bool sum_array[sum+1] = {0};
	sum_array[0] = true;
	for(auto i:arr)
	{
		for(int j=sum;j>=0;j--)
		{
			if(sum_array[j] && j+i<=sum)
				sum_array[j+i]=true;
		}
	}

	for(int i=0;i<sum+1;i++)
		if(sum_array[i])
			cout<<i<<" ";
	cout<<endl;

	return 0;

}
