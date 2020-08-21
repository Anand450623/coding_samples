/*
 * Problem   : Given an array of integers, implement a segment tree for range sum and range update problem.
 * Reference : https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int power(int num, int k)
{
	if(k==0)
		return 1;
	int temp = power(num, k/2);
	temp *= temp;
	if(k%2)
		temp *= num;
	return temp;
}

void range_update(int update[], int seg_tree[], int start, int end, int min, int max, int curr, int delta)
{

	// before checking any validations update and resolve any pending changes
	if(update[curr])
	{
		seg_tree[curr] += (max-min+1)*update[curr];
		if(max!=min) // not a leaf node
		{
			update[curr*2] += update[curr];
			update[curr*2+1] += update[curr];
		}
		update[curr]=0;
	}

	// out of range
	if(start>end || start>max || end<min)
		return;

	// completely inside range
	if(start<=min && max<=end)
	{
		seg_tree[curr] += (max-min+1)*delta;
		if(max!=min) // not a leaf node
		{
			update[curr*2] += delta;
			update[curr*2+1] += delta;
		}
		return;
	}

	// if not completely under range but is overlapping
	int mid = (min+max)/2;
	range_update(update, seg_tree, start, end, min, mid, 2*curr, delta);
	range_update(update, seg_tree, start, end, mid+1, max, 2*curr+1, delta);

	// update current node value on the basis of children
	seg_tree[curr] = seg_tree[curr*2]+seg_tree[curr*2+1];

}

int range_sum(int seg_tree[], int update[], int start, int end, int min, int max, int curr)
{

	if(update[curr])
	{
		seg_tree[curr] += (max-min+1)*update[curr];
		if(min!=max)
		{
			seg_tree[2*curr] += update[curr];
			seg_tree[2*curr+1] += update[curr];
		}
		update[curr] = 0;
	}

	if(start>end || start>max || end<min)
		return 0;

	if(start<=min && max<=end)
		return seg_tree[curr];

	int mid = (min+max)/2;
	return range_sum(seg_tree, update, start, end, min, mid, 2*curr) + range_sum(seg_tree, update, start, end, mid+1, max, 2*curr+1);

}

int main()
{

	int arr[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	int seg_tree_size = 2*power(2, ceil(log2(size)));
	int seg_tree[seg_tree_size] = {0};
	int update[seg_tree_size] = {0};

	for(int i=0; i<size; i++)
		seg_tree[i+size] = arr[i];

	for(int i=seg_tree_size-1; i>0; i--)
		seg_tree[i/2] += seg_tree[i];

	cout<<"original array -->\n\n";
	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"************************************************\n";
	cout<<"segment tree and lazy update array before update -->\n\n";
	for(int i=1; i<seg_tree_size; i++)
		cout<<seg_tree[i]<<" ";
	cout<<endl;

	for(int i=1; i<seg_tree_size; i++)
		cout<<update[i]<<" ";
	cout<<endl;

	cout<<"************************************************\n";
	cout<<"segment tree and lazy update array after update -->\n\n";

	range_update(update, seg_tree, 2, 4, 0, size-1, 1, 2);

	for(int i=1; i<seg_tree_size; i++)
		cout<<seg_tree[i]<<" ";
	cout<<endl;

	for(int i=1; i<seg_tree_size; i++)
		cout<<update[i]<<" ";
	cout<<endl;

	cout<<"************************************************\n\n";

	cout<<"Range sum [2-4] = "<<range_sum(seg_tree, update, 2, 4, 0, size-1, 1)<<endl;

	return 0;

}
