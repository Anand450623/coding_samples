/*============================================================================
 * Problem : Use BurnSide Lemma for calculating the number of symmetric necklaces of n perls, where each perl has m possible colors.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{

	if(b == 0)
		return a;
	else
		return gcd(b, a%b);

}

int power(int x, int m)
{

	if(m==0) return 1;

	int res = power(x, m/2);
	res *= res;

	if(m%2)
		res *= x;

	return res;

}

int main()
{

	int n = 4, m = 3;

	int count = 0;
	for(int i=0; i<n; i++)
		count += power(m, gcd(i,n));

	cout<<"The required number of symmetrical necklaces is given by = "<<(count/n)<<endl;
	return 0;

}
