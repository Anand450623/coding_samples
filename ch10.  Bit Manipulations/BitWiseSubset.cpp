/*
 * Problem : Given a number, calculate its bitwise subsets.
 * 			 BitWise Subsets :
 * 			 A number i is said to be bitwise subset of x if x&i==i.
 *  
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=20;
	
	for(int i=n;i>0;i=(i-1)&n)
		cout<<i<<" ";
	cout<<0;
	cout<<endl;
		
	return 0;
}
