This repository contains algorithm implementation for various number thoeory related problems.

Modular Arithemetic:

1. (x+y)mod m = (x mod m + y mod m) mod m
2. (x-y)mod m = (x mod m - y mod m) mod m
3. (x.y)mod m = (x mod m . y mod m) mod m
4. x^n mod m = ((x mod m)^n)mod m

Fermet's theorem states that 
(x^(m-1))mod m = 1 when m is prime and x and m and co-prime.

After combining fermet and euler's toient's theorem, a general formula for deriving modulo inverse of a number relative to a prime number m
is given by:

x^(-1) = x^(m-2)


While solving for diophantine equations using extended gcd algorithm, the coefficient obtained are not unique.
If a pair(x,y) is a solution, then also all the pairs

(x + kb/gcd(a,b), y - ka/gcd(a,b)))

are solutions, where k is any integer.