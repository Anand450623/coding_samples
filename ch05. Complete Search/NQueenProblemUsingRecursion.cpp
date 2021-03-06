/*
 * Problem: Generates solution for n-queen problem
 * Author: Anand Kumar
 */

#include <iostream>

using namespace std;

const int N=10;

void displayBoard(int arr[][N])
{

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j])
				cout<<"Q"<<"\t";
			else
				cout<<"_"<<"\t";
		}
		cout<<endl;
	}
}

bool isSafe(int arr[][N],int x,int y)
{

	for(int i=0;i<y;i++)	// checking queen pieces in same row
		if(arr[x][i])
			return false;

	for(int i=x,j=y; i>=0 && j>=0; i--,j--)	// checking queen pieces along upper left diagonals
		if(arr[i][j])
			return false;

	for(int i=x,j=y ; i<N && j>=0 ; i++,j--)	// checking queen pieces along lower left diagonal
		if(arr[i][j])
			return false;

	return true;

}

bool nQueen(int arr[][N],int col)
{

	if(col >= N)
		return true;

	for(int i=0;i<N;i++)
	{

		if(isSafe(arr,i,col))
		{
			arr[i][col]=1;

			if(nQueen(arr,col+1))
				return true;

			arr[i][col]=0; // backtrack
		}
	}

	return false;

}


int main()
{

	int arr[N][N] = {0};

	if(nQueen(arr,0))
		displayBoard(arr);
	else
		cout<<"No solution possible"<<endl;

	return 0;
}
