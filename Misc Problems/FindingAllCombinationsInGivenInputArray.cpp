/*============================================================================
 * Problem : Implement an algorithm to find all possible combinations of length k from given input array of length n by permuting it's
 * 			 last "k" elements.
 *
 * Author  : Anand Kumar
============================================================================*/

#include <bits/stdc++.h>
using namespace std;

int v[] = {1, 2, 3, 4, 5};
int n = 5;
int k = 3;

/*
 * Motivation: take first element in deque(elements under consideration), add it to sequence and push element to last.
 * 			   Eg. d = {3,4,5}, s = {1,2}
 *
 * 			   The Algo will run for 3 times:
 * 			   s = {1,2}, d = {3,4,5}
 * 			   s = {1,2}, d = {4,5,3}
 * 			   s = {1,2}, d = {5,3,4}
 */

void rec(deque<int> d, string s = "")
{

    if(d.size() == 0) {
        cout<<s<<endl;
        return;
    }

    for (int i = 0, len = d.size(); i < len; i++)
    {
        int x = d[0];
        d.pop_front();
        rec(d, s + to_string(x) + " ");
        d.push_back(x);
    }

}

int main()
{

    deque<int> d;
    for(int i = n - k; i < n; i++) d.push_back(v[i]);

    string s = "";
    for(int i = 0; i < n - k; i++) s += to_string(v[i]) + " ";

    rec(d, s);
    return 0;

}

