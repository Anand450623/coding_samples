#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int> q;
	priority_queue<int,vector<int>,greater<int>> q1;

	q.push(1);
	q.push(5);
	q.push(3);

	q1.push(1);
	q1.push(5);
	q1.push(3);

	cout<<q.top()<<endl;	//5 -- gives priority to largest element
	cout<<q1.top()<<endl;	//1	-- gives priority to smallest element

	return 0;
}
