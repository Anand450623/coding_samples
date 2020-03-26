/*
 * Problem : Sum over subsets.
 *  
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int n=2;
	int arr[] =  {7,12,14,16};
	int dp[(1<<n)][n];
	
	memset(dp,0,sizeof(dp));
	
	for(int x=0;x<(1<<n);x++)
	{
		for(int i=0;i<n;i++)
		{
			if(x & (1<<i))
			{
				if(i==0)
					dp[x][i] = arr[x] + arr[x^(1<<i)];
				else
					dp[x][i] = dp[x][i-1] + dp[x^(1<<i)][i-1];
			}
			else
			{
				if(i==0)
					dp[x][i] = arr[x];
				else
					dp[x][i] = dp[x][i-1];
			}		
		}
	}
		
	for(int x=0;x<(1<<n);x++)
		cout<<dp[x][n-1]<<" ";
	cout<<endl;	
		
	return 0;
	
}
