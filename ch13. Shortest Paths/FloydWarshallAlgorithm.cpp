/*============================================================================
 * Problem : Implement floyd warshall Algorithm for all pair shortest path.
 * Link	   : https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

	//Here, n=Number of Vertices, m=Number of edges
	int n,m;
	cin>>n>>m;

	//initial state, 9999 considered as infinite distance
	int wt[n+1][n+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)
				wt[i][j]=0;
			else
				wt[i][j]=9999;


	//taking inputs for path
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		wt[a][b]=c;
	}

	//floyd-warshall algorithm
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				wt[i][j]=min(wt[i][j],wt[i][k]+wt[k][j]);

	//q=Number of queries
	int q;
	cin>>q;

	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		if(wt[a][b]!=9999)
			cout<<wt[a][b]<<endl;
		else
			cout<<-1<<endl;
	}

	return 0;

}
