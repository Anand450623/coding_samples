/*
 * Problem: Given an array and a number find whether or not that sum can be achieved using any subset element sum or not
 * Author: Anand Kumar
 */

#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

set<int> generateSubsets(vector<int> arr, int size)
{
	int no_of_subset = (1<<size);
	set<int> s;
	for(int i=0;i<no_of_subset;i++)
	{
		int sum = 0;
		for(int j=0;j<size;j++)
		{
			if(i&(1<<j))
				sum += arr[j];
		}
		s.insert(sum);
	}

	return s;

}

int main()
{
	int i=0;
	int size = 4;
	int sum_required=15;
	int arr[] = {2,4,5,9};

	vector<int> v1;
	vector<int> v2;

	for( ; i<(size/2) ; i++)
	{
		v1.push_back(arr[i]);
	}

	for( ; i<size ; i++)
	{
		v2.push_back(arr[i]);
	}

	set<int> s1 = generateSubsets(v1,size/2);
	set<int> s2 = generateSubsets(v2,size/2);

	bool res=false;
	for(auto k:s1)
	{
		for(auto l:s2)
		{
			if(k+l==sum_required)
			{
				res=true;
				break;
			}
		}
	}

	if(res)
		cout<<"match found"<<endl;
	else
		cout<<"match not found"<<endl;
	return 0;

}
