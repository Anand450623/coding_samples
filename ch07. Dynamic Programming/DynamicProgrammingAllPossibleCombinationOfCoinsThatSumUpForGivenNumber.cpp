/*
 * Problem: Given a set of coins values coins = {c1,c2,c3,...,ck} and a target sum of money n, our task is to print all possible combinations of coins that sums up to n
 * Author: Anand Kumar
 */

#include <iostream>

#define N 11
using namespace std;

void printArray(int arr[], int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void checkForCoins(int n,int coins[],int arr[],int index,int coin_count)
{
	if(n==0)
	{
		printArray(arr,index);
	}
	else
	{
		for(int i=0;i<coin_count;i++)
		{
			int c = coins[i];
			if(n-c>=0)
			{
				arr[index] = c;
				checkForCoins(n-c,coins,arr,index+1,coin_count);
			}
		}
	}
}

int main()
{
	int coins[] = {1,3,4};
	int coin_count = 3;

	for(int i=1;i<N;i++)
	{
		cout<<"All possible valid combination that sums up to "<<i<<" :::"<<endl<<endl;
		int arr[100] = {0};
		checkForCoins(i,coins,arr,0,coin_count);
		cout<<endl<<endl;
	}

	return 0;

}
