/*
 * Problem : Given the prices of K products over N days, we want to buy each product exactly once. 
 * 			 However, we are allowded to buy at most one product in a day. 
 * 			 calculate the minimum total price ?
 * 
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int product=3;
	int days = 8;
	
	int price[product][days] = {{6,9,5,2,8,9,1,6},{8,2,6,2,7,5,7,2},{5,3,9,7,3,5,1,4}};
		
	int dp[(1<<product)][days];
	memset(dp,1,sizeof(dp));
	
	for(int i=0;i<days;i++)
		dp[0][i]=0;
	
	for(int x=0;x<product;x++) 	// day 0 initialization
		dp[1<<x][0]=price[x][0];
		
		
	for(int d=1;d<days;d++)
	{
		for(int s=1;s<(1<<product);s++)
		{
			dp[s][d] = dp[s][d-1];
			for(int x=0;x<product;x++)
			{
				if(s&(1<<x))
				{
					dp[s][d] = min(dp[s][d],dp[s^(1<<x)][d-1]+price[x][d]);
				}
			}
		}
	}
	
	for(int i=0;i<(1<<product);i++)
	{
		for(int j=0;j<days;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
	
}
