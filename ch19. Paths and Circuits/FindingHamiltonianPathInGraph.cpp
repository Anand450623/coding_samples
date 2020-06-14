/*============================================================================
 * Problem : Implement an algorithm to find Hamiltonian path in a Graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int calculateValueForIndex(int index, int path[], int arrSize, int prev)
{

	int val = prev;
	bool signal;
	do
	{

		val = (val+1)%arrSize;
		signal = false;
		for(int i=index-1; i>=0; i--)
			if(path[i] == val)
				signal = true;

	}while(signal);

	return val;

}

void findHamiltanionPath(int mat[5][5], int size)
{

	int path[size];
	path[0] = 0;

	for(int i=1; i<size; i++)
		path[i] = -1;


	bool solutionExists = false;
	for(int i=1; i<=size; i++)
	{

		if(i==size)
		{
			if(mat[path[size-1]][0])
				solutionExists = true;
			break;
		}

		bool found = false;
		int count = 0;
		int val = path[i-1];
		while(!found)
		{

			val = calculateValueForIndex(i, path, size, val);
			if(mat[path[i-1]][val])
			{
				path[i] = val;
				found = true;
			}
			else
				count++;

			if(count == size)
				break;

		}

		if(found == false)
			break;

	}

	if(solutionExists)
	{
		for(int i=0; i<size; i++)
			cout<<path[i]<<" ";
		cout<<path[0]<<endl;
	}
	else
		cout<<"Solution doesn't exists for given graph"<<endl;

}

int main()
{

	int graph[5][5] = {{0,1,0,1,0},
					   {1,0,1,0,1},
					   {0,1,0,0,1},
					   {1,0,0,0,1},
					   {0,1,1,1,0}};

	findHamiltanionPath(graph, 5);

	int graph1[5][5] = {{0, 1, 0, 1, 0},
						{1, 0, 1, 1, 1},
						{0, 1, 0, 0, 1},
						{1, 1, 0, 0, 1},
						{0, 1, 1, 1, 0}};

	findHamiltanionPath(graph1,5);

	int graph2[5][5] = {{0, 1, 0, 1, 0},
						{1, 0, 1, 1, 1},
						{0, 1, 0, 0, 1},
						{1, 1, 0, 0, 0},
						{0, 1, 1, 0, 0}};

	findHamiltanionPath(graph2,5);

	return 0;

}
