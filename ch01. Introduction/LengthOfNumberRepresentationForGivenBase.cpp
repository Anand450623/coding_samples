/*
 * Problem   : Given a number and base, find length required to represent that number w.r.t giveen base.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int number, base;
	cin>>number>>base;

	cout<<"The required length is = "<<ceil(log(number)/log(base))<<endl;

	return 0;

}
