/*
 * Problem: Given a string as input, find the longest palindromic substring for that string.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	string input = "forgeeksskeegfor";
	int n = input.size();
	bool arr[n][n];

	memset(arr,0,sizeof(arr));

	int maxLength = 1;
	for(int i=0;i<n;i++)
		arr[i][i] = true;

	for(int i=0;i<n-1;i++)
		if(input[i]==input[i+1])
		{
			arr[i][i+1]=true;
			maxLength=2;
		}


	int start = 1;
	for(int k=3;k<=n;k++)
	{
		for(int i=0;i<n-k+1;i++)
		{
			int j = i+k-1;
			if(arr[i+1][j-1] && input[i]==input[j])
			{
				arr[i][j] = true;
				if(k>maxLength)
				{
					start = i;
					maxLength = k;
				}
			}
		}
	}

	cout<<"length of longest palindromic subsequence = "<<maxLength<<endl;
	cout<<"longest palidromic substring = ";
	for(int i=start;i<start+maxLength;i++)
		cout<<input[i];
	cout<<endl;

	return 0;

}
