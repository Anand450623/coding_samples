/*
 * Problem   : Implement merge sort  for a given input array
 * Reference : https://www.geeksforgeeks.org/merge-sort/
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{

	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1], R[n2];

	for(int i=0; i<n1; i++)
		L[i] = arr[l+i];

	for(int i=0; i<n2; i++)
		R[i] = arr[m+i+1];

	int i=0, j=0, k=l;

	while(i<n1 && j<n2)
	{
		if(L[i] < R[j])
		{
			arr[k] = L[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = R[j];
			j++;
			k++;
		}
	}


	while(i<n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

}

void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int mid = (l+r)/2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);

		merge(arr, l, mid, r);
	}
}

int main()
{

	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<"The given input array is ->\n";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	mergeSort(arr, 0, n-1);

	cout<<"The sorted input array is ->\n";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	return 0;

}
