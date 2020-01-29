/*
 * Problem : Given 2 sets whose elements are in range[0,31], implement set operation using bit operators.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

void show_numbers(int number)
{
	
	for(int i=31;i>=0;i--)
		if(number&(1<<i))
			cout<<i<<" ";
	cout<<endl;
	
}

int main()
{	
	
	int a[] = {1,3,4,8};
	int b[] = {3,6,8,9};
	
	int x=0,y=0;
	for(auto i:a)
		x = x|(1<<i);
		
	for(auto i:b)
		y = y|(1<<i);
	
	int z=0;
	
	// implemnting union using bit manipulation	
	z = (x|y);
	show_numbers(z);
	cout<<"The number of elements in union set is = "<<__builtin_popcount(z)<<endl;
	
	// implementing intersection using bit manipulation
	z = (x&y);
	show_numbers(z);
	cout<<"The number of elements in intersection set is = "<<__builtin_popcount(z)<<endl;
	
	// implementing complement of set a
	z =  ~x;
	show_numbers(z);
	cout<<"The number of elements in complement set is = "<<__builtin_popcount(z)<<endl;
	
	// implementing difference of a and b
	z = x&(~y);
	show_numbers(z);
	cout<<"The number of elements in complement set is = "<<__builtin_popcount(z)<<endl;
		
	return 0;		
	
}
