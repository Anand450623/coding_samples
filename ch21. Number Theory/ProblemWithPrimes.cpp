/*============================================================================
 * Problem : Implement Algorithms to find the numbers, sum and product of factors of a given number
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

/*
 * While Checking for prime it is sufficient to check remainder from 2 to sqrt(n).
 */
bool isPrime(int number)
{
	for(int i=2;i*i<=number;i++)
		if(number%i==0)
			return false;
	return true;
}

/*
 * While finding prime factorization, it is sufficient to check remainder from prime numbers in the range(2, sqrt(n)).
 */
unordered_map<int,int> findFactorCount(int n)
{

	unordered_map<int,int> map;
	vector<int> primes;
	for(int i=2;i<=n;i++)
		if(isPrime(i))
			primes.push_back(i);

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

int main()
{

	int n = 84;

	unordered_map<int, int> map = findFactorCount(n);
	int numberOfFactors = 1;

	for(auto x:map)
		numberOfFactors *= x.second+1;

	cout<<"Total number of factors for "<<n<<" is = "<<numberOfFactors<<endl;

	double sum = 1.0;

	for(auto x:map)
		sum *= ((pow(x.first, x.second+1)-1)/(x.first - 1));

	cout<<"The sum of all the factors for "<<n<<" is = "<<sum<<endl;

	long long unsigned pFactor = 1;

	for(int i=0; i<(numberOfFactors/2); i++)
		pFactor *= n;

	cout<<"The product of all the factors of "<<n<<" is = "<<pFactor<<endl;

	cout<<"The approximate density of primes between 1 and "<<n<<" is = "<<int(n/log(n))<<endl;

	return 0;

}
