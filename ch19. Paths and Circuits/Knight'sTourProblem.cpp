/*============================================================================
 * Problem : Implement solution for knight's tour problem on a n*n board. Eg.,n=8
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
			cout<<board[i][j]<<" ";
		cout<<endl;
	}

	cout<<"********************************************\n";

}

bool isSafe(int cx, int cy, int board[8][8])
{
	if((cx>=0)&&(cx<=8)&&(cy>=0)&&(cy<=8)&&(board[cx][cy]==0))
		return true;
	else
		return false;
}


bool knightsTour(int board[8][8], int cx, int cy, int moveCount, int possibleX[], int possibleY[])
{
	if(moveCount==64)
	{
		printBoard(board);
		return true;
	}
	else
	{
		for(int i=0;i<9;i++)
		{
			int n_cx = cx+possibleX[i];
			int n_cy = cy+possibleY[i];
			if(isSafe(n_cx, n_cy, board))
			{

				moveCount++;
				board[n_cx][n_cy] = moveCount;

				if(knightsTour(board, n_cx, n_cy, moveCount, possibleX, possibleY))
					return true;

				board[n_cx][n_cy] = 0;//backtracking
				moveCount--;//backtracking

			}
		}
		return false;
	}
}

int main()
{

	int board[8][8];

	int possibleX[] = {2,2,1,1,-1,-1,-2,-2};
	int possibleY[] = {1,-1,2,-2,2,-2,1,-2};

	memset(board,0,sizeof(board));
	printBoard(board);

	board[0][0] = 1;
	//moveCount = 1, because we have already taken the first move.
	knightsTour(board,0, 0, 1, possibleX, possibleY);

	return 0;

}

