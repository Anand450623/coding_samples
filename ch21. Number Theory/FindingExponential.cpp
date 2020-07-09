/*============================================================================
 * Problem : Implement Algorithms to find x^n in efficient manner.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
	
	if(n==0)
		return 1;
	
	int pow = power(x, n/2);
	
	pow *= pow;
	if(n%2)
		pow *= x;
	
	return pow;
	
}

int main()
{

	cout<<power(2,3)<<endl;
	return 0;

}
