/*
 * Problem: Given n numbers in form of an array. The goal is to find a number x such that the sum |a-x|^c+|b-x|^c+...+|n-x|^c is minimum.
 * 			we are assuming the value for c as either 1 or 2 only.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int c=2;
	int arr[]= {1,2,9,2,6};
	int no_of_elements = sizeof(arr)/sizeof(arr[0]);

	int x=0;
	int minimum_sum=0;
	if(c==1)
	{
		sort(arr,arr+no_of_elements);
		x = arr[no_of_elements/2];

		for(int i=0;i<no_of_elements;i++)
			minimum_sum += abs(arr[i]-x);

		cout<<"The required value of x = "<<x<<endl;
		cout<<"The minimum obtained value is = "<<minimum_sum<<endl;

	}
	else
	{
		int sum = 0;
		for(int i=0;i<no_of_elements;i++)
			sum += arr[i];
		x = (sum/no_of_elements);

		for(int i=0;i<no_of_elements;i++)
			minimum_sum += (arr[i]-x)*(arr[i]-x);

		cout<<"The required value of x = "<<x<<endl;
		cout<<"The minimum obtained value is = "<<minimum_sum<<endl;

	}

	return 0;

}
