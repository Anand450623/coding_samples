/*
 * Problem : 0-1 knapsack problem
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int knapsack(int weights[],int values[],int remaining_capacity,int n,int index,int curr_sum)
{

	if(remaining_capacity<0)
		return curr_sum-values[index-1];

	if(n==index)
		return curr_sum;

	return max(knapsack(weights,values,remaining_capacity,n,index+1,curr_sum),knapsack(weights,values,remaining_capacity-weights[index],n,index+1,curr_sum+values[index]));

}

int main()
{

	int weights[] = {12,7,11,8,9};
	int values[] = {24,13,23,15,16};
	int capacity = 26;

	int n = sizeof(weights)/sizeof(weights[0]);

	cout<<"Recursive Approach : Maximum knapsack one can take = "<<knapsack(weights,values,capacity,n,0,0)<<endl; // recursive solution

	// Dynamic Programming Approach

	int arr[n][capacity+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=capacity;j++)
		{
			if(i==0||j==0)
				arr[i][j] = 0;
			else if(weights[i-1]<=j)
				arr[i][j] = max(values[i-1]+arr[i-1][j-weights[i-1]],arr[i-1][j]);
			else
				arr[i][j] = arr[i-1][j];
		}
	}

	cout<<"Dynamic Programming Approach : Maximum knapsack one can take = "<<arr[n][capacity]<<endl;

	return 0;

}
