/*
 * Problem: Given a set of coins values coins = {c1,c2,c3,...,ck} and a target sum of money n, our task is to check which all coins sum up together to arrange that sum.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
#define N 11
using namespace std;

int main()
{
	int coins[] = {1,3,4};
	int sum[N] = {0};
	int first[N] = {0};

	for(int i=1;i<N;i++)
	{
		sum[i] = INT32_MAX;
		for(auto c:coins)
		{
			if(i-c>=0 && sum[i-c]+1 < sum[i])
			{
				sum[i] = sum[i-c]+1;
				first[i]= c;
			}
		}
	}

	for(int i=1;i<N;i++)
	{
		cout<<i<<" : ";
		int n=i;
		while(n>0)
		{
			cout<<first[n]<<" ";
			n-=first[n];
		}
		cout<<endl;
	}

	return 0;

}
