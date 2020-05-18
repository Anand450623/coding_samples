/*
 * Problem: Count the number of common elements in given arrays
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {5,2,8,9,4};
	int b[] = {3,2,9,5};

	sort(a,a+5);
	sort(b,b+4);

	for(int i=0;i<5;i++)
		cout<<a[i]<<" "; // 2 4 5 8 9
	cout<<endl;

	for(int i=0;i<4;i++)
		cout<<b[i]<<" "; // 2 3 5 9
	cout<<endl;

	int i=0,j=0,count=0;

	while(i<5 && j<4) // "a" size = 5, "b" size = 4
	{
		if(a[i]==b[j])
		{
			count++;
			i++;j++;
		}
		else if(a[i]>b[j])
		{
			j++;
		}
		else
		{
			i++;
		}
	}

	cout<<count<<endl;

	return 0;

}
