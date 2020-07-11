/*============================================================================
 * Problem : Implement code for checking whether a given number is prime or not using wilson's theorem.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

/*
 * Wilson's theorem states that a number is prime if (n-1)! mod n = n-1
 */

int main()
{

	int n = 12;

	int fact = 1;
	for(int i=2; i<n; i++)
		fact *= i;

	if(fact%n == (n-1))
		cout<<n<<" is prime"<<endl;
	else
		cout<<n<<" is not prime"<<endl;

	return 0;

}
