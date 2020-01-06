/*
 * Problem: Given a string as input, find all possible palindromic subsequence of the string.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	string input = "hellolle";
	int n = input.size();

	vector<string> v;
	for(float pivot = 0; pivot<n; pivot+=0.5)
	{
		float radius = pivot - (int)pivot;
		int leftIndex = (int)(pivot - radius);
		int rightIndex = (int)(pivot + radius);
		while(rightIndex<n && leftIndex>=0 && input[leftIndex]==input[rightIndex])
		{

			string temp = "";
			for(int i=leftIndex;i<=rightIndex;i++)
				temp += input[i];
			v.push_back(temp);
			radius ++;

			leftIndex = (int)(pivot - radius);
			rightIndex = (int)(pivot + radius);
		}
	}

	cout<<"The total number of palindromic subsequence is = "<<v.size()<<endl;
	cout<<"The palindromic subsequences are :::\n";
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

	return 0;

}
