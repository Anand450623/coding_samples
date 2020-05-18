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

int main()
{
	
	int arr[] = {5,8,6,3,2,7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int n=arr_size;
	
	if((arr_size&-arr_size)!=arr_size)
	{
		while((arr_size&-arr_size)!=arr_size)
			arr_size -= (arr_size&-arr_size);
			
		arr_size*=2;
	}
	
	int segment_tree[2*arr_size] = {0};
	
	for(int i=arr_size,j=0;i<2*arr_size && j<n;i++,j++)
		segment_tree[i] = arr[j];
	
	// creating segment tree	
	for(int i=2*arr_size-1;i>1;i--)
	{
		if(i%2)
			segment_tree[(i-1)/2] += segment_tree[i];
		else
			segment_tree[i/2] += segment_tree[i];
	}
		
	showArray(segment_tree,2*arr_size);
	
	
	int start_search_index = 1, end_search_index = 4;
	int sum = 0;
	
	start_search_index += arr_size;
	end_search_index += arr_size;
	
	// implementing search query	
	while(start_search_index<=end_search_index)
	{
		if(start_search_index%2)
			sum += segment_tree[start_search_index++];
		if(end_search_index%2==0)
			sum += segment_tree[end_search_index--];
		
		start_search_index/=2;
		end_search_index/=2;
		
	}
	
	cout<<"the required range sum is = "<<sum<<endl;
	
	// implementing addition at specified position
	
	int position = 3;
	int new_value = 8;
	
	position += arr_size;
	int diff = new_value - segment_tree[position];
	
	for(   ; position>=1; position /= 2)
		segment_tree[position] += diff;
		
	showArray(segment_tree,2*arr_size);
	
	return 0;

}
