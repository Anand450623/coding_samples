/*============================================================================
 * Problem : Implement code for finding gcd of two numbers using Euclid's Algorithm.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{

	cout<<gcd(24, 36)<<endl;
	return 0;

}
