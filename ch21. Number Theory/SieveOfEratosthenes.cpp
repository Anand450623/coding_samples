/*============================================================================
 * Problem : Implement code for finding primes using sieve of Eratosthenes array.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int size = 101;

	/*
	 * 0 in sieve array denotes presence of prime,
	 * for every prime number encountered we mark 2x, 3x... and not prime as they are multiple of prime.
	 */

	int sieve[size] = {0};
	for(int i=2; i<size ;i++)
	{
		if(sieve[i])
			continue;
		else
		{
			for(int u = 2*i; u<size; u+=i)
				sieve[u] = i;
		}
	}

	cout<<"The primes between 2 and "<<size-1<<" are:::\n";
	for(int i=2; i<size ;i++)
		if(!sieve[i])
			cout<<i<<" ";
	cout<<endl;

	return 0;

}
