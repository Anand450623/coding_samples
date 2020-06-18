/*============================================================================
 * Problem : Implement solution for getting all possible tour's for knight's tour problem on a n*n board.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
#define N 5
using namespace std;

int count = 0;
void printBoard(int board[N][N])
{

	cout<<"Solution count = #"<<::count<<endl<<endl;
	::count++;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<setw(2)<<board[i][j]<<" ";
		cout<<endl;
	}

	cout<<"********************************************\n";

}

bool isSafe(int x, int y, int board[N][N])
{
	if(x>=0 && x<N && y>=0 && y<N && board[x][y]==0)
		return true;
	else
		return false;
}

bool knightTour(int x, int y,int board[N][N], int possibleX[], int possibleY[])
{
	if(board[x][y]==N*N)
	{
		printBoard(board);
		return true;
	}
	else
	{

		bool res = false;
		for(int i=0;i<8;i++)
		{

			int nx = x+possibleX[i];
			int ny = y+possibleY[i];

			if(isSafe(nx, ny, board))
			{
				board[nx][ny] = board[x][y]+1;
				res = knightTour(nx, ny, board, possibleX, possibleY) || res ;
				board[nx][ny] = 0;
			}

		}

		return res;

	}
}

int main()
{

	int board[N][N];

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
