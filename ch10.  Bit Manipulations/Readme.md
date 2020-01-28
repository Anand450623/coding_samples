// Bit operations for input x

1. x&1==1 (check for odd number)
2. x&1==0 (check for even number)
3. x&-x==x (check for power of 2)
4. x&(x-1) ==0 (check for power of 2)

More generally, x is divisible by 2^k exactly when x&(2^k-1)==0

4. ~x = -x-1
5. x<<k corresponds to multiplying x by 2^k
6. x>>k corresponds to dividing by 2^k rounded down to an integer
7. x|(1<<k) sets kth bit to 1
8. x|~(1<<k) sets kth bit to 0
9. x^(1<<k) Inverts the kth bit
10. x&-x : sets all the bits to zero except the last one bit
11. x&(x-1) : sets the last one bit of  x to zero
12. x|(x-1) : inverts all bits after the last one bit

built-in functions with g++ compiler : 

1. __builtin_clz(x): This function is used to count the number of zeroes at the begining of the number.
2. __builtin_ctz(x): This function is used to count the number of zeroes at the end of the number.
3. __builtin_popcount(x): This function is used to count the number of one’s(set bits) in an integer.
4. __builtin_parity(x): This function is used to check the parity of a number. This function returns true(1) if the number has odd parity else it returns false(0) for even parity.

Parity of a number refers to whether it contains an odd or even number of 1-bits. The number has “odd parity”, if it contains odd number of 1-bits and is “even parity” if it contains even number of 1-bits.

While, the above functions support only int numbers, there are also long and long long versions of the functions avialable with the suffix ll.
Eg. __builtin_popcountl(x) ,  __builtin_popcountll(x) and similarly for others as well.