/*============================================================================
 * Problem : Implement methods for finding catalan's number using various techniques.
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

/*
 * Recursive implementation for finding catalan's number
 */
int catalan(int n)
{

	if(n<=1)
		return 1;
	else
	{

		int res = 0;
		for(int i=0;i<n;i++)
			res += catalan(i)*catalan(n-i-1);

		return res;

	}

}

int main()
{

	int n = 10;

	// Recursive approach
	for(int i=0; i<n; i++)
		cout<<catalan(i)<<" ";
	cout<<endl;

	// dynamic programming approach
	int catalan[n] = {0};
	catalan[0] = catalan[1] = 1;
	for(int i=2; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			catalan[i] += catalan[j]*catalan[i-j-1];
		}
	}

	for(int i=0; i<n; i++)
		cout<<catalan[i]<<" ";
	cout<<endl;

	// combinatorics approach
	for(int i=0; i<n; i++)
		cout<<nCk(2*i, i)/(i+1)<<" ";
	cout<<endl;


	return 0;

}
