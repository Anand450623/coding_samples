/*============================================================================
 * Problem : Implement cayley's formula to find number of labeled trees that can be formed from n nodes.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

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

	int n = 4;
	cout<<"The required number of labeled trees are = "<<power(n, n-2)<<endl;
	return 0;

}
