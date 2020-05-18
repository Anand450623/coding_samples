/*
 * Author : Anand Kumar
 * Problem : Different methods of using bitset
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	bitset<5> s;
	s[4] = 1;
	s[1] = 1;

	cout<<s<<endl; // 10010 -- bitset works from right to left

	bitset<10> s1(string("10010"));

	cout<<s<<endl; //10010
	cout<<s[0]<<endl; //0 -- right to left
	cout<<s.count()<<endl; // 2 -- count of 1's
	cout<<s.flip()<<endl;	// 01101 -- 1's complement
	// NOTE : flip changes the actual bitset
	cout<<s.flip(4)<<endl; // flips the bit value at passed index

	return 0;
}
