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

int range_sum(int seg_tree[], int a, int b, int k, int x, int y)
{
	if(a>y || b<x)
		return 0;
	if(a<=x && y<=b)
		return seg_tree[k];
	int d = (x+y)/2;
	return range_sum(seg_tree, a, b, 2*k, x, d) + range_sum(seg_tree, a, b, 2*k+1, d+1, y);
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

	cout<<"Contents of input array --->\n";
	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"Contents of segment tree --->\n";
	for(int i=1; i<seg_tree_size; i++)
		cout<<seg_tree[i]<<" ";
	cout<<endl;

	int start = 3;
	int end = 6;

	cout<<"Range Sum for ["<<start<<"-"<<end<<"] = "<<
			range_sum(seg_tree, start, end, 1, 0, size-1);

	return 0;

}
