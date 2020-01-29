/*
 * Problem : Given a number find it's binary equivalent using bit operator.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int number=32;
	for(int i=31;i>=0;i--)
		if(number&(1<<i))
			cout<<1;
		else
			cout<<0;
	cout<<endl;
	
	cout<<floor(log2(number))+1;	// checks the length of input number in binary representation.
	
	return 0;	
	
}
