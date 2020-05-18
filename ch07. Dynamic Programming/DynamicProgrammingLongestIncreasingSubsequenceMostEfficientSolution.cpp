/*
 * Problem: find the length of longest increasing subsequence in an array in O(nlogn) time.
 * Author: Anand Kumar
 */

#include <bits/stdc++.h>
using namespace std;

int lengthOfMaxSubArray(vector<int> v)
{

	vector<int> temp;

	for(auto i:v)
	{
		auto it = lower_bound(temp.begin(),temp.end(),i);
		if(it==temp.end())
			temp.push_back(i);
		else
			*it = i;
	}

	return temp.size();

}

int main()
{
	vector<int> v{2,5,3,7,11,8,10,13,6};
	cout<<lengthOfMaxSubArray(v);
}
