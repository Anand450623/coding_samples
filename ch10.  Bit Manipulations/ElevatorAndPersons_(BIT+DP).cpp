/*
 * Problem : There is an elevator with maximum weight capacity X, and N people with known weights who want to get from ground floor 
 * 			 to top floor. calculate the minimum number of rides so that all the people can travel to top floor.
 *  
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x=10,n=5;
	int weight[] = {2,3,3,5,6};
	
	pair<int,int> best[1<<n];	// best contains pair for rides and last
	
	best[0] = {0,0};
	
	for(int s=1;s<(1<<n);s++)
	{
		best[s] = {n,0};
		for(int p=0;p<n;p++)
		{
			if(s&(1<<p))
			{
				auto option = best[s^(1<<p)];
				if(option.second + weight[p] <=x)
				{
					option.second += weight[p];
				}
				else
				{
					option.first++;
					option.second = weight[p];
				}
				best[s] = min(best[s],option);
			}
		}
	}
	
	auto result = best[(1<<n)-1];
	cout<<"Minimum number of rides = "<<result.first+1<<endl;
	
	return 0;
	
}
