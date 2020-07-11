/*============================================================================
 * Problem : Implement code for solving diophantine equation.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int extendedGcd(int a, int b, int &x, int &y)
{

	if(b == 0)
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

	int a = 39, b = 15, c = 12;

	int x, y;
	int g = extendedGcd(a, b, x, y);

	if(c%g == 0)
	{
		cout<<"Solution exists and can be solved using extended eulerian algorithm"<<endl;
		cout<<"The required coefficient x,y for a,b are = "<<x*(c/g)<<", "<<y*(c/g)<<endl;
	}
	else
	{
		cout<<"Solution doesn't exists using extended eulerian algorithm"<<endl;
	}

	return 0;

}
