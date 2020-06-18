This repository contains sample codes for implementation of path and circuits algorithm in a graph/tree.

Eulerian Paths and Circuits:

The existance of eulerian paths and circuits depends on the degree of the nodes. 
First, an undirected graph has an eulerian path exactly when all the edges belong to same component and

1. The degree of each node is even or
2. The degree of exactly two nodes is odd, and the degree of all other nodes is even.

In the first case, each eulerian path is also an Eulerian circuit. In the second case, the odd-degree nodes are the starting and ending nodes
of an Eulerian path which is not an Eulerian circuit.

In a directed graph, we focus on indegrees and outdegrees of a node. A directed graph contains an Eulerian path exactly when all the edges 
belong to the same strongly connected component and

1. In each node, the indegree equals the outdegrees, or
2. In one node, the indegree is one larger than the outdegree, in another node, the outdegree is one larger than the indegree, and in all other
   nodes, the indegree equals the outdegree.
   
Application of Eulerian Paths in genology:

1. De-Brujin Sequence
   
=================================================================================================================================

Hamiltonian Paths and Circuits:

A Hamiltonian path is a path that visits each node of the graph exactly once.
If the hamiltonian path begins and ends at the same node, it is called Hamiltonian circuit.

No efficient method is known for testing if a graph contains a Hamiltonian path and the problem is NP Hard.

Existance:

1. Dirac's thoerem: If the degree of each node is atleast n/2, the graph contains a Hamiltonian path.
2. Ore's theorem: If the sum of degress of each non-adjacent pair of nodes is at least n, the graph contains a Hamiltonian path.

For a complete undirected graph with N vertices, the total count of hamiltonian paths is (n-1)!/2

Application in modelling:

1. Knight's tour problem