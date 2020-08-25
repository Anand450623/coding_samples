/*
 * Problem   : Given three sides of triangle calculate it's area using heron's formulae.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a=3, b=4, c=5;
	int s = (a+b+c)/2;
	int area = s*(s-a)*(s-b)*(s-c);
	area = sqrt(area);
	cout<<"The area of triangle is = "<<area<<" square unit"<<endl;
	return 0;
}
