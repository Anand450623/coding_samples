/*
 * Problem   : Demonstrate some example of complex number in C++ using some examples.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
# define X real()
# define Y imag()
using namespace std;

int main()
{

	typedef long long C;
	typedef complex<C> P;

	// declaring complex numbers
	P p  = {4,2};
	cout<<p.X<<" "<<p.Y<<endl;

	// addition of two complex numbers
	P u = {3, 1};
	P v = {2, 2};
	P s = v+u;
	cout<<s.X<<" "<<s.Y<<endl;

	// distance between two complex numbers
	typedef complex<long double> P1;
	P1 a = {4, 2};
	P1 b = {3, -1};
	cout<<abs(b-a)<<endl;

	/*
	 * calculates the angle of vector with respect to x axis in radians, where r radian equals to 180*r/3.14 degrees.
	 * The angle of a vector pointing to right is 0, the angle decreases clockwise and increases counterclockwise.
	 */
	P1 x = {4, 2};
	cout<<arg(x)<<endl;

	/*
	 * function polar(s, a) constructs a vector whose length is s and that points to an angle a.
	 * A vector can be rotated by an angle a by multiplying it by a vector of length 1 and angle a.
	 */
	x *= polar(1.0, 0.5);
	cout<<arg(x)<<endl;

	/*
	 * Calculation of cross product of vectors.
	 * The cross product (a*b)tells us whether b turns left (positive value), does not turn (zero) or turns right (negative value)
	 * when placed directly after a.
	 */
	P m = {4, 2};
	P n = {1, 2};
	cout<<(conj(m)*n).Y<<endl;

	return 0;

}
