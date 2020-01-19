/*
 * Problem : Given an array of integers, implement a segment tree for range sum and single updation problem.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

void showArray(int arr[],int size)
{	
	for(int i=1;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int rangeMinimum(int st[],int qs,int qe,int cs,int ce,int c_index)
{
	if(qs<=cs && qe >=ce)
		return st[c_index];
	else if(qs>ce || qe<cs)
		return INT32_MAX;
	else
	{
		int mid = (cs+ce)/2;
		int ls = rangeMinimum(st,qs,qe,cs,mid,c_index*2);
		int rs = rangeMinimum(st,qs,qe,mid+1,ce,c_index*2+1);
		return min(ls,rs);
	}
}

int main()
{
	
	int arr[] = {5,8,6,3,2,7,1};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int n=arr_size;
	
	if((arr_size&-arr_size)!=arr_size)
	{
		while((arr_size&-arr_size)!=arr_size)
			arr_size -= (arr_size&-arr_size);
			
		arr_size*=2;
	}
	
	int segment_tree[2*arr_size]={0};
	//memset(segment_tree,1,sizeof(segment_tree));	-- an alternative to initialize array
	
	for(int i=arr_size,j=0;i<2*arr_size && j<n;i++,j++)
		segment_tree[i] = arr[j];
		
	for(int i=arr_size+n;i<2*arr_size;i++)
		segment_tree[i] = INT32_MAX; 
	
	// creating segment tree	
	for(int i=2*arr_size-1;i>1;i-=2)
		segment_tree[(i-1)/2] = min(segment_tree[i],segment_tree[i-1]);
		
	// searching minimum in a range
	
	int queryStart = 4;
	int queryEnd = 4;
	cout<<rangeMinimum(segment_tree,queryStart+1,queryEnd+1,1,arr_size,1);
	
	return 0;

}
