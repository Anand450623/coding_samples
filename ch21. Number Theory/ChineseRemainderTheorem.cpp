/*============================================================================
 * Problem : Implement code for solving equations using chinese remainder theorem.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

/*
 * Using chinese remainder theorem, we solve a set of linear equations given by:
 * x = a1 mod b1
 * x = a2 mod b2
 * x = a3 mod b3...
 */
int main()
{

	int size =3;

	int a[] = {3,4,2};
	int b[] = {5,7,3};

	int p = 1;
	for(int i=0; i<size; i++)
		p *= b[i];

	int x=0;
	for(int i=0; i<size; i++)
	{
		int temp = p/b[i];
		x += a[i]*temp*(temp%b[i]);
	}

	cout<<"The solution for given set of equations using chinese remainder theorem is = "<<x<<endl;

	return 0;

}
