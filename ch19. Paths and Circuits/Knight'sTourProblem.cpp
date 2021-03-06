/*============================================================================
 * Problem : Implement solution for knight's tour problem on a n*n board. Eg., n=8
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void printBoard(int board[8][8])
{

	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
			cout<<setw(2)<<board[i][j]<<" ";
		cout<<endl;
	}

	cout<<"********************************************\n";

}

bool isSafe(int x, int y, int board[8][8])
{
	if(x<0 || x>7 || y<0 || y>7 || board[x][y]!=0)
		return false;
	else
		return true;
}

bool knightTour(int x, int y,int board[8][8], int possibleX[], int possibleY[])
{
	if(board[x][y]==64)
	{
		printBoard(board);
		return true;
	}
	else
	{

		for(int i=0;i<8;i++)
		{
			if(isSafe(x+possibleX[i], y+possibleY[i], board))
			{
				int nx = x+possibleX[i];
				int ny = y+possibleY[i];
				board[nx][ny] = board[x][y]+1;

				if(knightTour(nx, ny, board, possibleX, possibleY))
					return true;

				board[nx][ny] = 0;

			}

		}

		return false;

	}
}

int main()
{

	int board[8][8];

	int possibleX[] = {2,1,-1,-2,-2,-1,1,2};
	int possibleY[] = {1,2,2,1,-1,-2,-2,-1};

	memset(board,0,sizeof(board));
	printBoard(board);

	board[0][0] = 1;
	if(knightTour(0,0,board,possibleX, possibleY))
		cout<<"Solution exists"<<endl;
	else
		cout<<"Solution doesn't exists"<<endl;

	return 0;

}
