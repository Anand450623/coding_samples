/*============================================================================
 * Problem   : Implement Knuth–Morris–Pratt algorithm.
 * Reference : https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
 * Author    : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

vector<int> calculateLPSArray(string pattern)
{
	int n = pattern.length();
	vector<int> lps(n, 0);
	int len=0;
	int index=1;
	while(index < n)
	{
		if(pattern[index] == pattern[len])
		{
			len++;
			pattern[index] = len;
			index++;
		}
		else
		{
			if(len == 0)
			{
				pattern[index] = 0;
				index++;
			}
			else
			{
				len = pattern[len-1];
			}
		}
	}
	return lps;
}

vector<int> KMP(string txt, string patt)
{
	vector<int> kmp;
	vector<int> lps = calculateLPSArray(patt);
	int i=0, j=0;
	int m = patt.length();
	int n = txt.length();
	while(i<n)
	{
		if(txt[i]==patt[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			kmp.push_back(i-j);
			j = lps[j-1];
		}
		else if(i<n && txt[i]!=patt[j])
		{
			if(j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
	return kmp;
}

int main()
{

	string txt = "AAA";
	string patt = "AA";
	vector<int> kmp = KMP(txt, patt);

	cout<<"The given pattern were found at below indices"<<endl;
	for(auto x: kmp)
		cout<<x<<" ";
	cout<<endl;

	return 0;

}
