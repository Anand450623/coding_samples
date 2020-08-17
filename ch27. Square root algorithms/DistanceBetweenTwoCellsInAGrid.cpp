/*============================================================================
 * Problem   : Calculate distance between two cells in a grid if both the cells contains the same element.
 * 			   Find Minimum distance between such cells for each letter.
 * Author    : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
#define N 4
using namespace std;

/*
 *  Method1: Should be used when k <= sqrt(n); where k is the number of times a identical letter is occurred
 *  												 and n is total count of elements in grid
 */
void findDistance(char grid[N][N], int x, int y, map<char, int> &map)
{

	char temp = grid[x][y];

	vector<pair<int, int>> v;
	v.push_back({x, y});

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(grid[i][j] == temp && !(i==x && j==y))
			{
				v.push_back({i, j});
			}
		}
	}

	int minDistane = INT32_MAX;
	vector<int> distance;
	for(unsigned int i=0; i<v.size(); i++)
	{
		for(unsigned int j=i+1; j<v.size(); j++)
		{
			int distance = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
			minDistane = min(distance, minDistane);
		}
	}

	map.insert({temp, minDistane});

}

/*
 *  Method1: Should be used when k > sqrt(n); where k is the number of times a identical letter is occurred
 *  												 and n is total count of elements in grid
 */
void findDistanceUsingBFS(char grid[N][N], int x, int y, map<char, int> &map1)
{

	queue<tuple<int, int, int>> q;
	q.push({x, y, 0});

	bool visited[N][N];
	memset(visited, 0, sizeof(visited));

	int minDistance = INT32_MAX;
	visited[x][y] = true;
	char temp = grid[x][y];
	while(!q.empty())
	{

		int a,b,c;
		tie(a,b,c) = q.front();

		q.pop();

		if(grid[a][b] == temp && visited[a][b] == false)
		{
			minDistance = c;
			break;
		}

		visited[a][b] = true;

		// move right
		if(a+1<N && visited[a+1][b] == false)
			q.push({a+1, b, c+1});

		//move left
		if(a-1 >= 0 && visited[a-1][b] == false)
			q.push({a-1, b, c+1});

		// move down
		if(b+1<N && visited[a][b+1] == false)
			q.push({a, b+1, c+1});

		// move up
		if(b-1 >= 0 && visited[a][b-1] == false)
			q.push({a, b-1, c+1});

	}

	map1.insert({temp, minDistance});

}

int main()
{

	char grid[N][N] = {{'A', 'F', 'B', 'A'},
					   {'C', 'E', 'G', 'E'},
					   {'B', 'D', 'A', 'F'},
					   {'A', 'C', 'B', 'D'}};

	map<char, int> map, map1;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(map.find(grid[i][j]) == map.end())
			{
				findDistance(grid, i, j, map);
				findDistanceUsingBFS(grid, i, j, map1);
			}
		}
	}

	for(auto i:map)
		cout<<i.first<<" "<<i.second<<endl;

	cout<<"******************************************************\n";

	for(auto i:map1)
		cout<<i.first<<" "<<i.second<<endl;

	return 0;

}
