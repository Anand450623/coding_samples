/*
 * Problem: Generates subsets for a given set recursively
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

void searchForSubset(string arr,int index=0,string curr=" ")
{
	int n = arr.length();
	if(index==n)
	{
		cout<<curr<<endl;
		return;
	}
	else
	{
		searchForSubset(arr,index+1,curr+arr[index]);
		searchForSubset(arr,index+1,curr);
	}
}

int main()
{
	string arr = "abc";
	searchForSubset(arr);
	return 0;
}
