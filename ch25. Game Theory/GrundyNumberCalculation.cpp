/*============================================================================
 * Problem : Implement an algorithm to find grundy number for a nim game under different scenario.
 * Link    : https://www.geeksforgeeks.org/combinatorial-game-theory-set-3-grundy-numbersnimbers-and-mex/
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
 * In this case, the player can take any number of sticks from heap between [1,n]
 */
int calculateGrundyNumberForGame1(int n)
{
	if(n==0)
		return 0;
	else
	{
		unordered_set<int> s;
		for(int i=0; i<n; i++)
			s.insert(i);
		return calculateMex(s);
	}
}

/*
 * In this case, the player can take any number of sticks from heap between [1,3]
 */
int calculateGrundyNumberForGame2(int n)
{
	if(n==0)
		return 0;
	else
		return n%4;
}

/*
 * In this case, the player divides the number of sticks with 2,3 or 6 and then takes the floor
 * It equals to the number of sticks remaining in the heap.
 */
int calculateGrundyNumberForGame3(int n)
{
	if(n==0)
		return 0;
	else
	{
		unordered_set<int> s;
		s.insert(calculateGrundyNumberForGame3(n/2));
		s.insert(calculateGrundyNumberForGame3(n/3));
		s.insert(calculateGrundyNumberForGame3(n/6));
		return calculateMex(s);
	}
}

int main()
{
	int n=10;
	cout<<calculateGrundyNumberForGame1(n)<<endl;
	cout<<calculateGrundyNumberForGame2(n)<<endl;
	cout<<calculateGrundyNumberForGame3(n)<<endl;
	return 0;
}
