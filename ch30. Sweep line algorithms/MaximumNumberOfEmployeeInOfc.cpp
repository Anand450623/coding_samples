/*
 * Problem   : Given in and exit time of n employees, find the maximum count of employees present in office at same time.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	vector<int> arrival = {10,6,14,5};
	vector<int> leaving = {15,12,16,13};
	sort(arrival.begin(), arrival.end());
	sort(leaving.begin(), leaving.end());

	int personCount = 0;
	int maxCount = 0;
	unsigned int aIter = 0;
	unsigned int lIter = 0;
	while(aIter < arrival.size() && lIter < leaving.size())
	{
		if(arrival[aIter] < leaving[lIter])
		{
			aIter++;
			personCount++;
			if(personCount > maxCount)
				maxCount = personCount;
		}
		else
		{
			lIter++;
			personCount--;
		}
	}

	while(aIter < arrival.size())
	{
		aIter++;
		personCount++;
	}

	if(personCount>maxCount)
		maxCount = personCount;

	while(lIter < leaving.size())
	{
		lIter++;
		personCount--;
	}

	cout<<"Maximum number of employees that were in the office at the same time = "<<maxCount<<endl;

	return 0;

}
