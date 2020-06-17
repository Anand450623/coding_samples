/*============================================================================
 * Problem : Implement solution for knight's tour problem on a n*n board using warnsdorffs-algorithm. Eg., n=8
 * Idea    : Just do not keep back tracking, from a node choose next node having minimum neighbors.
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
}

bool limits(int x, int y)
{
    return ((x >= 0 && y >= 0) && (x < 8 && y < 8));
}

bool isempty(int board[8][8], int x, int y)
{
    return (limits(x, y)) && (board[x][y] == 0);
}

int getDegree(int board[8][8], int x, int y, int possibleX[], int possibleY[])
{
    int count = 0;
    for (int i = 0; i < 8; ++i)
        if (isempty(board, (x + possibleX[i]), (y + possibleY[i])))
            count++;

    return count;
}

bool nextMove(int board[8][8], int* x, int* y, int possibleX[], int possibleY[])
{

	int min_deg_idx = -1, c, min_deg = INT_MAX, nx, ny;

    for (int count = 0; count <8 ; ++count)
    {
        nx = *x + possibleX[count];
        ny = *y + possibleY[count];
        if ((isempty(board, nx, ny)) &&  (c = getDegree(board, nx, ny, possibleX, possibleY)) < min_deg)
        {
            min_deg_idx = count;
            min_deg = c;
        }
    }

    // IF we could not find a next cell
    if (min_deg_idx == -1)
        return false;

    // Store coordinates of next point
    nx = *x + possibleX[min_deg_idx];
    ny = *y + possibleY[min_deg_idx];

    // Mark next move
    board[nx][ny] = board[*x][*y]+1;

    // Update next point
    *x = nx;
    *y = ny;

    return true;

}

bool neighbour(int x, int y, int xx, int yy, int possibleX[], int possibleY[])
{

    for (int i = 0; i < 8; ++i)
        if (((x+possibleX[i]) == xx)&&((y + possibleY[i]) == yy))
            return true;

    return false;

}

bool findClosedTour(int possibleX[], int possibleY[])
{

	int board[8][8];
	memset(board,0,sizeof(board));

    // Randome initial position
    int sx = rand()%8;
    int sy = rand()%8;

    // Current points are same as initial points
    int x = sx, y = sy;
    board[x][y]=1;

    // starting from 1 as first move have been made
    for (int i = 1; i < 64; ++i)
        if (nextMove(board, &x, &y, possibleX, possibleY) == 0)
            return false;

    // Check if tour is closed (Can end at starting point)
    if (!neighbour(x, y, sx, sy, possibleX, possibleY))
        return false;

    printBoard(board);

    return true;

}

int main()
{

	srand(time(NULL));

	int possibleX[] = {1,1,2,2,-1,-1,-2,-2};
	int possibleY[] = {2,-2,1,-1,2,-2,1,-1};

	// While we don't get a solution
	while (!findClosedTour(possibleX, possibleY));

	return 0;

}

