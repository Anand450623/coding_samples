This repository contains sample codes for implementation of graph traversal algorithm.

Using graph traversal algorithms, we can check many properties of graph, Some of which are listed below:

1. Connectivity check in graph.
2. Connected component count in graph.
3. Finding cycles in graph.
4. BiPartiteness check in graph.

NOTE : Another way to find out whether a graph contains a cycle in simple graph is to simply calculate the number of nodes and edges in every component. If a component contains c nodes and no cycle, it must contain exactly c-1 edges (so it has to be a tree). If there are c or more edges, the component surely contains a cycle.

Again, the above thoery is only for simpler graph and cannot be applied to complex graph like one with adjacency matrix 0->{1,2,3}, 0->{1,2}.
Here, the graph deosn't contains any cycle but according to above stated rule it will result out in cyclic graph.