/*============================================================================
 * Problem : Implement algorithm to count derangements for given range of numbers.
 * 			 i.e., permutations where no elements remains in its original place.
 * 			 For Eg. when n=3, there are two derangements: (2,3,1) and (3,1,2)
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int derangement(int n)
{

	if(n <= 1)
		return 0;

	if(n == 2)
		return 1;

	return (n-1)*(derangement(n-2) + derangement(n-1));

}

int main()
{

	for(int i=1; i<10; i++)
		cout<<"Derangements in set with "<<i<<" elements is = "<<derangement(i)<<endl;

	return 0;

}
