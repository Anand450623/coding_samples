/*
 * Problem: Given a set of coins values coins = {c1,c2,c3,...,ck} and a target sum of money n, our task is to calculate total no of ways in which we can construct the
 * 			required sum.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
#define N 11
using namespace std;

int main()
{
	int coins[] = {1,3,4};
	int total_sum[N] = {0};

	total_sum[0]=1;
	for(int i=1;i<N;i++)
	{
		for(auto c:coins)
		{
			if(i-c>=0)
			{
				total_sum[i] += total_sum[i-c];
			}
		}
	}

	for(int i=0;i<N;i++)
		cout<<i<<" = "<<total_sum[i]<<endl;

	return 0;

}
