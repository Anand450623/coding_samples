/*============================================================================
 * Problem : Implement code for finding modular multiplicative inverse of all integer from 1 to n with respect to a given prime number.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

/*
 * Recurrence relation used: inverse(a) = (inverse(prime % a) * (prime - prime/a)) % prime
 */
void findModuloInverse(int n, int m)
{

	int dp[n + 1];
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[m % i] *	(m - m / i) % m;

	for (int i = 1; i <= n; i++)
		cout << dp[i] << ' ';

}

int main()
{
	int n = 10, m=17;
	findModuloInverse(n,m);
	return 0;
}
