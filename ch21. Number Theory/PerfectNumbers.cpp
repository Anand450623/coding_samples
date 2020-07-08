/*============================================================================
 * Problem : Implement code to check whether a given number is perfect or not.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int n = 28;

	int sum = 0;
	for(int fact=1; fact<n; fact++)
		if(n%fact==0)
			sum += fact;

	if(sum==n)
		cout<<n<<" is a perfect number"<<endl;
	else
		cout<<n<<" is not a perfect number"<<endl;

	return 0;

}
