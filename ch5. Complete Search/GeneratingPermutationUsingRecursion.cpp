/*
 * Problem: Generates permutations for a given set recursively
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

void swap(char *s, char *d)
{
	char temp = *s;
	*s=*d;
	*d=temp;
}

void permutations(string arr,int l,int r)
{
	if(l==r)
		cout<<arr<<endl;
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(&arr[i],&arr[l]);
			permutations(arr,l+1,r);
			swap(&arr[i],&arr[l]);
		}
	}
}

int main()
{
	string arr = "abcd";
	permutations(arr,0,arr.length()-1);
	return 0;
}
