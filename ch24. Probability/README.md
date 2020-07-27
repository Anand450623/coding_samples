This repository contains algorithm implementation for various probability related problems.

Markov chain dynamic programming approach:

We can use dynamic programming and depth-first search (DFS) to solve this problem, 
by taking the state and the time as the two DP variables. 

We can easily observe that the probability of going from state A to state B at time t is equal to the 
product of the probability of being at A at time t - 1 and the probability associated with the edge 
connecting A and B. 

Therefore the probability of being at B at time t is the sum of this quantity for all A adjacent to B.

For eg. In our 2-D array, row can act as state and column can act as time.
so, P[B][T]  = P[A][T-1]* P[A][B]

This P[B][T] has to be summmed upon for all the adjacent states of B.

Reference link: https://www.geeksforgeeks.org/find-the-probability-of-a-state-at-a-given-time-in-a-markov-chain-set-1/?ref=lbp

Randomized Algorithm:::

An algorithm that uses random numbers to decide what to do next anywhere in its logic is called Randomized Algorithm.

Some randomized algorithms have deterministic time complexity. 
Such algorithms are called Monte Carlo Algorithms and are easier to analyse for worst case.

On the other hand, time complexity of other randomized algorithms (other than Las Vegas) is dependent on value of random variable. 
Such Randomized algorithms are called Las Vegas Algorithms.

Graph Coloring Algorithm:

Welsh–Powell Algorithm: This algorithm is a greedy algorithm for choosing from the available colors but the fact which makes it faster than
the other non-planned approach is that it process the nodes in the order of their degree. i.e., node having the highest degree is processed 
first.