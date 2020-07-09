/*============================================================================
 * Problem : Implement Algorithms to find (x^n)modm in efficient manner.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int power(int x, int n, int m)
{

	if(n==0)
		return 1%m;

	int pow = power(x, n/2, m);

	pow = (pow*pow)%m;

	if(n%2)
		pow = (pow*x)%m;

	return pow;

}

int main()
{

	cout<<power(2,5,7)<<endl;
	return 0;

}
