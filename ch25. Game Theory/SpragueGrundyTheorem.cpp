/*============================================================================
 * Problem : Implement an algorithm to find winner of modified nim game using sprague-grundy-theorem.
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int calculateMex(unordered_set<int> s)
{
	int mex = 0;
	while(s.find(mex) != s.end())
		mex++;
	return mex;
}

/*
 * In this case, the player divides the number of sticks with 2,3 or 6 and then takes the floor
 * It equals to the number of sticks remaining in the heap.
 * There are n number of heaps following the same principle.
 */
int main()
{

	int n=10;
	int grundyArray[n] = {0};
	for(int i=1; i<=n; i++)
	{
		unordered_set<int> s;
		s.insert(grundyArray[n/2]);
		s.insert(grundyArray[n/3]);
		s.insert(grundyArray[n/6]);
		grundyArray[i] = calculateMex(s);

	}

	int heaps = 3;
	int sticks[] = {3,8,4};
	int resultXOR = 0;
	for(int i=0; i<heaps; i++)
		resultXOR ^= grundyArray[sticks[i]];

	if(resultXOR)
		cout<<"The player to start the game will win"<<endl;
	else
		cout<<"The player to start the game will lose"<<endl;

	return 0;

}
