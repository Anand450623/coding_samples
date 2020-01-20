/*
 * Problem : Given an array of integers, implement range minimum query using sparse table method
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int arr[] = {7,2,3,0,5,10,3,12,18};
	int arr_len = sizeof(arr)/sizeof(arr[0]);	
	
	int row = arr_len,col = ((arr_len&-arr_len)==arr_len)?log2(arr_len):floor(log2(arr_len))+1;
	int sm[row][col];
	
	memset(sm,0,sizeof(sm));
	
	for(int i=0;i<arr_len;i++)
		sm[i][0] = arr[i];
		
	
	for(int j=1;j<col;j++)
		for(int i=0;(i+(1<<j)-1)<row;i++)
			sm[i][j] = min(sm[i+(1<<(j-1))][j-1],sm[i][j-1]);
	
	/*
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			cout<<sm[i][j]<<" ";
		cout<<endl;
	}
	*/
	
	int queryStart = 7, queryEnd=8;	
	int items = queryEnd-queryStart+1;	
	int range = floor(log2(items));
	
	cout<<"The required minimum in the given range is = "<<min(sm[queryStart][range],sm[queryStart+items-(1<<range)][range]);
	
	return 0;
}
