# Graph Clustering Coefficient Calculator

This project provides a simple C++ implementation for analyzing an **undirected graph**, computing:

- The **largest connected component**.
- The **global clustering coefficient** of that component.

## Features

- Adjacency list representation of the graph.
- Breadth-First Search (BFS) to find connected components.
- Triangle counting to evaluate local and global clustering.
- No external dependencies.

## Definitions

- **Connected Component**: A set of vertices where each pair is connected via paths.
- **Global Clustering Coefficient**:

$$
C = \frac{2 \times \text{number of triangles}}{\text{number of connected triples of vertices}}
$$

## Usage

Include the `Graph.h` and `Graph.cpp` files in your project and use the `Graph` class:

```cpp
Graph g;
g.add_edge(0, 1);
g.add_edge(1, 2);
g.add_edge(2, 0);
g.add_edge(3, 4);

int size = g.getLargestComponentSize(); // returns 3
double coeff = g.getGlobalClusteringCoefficient(); // returns 1.0