This repository contains sample algo implementation for flows and cuts problems.

Algorithm for finding maximum flow or Minimum Cut:
1. Ford-fulkerson Algorithm

The above algo. sugggest to use residual graphs, but it doesn't tells about the method to choose paths.
Normal DFS may lead to very high time complexity.

Therefore, new algorithms were suugested to choose paths intelligently.

1. FFA+BFS = Edmand-Karp Algorithm
2. FFA+Optimzied DFS = Scaling Algorithm