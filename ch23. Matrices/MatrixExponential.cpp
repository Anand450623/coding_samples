/*============================================================================
 * Problem : Implement code to find value of a matrix raised to nth power.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
#define N 2
using namespace std;

/*
 * NOTE: Matrix Exponential exists only for square matrixes.
 */

typedef struct mat
{

	int data[N][N];

	mat()
	{
		memset(data, 0, sizeof(data));
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(i==j)
					data[i][j] = 1;
	}

	void display()
	{
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
				cout<<this->data[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}

	void assign(int x, int y, int value)
	{
		this->data[x][y] = value;
	}

	struct mat pow2()
	{

		struct mat temp;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				int sum = 0;
				for(int k=0; k<N; k++)
				{
					sum += this->data[i][k] * this->data[k][j];
				}
				temp.assign(i, j, sum);
			}
		}

		return temp;

	}

	struct mat mul(mat input)
	{

		struct mat temp;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				int sum = 0;
				for(int k=0; k<N; k++)
				{
					sum += this->data[i][k] * input.data[k][j];
				}
				temp.assign(i, j, sum);
			}
		}

		return temp;

	}

}mat;

mat power(mat data, int k)
{

	if(k == 0)
		return mat();
	else
	{

		mat temp = power(data, k/2);
		temp = temp.pow2();

		if(k%2)
			temp = temp.mul(data);

		return temp;

	}

}

int main()
{

	mat identity = mat();
	cout<<"matrix initialized...\n";
	identity.display();

	identity.assign(0, 0, 2);
	identity.assign(0, 1, 5);
	identity.assign(1, 0, 1);
	identity.assign(1, 1, 4);

	cout<<"matrix after assigning data...\n";
	identity.display();

	identity = power(identity, 8);

	cout<<"after power is calculated...\n";
	identity.display();

	return 0;

}
