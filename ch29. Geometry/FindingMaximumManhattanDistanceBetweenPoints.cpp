/*
 * Problem   : Given multiple coordinate points find the maximum manhattan distance between points.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	vector<pair<int, int>> v;
	v.push_back({1, 3});
	v.push_back({2, 1});
	v.push_back({4, 4});
	v.push_back({4, 2});

	// Transformation technique : rotate all coordinate 45 degrees so that point (x, y) becomes (x+y, y-x)
	vector<pair<int, int>> transformed_coordinate;
	for(unsigned int i=0; i<v.size(); i++)
		transformed_coordinate.push_back({v[i].first+v[i].second, v[i].second-v[i].first});

	// The pair which maximizes the distance max(|x1'-x2'|,|y1'-y2'|) is the pair having maximum manhattan distance.
	int maximum = INT32_MIN;
	pair<int, int> maxPair;
	for(unsigned int i=0; i<transformed_coordinate.size()-1; i++)
	{
		int distance = max(abs(transformed_coordinate[i].first - transformed_coordinate[i+1].first),
				abs(transformed_coordinate[i].second - transformed_coordinate[i+1].second));
		if(distance > maximum)
		{
			maximum = distance;
			maxPair = {i, i+1};
		}
	}

	cout<<"The maximum distance is = "<<maximum<<"\nAnd the corresponding pair is = ("<<v[maxPair.first].first<<", "
			<<v[maxPair.first].second<<"), ("<<v[maxPair.second].first<<", "<<v[maxPair.second].second<<")\n";

	return 0;

}
