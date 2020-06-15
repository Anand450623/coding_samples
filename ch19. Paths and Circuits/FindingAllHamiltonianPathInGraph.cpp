/*============================================================================
 * Problem : Implement an algorithm to find all Hamiltonian path in a Graph.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

void findAllCombination(int graph[5][5], deque<int> d, vector<int> v)
{
	if(d.size()==0)
	{

		vector<int> path;
		for(int i=1; i<v.size();i++)
			if(graph[v[i]][v[i-1]])
				path.push_back(v[i-1]);

		if(path.size()==4)
		{

			if(graph[v[4]][v[0]])
				cout<<"hamiltanion circuit exists\n";

			for(auto i:v)
				cout<<i<<" ";
			cout<<endl;
		}

		return;
	}

	for(int i=0; i<d.size(); i++)
	{
		int x = d[0];
		d.pop_front();
		v.push_back(x);
		findAllCombination(graph,d,v);
		v.pop_back();
		d.push_back(x);
	}

}

int main()
{

	int graph[5][5] = {{0,1,0,1,0},
					   {1,0,1,0,1},
					   {0,1,0,0,1},
					   {1,0,0,0,1},
					   {0,1,1,1,0}};

	deque<int> d;
	vector<int> v;
	v.push_back(0);

	for(int i=1;i<5;i++)
		d.push_back(i);

	findAllCombination(graph, d, v);

	//findHamiltanionPath(graph, 5);

	return 0;

}
