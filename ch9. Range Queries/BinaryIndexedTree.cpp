/*
 * Problem : Given a array of integers, implement a binary indexed tree or fenwik tree for searching and updating.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int getsum(int bit[],int k)
{
	int sum = 0;
	while(k>=1)
	{
		sum += bit[k];
		k -= k&-k;
	}
	return sum;
}

int* updateBit(int bit[],int index,int size,int value)
{
	
	index = index+1;
	while(index<=size)
	{
		bit[index] += value;
		index += index&-index;
	}
	
	return bit;
	
}

void printArray(int bit[],int size)
{
	for(int i=1;i<=size;i++)
		cout<<bit[i]<<" ";
	cout<<endl;
}

int main()
{
	
	int start_search_index = 2;
	int end_search_index = 4;
	int  arr[] = {1,3,4,8,6,1,4,2};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int bit[arr_size+1] = {0};
	
	for(int i=0;i<arr_size;i++)
	{
		int j=i+1;
		while(j<=arr_size)
		{
			bit[j] += arr[i];
			j += j&-j;
		}
	}
	
	cout<<getsum(bit,end_search_index)-getsum(bit,start_search_index-1)<<endl;
	
	cout<<"Binary Indexed array before updation ->\n";
	printArray(bit,arr_size);
	
	updateBit(bit,2,arr_size,4);
	
	cout<<"Binary Indexed array after updation ->\n";
	printArray(bit,arr_size);
	
	return 0;

}
