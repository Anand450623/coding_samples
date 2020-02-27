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
	//int days = 8;
	int days = 3;
	
	//int price[product][days] = {{6,9,5,2,8,9,1,6},{8,2,6,2,7,5,7,2},{5,3,9,7,3,5,1,4}};
	int price[product][days] = {{2,1,4},{3,2,1},{1,2,3}};
		
	int dp[(1<<product)][days];
	
	for(int i=0;i<days;i++)	// day 0 initialization starts
		dp[0][i]=0;
		
	for(int i=1;i<(1<<product);i++)
		for(int j=0;j<days;j++)
			dp[i][j] = INT_MAX;
	
	for(int x=0;x<product;x++) 	// day 0 initialization ends
		dp[1<<x][0]=price[x][0];
		
	
	for(int x=1;x<(1<<product);x++)
	{
		if(!((x&(x-1))==0))
		{
			for(int i=0;i<product;i++)
			{
				if(x&(1<<i))
				{
					dp[x][0] = min(dp[x][0],dp[x^(1<<i)][0]);
				}
			}
		}			
	}
	
	for(int d=1;d<days;d++)
	{
		for(int s=1;s<(1<<product);s++)
		{
			if((s&(s-1))==0)
			{
				dp[s][d] = min(dp[s][d-1],price[int(log2(s))][d]);
			}
			else
			{
				for(int x=0;x<product;x++)
				{
					if(s&(1<<x))
					{
						if(dp[s][d]==INT_MAX)
							dp[s][d] = dp[s^(1<<x)][d-1]+price[x][d];
						else
							dp[s][d] = min(dp[s][d],dp[s^(1<<x)][d-1]+price[x][d]);
					}
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
