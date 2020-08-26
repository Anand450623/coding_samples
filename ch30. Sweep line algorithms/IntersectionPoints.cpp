/*
 * Problem   : Given a set of n line segments, each of them being either vertical or horizontal, count the total number of intersection points.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

typedef struct data
{
	int x;
	int event; // 1-> start of line, 2-> vertical line found, 3-> end of line
	int y1;
	int y2;

	data()
	{
		x = 0;
		event = 0;
		y1 = 0;
		y2 = 0;
	}

	data(int time, int event, int y1, int y2)
	{
		this->x = time;
		this->event = event;
		this->y1 = y1;
		this->y2 = y2;
	}

	bool operator<(const data d)
	{
		if(this->x < d.x)
			return true;
		else if(this->x > d.x)
			return false;
		else
			return this->event < d.event;
	}

}data;

int lowerBound(vector<int> p, int lowLimit)
{
	int low = 0;
	int high = p.size()-1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(p[mid]>=lowLimit)
			high = mid-1;
		else
			low = mid+1;
	}
	return low;
}

int upperBound(vector<int> p, int highLimit)
{
	int low = 0;
	int high = p.size()-1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(p[mid]<=highLimit)
			low = mid+1;
		else
			high = mid-1;
	}
	return high;
}

int countIntersectingPoints(vector<int> p, int lowLimit, int highLimit)
{
	return upperBound(p, highLimit) - lowerBound(p, lowLimit) + 1;
}

int main()
{

	vector<data> points;
	points.push_back({1,1,2,2});
	points.push_back({6,3,2,2});
	points.push_back({2,1,4,4});
	points.push_back({7,3,4,4});
	points.push_back({7,1,3,3});
	points.push_back({11,3,3,3});
	points.push_back({3,2,1,6});
	points.push_back({9,2,2,5});
	points.push_back({7,2,1,6});

	sort(points.begin(), points.end());

	int count = 0;
	multiset<int> pointSet;
	multiset<int>::iterator it;

	for(unsigned int i=0; i<points.size(); i++)
	{
		if(points[i].event==1)
			pointSet.insert(points[i].y1);
		else if(points[i].event==2)
		{
			vector<int> p;
			for(auto x:pointSet)
				p.push_back(x);
			count += countIntersectingPoints(p, points[i].y1, points[i].y2);
		}
		else
		{
			it = pointSet.find(points[i].y1);
			pointSet.erase(it);
		}
	}

	cout<<"Total number of intersecting points are = "<<count<<endl;

	return 0;

}
