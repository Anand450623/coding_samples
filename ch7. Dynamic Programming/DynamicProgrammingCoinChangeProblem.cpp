/*
 * Problem: Given a set of coins values coins = {c1,c2,c3,...,ck} and a target sum of money n, our task is to form the sum n using as few coins as
 * 			possible.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
#define N 11
using namespace std;

int coinChange(int sum[],int coins[],int sum_index,int coins_count)
{

	if(sum_index==0)
		return 0;

	if(sum[sum_index] > 0)
		return sum[sum_index];

	for(int i=1;i<N;i++)
	{
		sum[i] = INT32_MAX;
		for(int j=0;j<coins_count;j++)
		{
			if(i>=coins[j])
			{
				sum[i] = min(sum[i], coinChange(sum,coins,i-coins[j],coins_count)+1);
			}
		}
	}

	return sum[sum_index];

}

int main()
{
	int coins[] = {1,3,4};
	int sum[N] = {0};
	int coins_count = 3;

	cout<<coinChange(sum,coins,N-1,coins_count)<<endl<<endl; // recursive approach

	for(int i=1;i<N;i++)	// dynamic programming approach
	{
		sum[i] = INT32_MAX;
		for(auto c:coins)
		{
			if(i-c>=0)
			{
				sum[i] = min(sum[i],sum[i-c]+1);
			}
		}
	}

	for(int i=0;i<N;i++)
		cout<<i<<" = "<<sum[i]<<endl;

	return 0;

}
