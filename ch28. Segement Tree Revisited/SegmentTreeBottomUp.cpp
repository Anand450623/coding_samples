/*
 * Problem : Given an array of integers, implement a segment tree for range sum and single updation problem.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int power(int num, int k)
{
	if(k==0)
		return 1;

	int temp = power(num , k/2);
	temp *= temp;
	if(k%2)
		temp *= num;
	return temp;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	int seg_tree_size = 2*power(2, ceil(log2(size)));
	int seg_tree[seg_tree_size] = {0};

	for(int i=0; i<size; i++)
		seg_tree[i+size] = arr[i];

	for(int i=seg_tree_size-1; i>0; i--)
		seg_tree[i/2] += seg_tree[i];

	for(int i=1; i<seg_tree_size; i++)
		cout<<seg_tree[i]<<" ";
	cout<<endl;

	int start = 3;
	int end = 6;

	start += size;
	end += size;
	int sum = 0;

	// sum in a range
	while(start<=end)
	{
		if(start%2)
			sum += seg_tree[start++];
		if(end%2==0)
			sum += seg_tree[end--];
		start /= 2;
		end /= 2;
	}

	cout<<sum<<endl;

	// update in a range
	int index = 3;
	int newValue = 8;
	int difference = newValue - arr[index];
	index += size;
	for(	; index>0; index/=2)
		seg_tree[index] += difference;

	for(int i=1; i<seg_tree_size; i++)
		cout<<seg_tree[i]<<" ";
	cout<<endl;

	return 0;

}
