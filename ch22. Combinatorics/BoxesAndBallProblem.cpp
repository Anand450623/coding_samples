/*============================================================================
 * Problem : Implement solution for boxes and ball problem under different circumstance.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int nCk(int n, int k)
{

	unsigned long int res = 1;

	// Since C(n, k) = C(n, n-k)
	if (k > n - k)
	   k = n - k;

	// Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
	for (int i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}

	return res;

}

int main()
{

	/*
	 * Boxes and Ball is a useful model, where we count number of different ways to place k balls in n boxes under different scenarios.
	 * For code implementation we'll assume k = 2 and n = 5.
	 */

	int k=2, n=5;

	// Scenario #1: Each box contains at most one ball.
	cout<<"Solution for scenario #1 = "<<nCk(n, k)<<endl;

	// Scenario #2: A box can contains multiple balls.
	cout<<"Solution for scenario #2 = "<<nCk(n+k-1, k)<<endl;

	// Scenario #3: Each box may contain at most one ball and no two adjacent boxes may contain a ball.
	cout<<"Solution for scenario #3 = "<<nCk(n-k+1, n-2*k+1)<<endl;

	return 0;

}
