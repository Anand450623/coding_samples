/*============================================================================
 * Problem : Implement code for finding co-primes numbers to n between 1 and n.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findPrimesTillN(int n)
{

	vector<int> v;
	int sieve[n] = {0};

	for(int i=2;i<=n;i++)
	{
		if(sieve[i])
			continue;
		else
		{
			for(int u=2*i; u<=n; u+=i)
				sieve[u] = i;
		}
	}

	for(int i=2; i<=n; i++)
		if(!sieve[i])
			v.push_back(i);

	return v;

}

unordered_map<int,int> findFactorCount(int n)
{

	unordered_map<int,int> map;
	vector<int> primes = findPrimesTillN(n);

	int index = 0;
	int temp = n;
	while(primes[index]*primes[index] <= temp)
	{

		while(n % primes[index] == 0)
		{
			map[primes[index]] += 1;
			n /= primes[index];
		}

		index++;

	}

	if(n > 1)
		map[n] = 1;

	return map;

}

/*
 * If the input number is prime, then every other number will be a co-prime for that,
 * therefore, the number of co-prime is equal to (n-1) for input n;
 * where, n is a prime number.
 */

int main()
{

	int n = 13;
	unordered_map<int,int> map = findFactorCount(n);

	int coPrimeCount = 1;
	for(auto x:map)
		coPrimeCount *= (pow(x.first, x.second-1)*(x.first-1));

	cout<<"The co-prime count between 1 and "<<n<<" is = "<<coPrimeCount<<endl;

	return 0;

}
