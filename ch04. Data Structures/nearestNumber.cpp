/*
 *  Author : Anand Kumar
 *  Problem: The following code finds the nearest element to x in a given array
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = {1,3,6,9,11,24,34};
	int size = 7;
	int x = 5;
	set<int> s;

	for(int i=0;i<size;i++)
	{
		s.insert(arr[i]);
	}

	auto it = s.lower_bound(x);

	if(it==s.begin())
		cout<<*it<<endl;
	else if(it==s.end())
		cout<<*it<<endl;
	else
	{
		int a = *it;
		--it;
		int b = *(it);

		if(a-x>x-b)
			cout<<b<<endl;
		else
			cout<<a<<endl;
	}

	return 0;

}
