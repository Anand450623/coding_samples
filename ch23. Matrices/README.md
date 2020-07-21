This repository contains algorithm implementation for various matrices related problems.

Direct formula for calculating fibonacci number : Fn = {[(√5 + 1)/2] ^ n} / √5

Steps to construct coefficient matrix any linear recurrance:
Let's consider fibonacci sequence as sample input.
f(n) = f(n-1) + f(n-2)

1. It will be a n*n matrix depending on number of dependent terms. for this example n=2 (f(n-1) + f(n-2)).
2. The first row will be coefficient of terms. Here, first row {1, 1}
3. Then the remaining rows will be goverened by the sequence. {{1,0,0,...,n},{0,1,0,...,n},{0,0,1,0,...,n}}

Then, the nth number of sequence can be found as the first element i.e., [0][0]th element of the coefficient matrix raised to power n.

Counting Path problem using adjacency matrix:

The Powers of an adjacency matrix of a graph have an interesting property. When V is an adjacency matrix of an unweighted graph, 
the matrix V raised to power n contains the number of paths of n edges between the nodes in the graph.

for example., if V^4[2, 5] = 2, then there are two paths of 4 edges from node 2 to node 5.