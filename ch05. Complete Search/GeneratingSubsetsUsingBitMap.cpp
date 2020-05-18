/*
 * Problem: Generates subsets for a given set using bit mapping
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

void searchForSubset(string arr)
{
	int n = arr.length();

	for(int b=0;b<(1<<n);b++)
	{
		for(int i=0;i<n;i++)
		{
			if(b&(1<<i))
				cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	string arr = "abc";
	searchForSubset(arr);
	return 0;
}
