/*
 * Problem   : Given coordinates for vertices of polygon, find number of integral points lying inside the polygon using pick's thoerem.
 * Reference : https://www.geeksforgeeks.org/count-integral-points-inside-a-triangle/
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

double polygonArea(vector<pair<int, int>> v)
{
	double area = 0.0;
	for(unsigned int i=0; i<v.size()-1; i++)
		area += ((v[i].first*v[i+1].second) - (v[i+1].first*v[i].second));

	int size = v.size();
	area += ((v[size-1].first*v[0].second) - (v[0].first*v[size-1].second));
	return abs(area)/2;
}

int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int pointsOnEgde(pair<int, int> a, pair<int, int> b)
{

	// edge is parallel to y-axis
	if(a.first == b.first)
		return abs(a.second - b.second) - 1;

	// edge is parallel to x-axis
	if(a.second == b.second)
		return abs(a.first - b.first) -1;

	return gcd(abs(a.first - b.first), abs(a.second - b.second)) - 1;

}

/*
 * Pick's theorem states that area of any polygon is equal to : a + b/2 -1
 * where a = number of integer points inside the polygon
 *       b = number of integral points on the boundary of polygon
 * Hence,
 *       a = (2(A+1) - b)/2;   where a is the number of points on the boundary.
 */
int main()
{

	vector<pair<int, int>> v;

//	v.push_back({2, 4});
//	v.push_back({5, 5});
//	v.push_back({7, 3});
//	v.push_back({4, 1});
//	v.push_back({4, 3});

	v.push_back({0, 0});
	v.push_back({0, 5});
	v.push_back({5, 0});

	double area = polygonArea(v);
	area = 2*(area+1);

	int points = 0;
	for(unsigned int i=0; i<v.size()-1; i++)
		points += pointsOnEgde(v[i], v[i+1]);

	points += pointsOnEgde(v[0], v[v.size()-1]);
	points += v.size(); // points on the vertices

	int pointsInside = (area - points)/2;

	cout<<"Total integral points inside the polygon are = "<<pointsInside<<endl;

	return 0;

}
