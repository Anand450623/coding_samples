/*
 * Problem   : Given n points in (x,y) plane, find the coordinates using which convex hall can be constructed. (Graham + Andrew Algorithm)
 * Reference : https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

typedef struct point
{
	int x;
	int y;

	point()
	{
		x = 0;
		y = 0;
	}

	point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator<(const point p) const
	{
		return (this->x < p.x || (this->x == p.x && this->y < p.y));
	}

}point;

bool cw(point a, point b, point c)
{
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

bool ccw(point a, point b, point c)
{
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

vector<point> convexHull(vector<point> points)
{

	vector<point> hullCoordinates;

	if(points.size() <= 1)
		return hullCoordinates;

	sort(points.begin(), points.end());
	vector<point> up;
	vector<point> down;

	point p1 = points[0];
	point p2 = points.back();

	up.push_back(p1);
	down.push_back(p1);

	for(unsigned int i=1; i<points.size(); i++)
	{
		if(i == points.size()-1 || ccw(p1, points[i], p2))
		{
			while(up.size() >= 2 && !ccw(up[up.size()-2], up[up.size()-1], points[i]))
			{
				up.pop_back();
			}
			up.push_back(points[i]);
		}
		if(i == points.size()-1 || cw(p1, points[i], p2))
		{
			while(down.size() >= 2 && !cw(down[down.size()-2], down[down.size()-1], points[i]))
			{
				down.pop_back();
			}
			down.push_back(points[i]);
		}
	}

	for(unsigned int i=0; i<up.size(); i++)
		hullCoordinates.push_back(up[i]);
	for(unsigned int i=down.size()-2; i>0; i--)
		hullCoordinates.push_back(down[i]);

	return hullCoordinates;

}

int main()
{

	vector<point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};

	//{{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
	//{{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};

	for(auto x: convexHull(points))
	{
		cout<<x.x<<" "<<x.y<<endl;
	}

	return 0;

}
