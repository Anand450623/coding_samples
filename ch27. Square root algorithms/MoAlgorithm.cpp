/*============================================================================
 * Problem   : Implement Mo Algorithm for finding solution to range queries.
 *
 * Author    : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int block_size;

typedef struct Query
{
	int L, R;
}Query;

bool compare(Query q1, Query q2)
{
	if(q1.L/block_size != q2.L/block_size)
		return q1.L < q2.L;
	else
		return q1.R < q2.R;
}

void queryResults(int a[], int n, Query q[], int m)
{

	block_size = (int)sqrt(n);
	sort(q,q+m,compare);
	int sum = 0;
	int l=0,r=0;

	cout<<"Input array:::\n";
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;

	for(int i=0; i<m; i++)
	{
		Query query = q[i];

		for( ;l<query.L; l++)
			sum -= a[l];
		for( ;l>query.L; l--)
			sum += a[l];
		for( ;r<=query.R; r++)
			sum += a[r];
		for( ;r>query.R+1; r--)
			sum -= a[r];
		cout<<query.L<<"-"<<query.R<<" = "<<sum<<endl;
	}

}

int main()
{
	int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
	int n = sizeof(a)/sizeof(a[0]);
	Query q[] = {{0, 4}, {1, 3}, {2, 4}};
	int m = sizeof(q)/sizeof(q[0]);
	queryResults(a, n, q, m);
	return 0;
}
