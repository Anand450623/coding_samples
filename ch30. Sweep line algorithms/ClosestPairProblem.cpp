/*
 * Problem   : Given array of n points in plane, find 2 points whose euclidean distance is minimum.
 * Reference : https://www.geeksforgeeks.org/closest-pair-of-points-onlogn-implementation/
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

typedef struct point
{
	int idx;
	int x;
	int y;

	point()
	{
		idx = 0;
		x = 0;
		y = 0;
	}

	point(int idx, int x, int y)
	{
		this->idx = idx;
		this->x = x;
		this->y = y;
	}

}point;

bool compareX(point p, point q)
{
	return p.x < q.x || (p.x == q.x && p.y < q.y);
}

bool compareY(point p, point q)
{
	return p.y < q.y;
}

float dist(point p, point q)
{
	return sqrt(pow((p.x - q.x),2) + pow((p.y - q.y),2));
}

float bruteForce(vector<point> points, float minDist, pair<int, int> &minDistPair)
{
	float min = minDist;
	for(unsigned int i=0; i<points.size(); i++)
	{
		for(unsigned int j=i+1; j<points.size(); j++)
		{
			if(dist(points[i], points[j]) < min)
			{
				min = dist(points[i], points[j]);
				minDistPair = {points[i].idx, points[j].idx};
			}
		}
	}
	return min;
}

float stripClosest(vector<point> strip, float d, pair<int, int> &minDistPair)
{

	float minDistance = d;
	for(unsigned int i=0; i<strip.size(); i++)
	{
		for(unsigned int j = i+1; j<strip.size() && (strip[j].y - strip[i].y) < minDistance; j++)
		{
			if(dist(strip[j], strip[i]) < minDistance)
			{
				minDistance = dist(strip[j], strip[i]);
				minDistPair = {strip[i].idx, strip[j].idx};
			}
		}
	}

	return minDistance;

}

float findClosest(vector<point> xPoints, vector<point> yPoints, float min, pair<int, int> &minDistPair)
{

	if(xPoints.size() <= 3)
		return bruteForce(xPoints, min, minDistPair);

	int mid = xPoints.size()/2;
	vector<point> ylft;
	vector<point> yrht;

	for(unsigned int i=0; i<yPoints.size(); i++)
	{
		if(yPoints[i].x < xPoints[mid].x)
			ylft.push_back(yPoints[i]);
		else
			yrht.push_back(yPoints[i]);
	}

	vector<point> xlft(xPoints.begin(), xPoints.begin()+mid);
	vector<point> xrht(xPoints.begin()+mid, xPoints.end());

	float dl = findClosest(xlft, ylft, min, minDistPair);
	float dr = findClosest(xrht, yrht, dl, minDistPair);
	min = dr;

	vector<point> strip;
	for(unsigned int i=0; i<xPoints.size(); i++)
		if(abs(xPoints[i].x - xPoints[mid].x) < min)
			strip.push_back(xPoints[i]);

	return stripClosest(strip, min, minDistPair);

}

int main()
{

	vector<point> points = {{0, 2, 3}, {1, 12, 30}, {3, 40, 50}, {4, 5, 1}, {5, 12, 10}, {6, 3, 4}};
	vector<point> xPoint(points.begin(), points.end());
	vector<point> yPoint(points.begin(), points.end());

	sort(xPoint.begin(), xPoint.end(), compareX);
	sort(yPoint.begin(), yPoint.end(), compareY);

	float min = FLT_MAX;
	pair<int, int> minDistPair;
	float dist = findClosest(xPoint, yPoint, min, minDistPair);
	printf("%d %d %.6f", minDistPair.first, minDistPair.second, dist);

	return 0;

}
