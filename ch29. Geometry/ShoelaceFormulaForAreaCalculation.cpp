/*
 * Problem   : Implement shoelace formula for calculating area of polygon whose vertices coordinates are given.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	vector<pair<int, int>> v;
//	v.push_back({2, 4});
//	v.push_back({5, 5});
//	v.push_back({7, 3});
//	v.push_back({4, 1});
//	v.push_back({4, 3});

	v.push_back({0, 0});
	v.push_back({4, 0});
	v.push_back({0, 3});

	double area = 0.0;
	for(unsigned int i=0; i<v.size()-1; i++)
		area += ((v[i].first*v[i+1].second) - (v[i+1].first*v[i].second));

	int size = v.size();
	area += ((v[size-1].first*v[0].second) - (v[0].first*v[size-1].second));

	cout<<"The area of polygon is = "<<abs(area)/2<<" square unit"<<endl;

	return 0;

}
