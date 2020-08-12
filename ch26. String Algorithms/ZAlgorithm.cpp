/*============================================================================
 * Problem   : Implement Z-Algorithm for String Search.
 * Reference : https://cp-algorithms.com/string/z-function.html
 * Author    : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

vector<int> computeZArrayNaiveApproach(string s)
{
	int n = s.length();
	vector<int> array(n, 0);

	for(int i=1; i<n; i++)
	{
		while(i+array[i]<n && s[array[i]]==s[array[i]+i])
			array[i]++;
	}

	return array;
}

vector<int> computeZArrayOptimized(string s)
{
	int n = s.length();
	vector<int> array(n, 0);

	int l=0, r=0;
	for(int i=1; i<n; i++)
	{
		if(i<=r)
			array[i] = min(r-i+1, array[i-l]);
		while(i+array[i]<n && s[array[i]]==s[i+array[i]])
			array[i]++;
		if(i+array[i]-1>r)
		{
			l = i;
			r = i+array[i]-1;
		}
	}

	return array;
}

int main()
{

	string seq = "HATTIVATTI";
	string patt = "ATT";
	string s = patt+"#"+seq;

	cout<<"Z-Array computed using naive algorithm\n";
	vector<int> z = computeZArrayNaiveApproach(s);
	for(auto x:z)
		cout<<x<<" ";
	cout<<endl;

	cout<<"Z-Array computed using optimized algorithm\n";
	vector<int> zo = computeZArrayOptimized(s);
	for(auto x:zo)
		cout<<x<<" ";
	cout<<endl<<endl;

	int length = patt.size();
	for(unsigned int i=0; i<z.size(); i++)
		if(z[i]==length)
			cout<<"pattern found at "<<i-length-1<<endl;

	return 0;

}
