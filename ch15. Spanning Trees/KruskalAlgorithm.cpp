/*============================================================================
 * Problem : Implement Kruskal Algorithm to find minimum spanning tree from a given graph.
 * Link : https://www.hackerrank.com/challenges/kruskalmstrsub/problem
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

typedef struct edge
{
	int src;
	int dest;
	int wt;

	edge(int src, int dest, int wt)
	{
		this->src=src;
		this->dest=dest;
		this->wt=wt;
	}

	bool operator<(const edge t)
	{
		return this->wt<t.wt;
	}

}edge;

typedef struct component
{

	int root;
	int size;

	component()
	{
		this->root=0;
		this->size=0;
	}

	component(int data)
	{
		this->root=data;
		this->size=1;
	}


}component;

void swap(int* a, int* b)
{
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;
}

int find(int src1, component components[])
{

	while(src1!=components[src1].root)
		src1=components[src1].root;

	return src1;

}

void merge(int src1, int src2, component components[])
{

	int src1Parent = find(src1,components);
	int src2Parent = find(src2,components);

	if(components[src1Parent].size < components[src2Parent].size)
		swap(&src1Parent, &src2Parent);

	components[src1Parent].size += components[src2Parent].size;
	components[src2Parent].root = src1Parent;

}

int  kruskal(vector<edge> edgeList, int noOfVertices)
{

	component components[noOfVertices];
	vector<edge> selectedEdges;
	int minWeight = 0;

	for(int i=1; i<noOfVertices; i++)
		components[i] = component(i);

	for(auto i:edgeList)
	{

		if(find(i.src,components)==find(i.dest,components))
			continue;
		else
		{
			merge(i.src,i.dest,components);
			minWeight += i.wt;
		}

	}

	return minWeight;

}

int main()
{

	int NO_OF_EDGES;
	int NO_OF_VERTICES;

	cin>>NO_OF_VERTICES>>NO_OF_EDGES;

	vector<edge> edgeList;

	for(int i=0;i<NO_OF_EDGES;i++)
	{

		int a,b,c;
		cin>>a>>b>>c;

		edge temp = edge(a,b,c);
		edgeList.push_back(temp);

	}

	sort(edgeList.begin(),edgeList.end());
	cout<<kruskal(edgeList,NO_OF_VERTICES+1);

	return 0;

}
