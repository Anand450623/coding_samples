/*============================================================================
 * Problem : Given an undirected graph and a number m, determine if the graph can be coloured with at most m colours
 * 			 such that no two adjacent vertices of the graph are colored with the same color.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

# define N 4

bool isSafe(bool graph[N][N], int color[], int curr, int currColor)
{

	/*
	 * If i is a neighbor and if has same color as expected for current node return false.
	 * Similarly, check for all nodes.
	 */
	for(int i=0; i<N; i++)
		if(graph[curr][i] && color[i] == currColor)
			return false;

	return true;

}

bool graphColoring(bool graph[N][N], int color[], int m, int curr)
{

	if(curr == N)
		return true;

	/*
	 * Check with all the colors
	 */
	for(int i=1; i<=m; i++)
	{

		/*
		 * check if ith color can be used for current node.
		 */
		if(isSafe(graph, color, curr, i))
		{

			color[curr] = i;

			if(graphColoring(graph, color, m, curr+1))
				return true;

			color[curr] = 0;

		}

	}

	return false;

}

int main()
{

	bool graph[N][N] = {
						{ 0, 1, 1, 1 },
						{ 1, 0, 1, 0 },
						{ 1, 1, 0, 1 },
						{ 1, 0, 1, 0 },
						};

	int m = 3;
	int start = 0;
	int color[N] = {0};
	if(graphColoring(graph, color, m, start))
	{
		cout<<"Graph Coloring is possible using "<<m<<" color(s)\n";
		for(int i=0; i<N; i++)
			cout<<"Node "<<i<<" has been assigned "<<color[i]<<"th color"<<endl;
	}
	else
		cout<<"Graph Coloring is not possible\n";

	return 0;

}
