/*============================================================================
 * Problem : Given a Markov chain G, we have the find the probability of reaching the state F at time t = T
 * 			 if we start from state S at time t = 0.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

# define N 6

/*
 * A Markov chain is a random process consisting of various states and the probabilities of moving from one state to another.
 * We can represent it using a directed graph where the nodes represent the states and the edges represent the probability of
 * going from one node to another. It takes unit time to move from one node to another.
 *
 * The sum of the associated probabilities of the outgoing edges is one for every node.
 */

void multiply(float src[N][N], float dest[N][N])
{

	float temp[N][N];
	memset(temp, 0, sizeof(temp));
	for(int  i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			for(int k=0; k<N; k++)
			{
				temp[i][j] += src[i][k]*dest[k][j];
			}
		}
	}

	for(int  i=0; i<N; i++)
		for(int j=0; j<N; j++)
			src[i][j] = temp[i][j];

}

void power(float probability[N][N], int n)
{

	if(n==0 || n==1)
		return;

	float copy[N][N];

	for(int  i=0; i<N; i++)
		for(int j=0; j<N; j++)
			copy[i][j] = probability[i][j];

	power(probability, n/2);

	multiply(probability, probability);

	if(n%2)
		multiply(probability, copy);

}

int main()
{

	int s = 4; //s is the starting point.
	int t = 100; //t is the number of time units.

	float probability[N][N] = {{ 0, 0.09, 0, 0, 0, 0 },
						   	   { 0.23, 0, 0, 0, 0, 0.62 },
							   { 0, 0.06, 0, 0, 0, 0 },
							   { 0.77, 0, 0.63, 0, 0, 0 },
							   { 0, 0, 0, 0.65, 0, 0.38 },
							   { 0, 0.85, 0.37, 0.35, 1.0, 0 }};

	power(probability, t);
	float entryMat[N] = {0};
	entryMat[s-1] = 1;

	float temp[N];

	for(int i=0; i<N; i++)
	{
		float sum = 0.0f;
		for(int j=0; j<N; j++)
		{
			sum += probability[i][j] * entryMat[j];
		}
		temp[i] = sum;
	}

	cout<<"The probabilities of being at ith state after T = "<<t<<" time unit is given by:::\n";

	for(int i=0; i<N; i++)
		cout<<temp[i]<<" ";
	cout<<endl;

	return 0;

}
