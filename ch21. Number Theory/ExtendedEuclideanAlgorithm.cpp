/*============================================================================
 * Problem : Implement code for extended euclidean algorithm
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;


/*
 * Recursive Implementation of Extended Euclidean Algorithm.
 */
int extendedGcd(int a, int b, int &x, int &y)
{
	if(b==0)
	{
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int gcd = extendedGcd(b, a%b, x1, y1);

	x = y1;
	y = x1 - int(a/b)*y1;

	return gcd;

}

int main()
{

	int a=54, b=20, x, y;

	cout<<"The GCD for "<<a<<" and "<<b<<" is = "<<extendedGcd(a,b,x,y)<<endl;
	cout<<"The value for coefficient x, y for a,b is = "<<x<<" "<<y<<endl;

	return 0;

}
