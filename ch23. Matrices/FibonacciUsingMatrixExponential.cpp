/*============================================================================
 * Problem : Implement code to find Nth fibonacci number in log(n) Complexity.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

void multiply(int x[2][2], int y[2][2])
{

	int a = x[0][0] * y[0][0] + x[0][1] * y[1][0];
	int b = x[0][0] * y[0][1] + x[0][1] * y[1][1];
	int c = x[1][0] * y[0][0] + x[1][1] * y[1][0];
	int d = x[1][0] * y[0][1] + x[1][1] * y[1][1];

	x[0][0] = a;
	x[0][1] = b;
	x[1][0] = c;
	x[1][1] = d;

}

void power(int x[2][2], int n)
{

    if(n == 0 || n == 1)
       return;

    int copy[2][2] = {{1, 1}, {1, 0}};

    power(x, n / 2);
    multiply(x, x);

    if (n % 2 != 0)
        multiply(x, copy);

}

int fibo(int n)
{

	int x[2][2] = {{1, 1}, {1, 0}};

	if (n == 0)
		return 0;

	power(x, n - 1);

	return x[0][0];

}

int main()
{

	cout<<"Nth fibonacci number is given by = "<<fibo(6);
	return 0;

}
