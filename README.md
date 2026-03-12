# Graph Algorithms in C++

This repository contains implementations of fundamental **graph algorithms** written in C++. The goal of the project is to explore graph data structures and practice implementing classic algorithms used in computer science and real-world systems such as navigation, networking, and search engines.

The project focuses on **algorithmic problem solving and efficient graph traversal techniques**.

---

## Overview

Graphs are one of the most important data structures in computer science and are widely used in:

* Navigation systems
* Social networks
* Computer networks
* Route optimization
* Dependency resolution

This project implements core graph algorithms that form the foundation for many real-world systems.

---

## Implemented Algorithms

### Breadth-First Search (BFS)

Breadth-First Search explores a graph level by level and is commonly used for:

* shortest path in unweighted graphs
* connectivity analysis
* graph traversal

Time Complexity:

```
O(V + E)
```

Where:

* V = number of vertices
* E = number of edges

---

### Depth-First Search (DFS)

Depth-First Search explores a graph by going as deep as possible before backtracking.

Applications include:

* cycle detection
* topological sorting
* connected components

Time Complexity:

```
O(V + E)
```

---

## Graph Representation

The graph is represented using an **adjacency list**, which is efficient for sparse graphs.

Example structure:

```
vector<vector<int>> adjacencyList;
```

Advantages:

* memory efficient
* fast traversal
* scalable for large graphs

---

## Example Graph

Example graph structure:

```
1 --- 2
|     |
3 --- 4
```

Traversal example using BFS starting from node 1:

```
1 → 2 → 3 → 4
```

Traversal using DFS:

```
1 → 2 → 4 → 3
```

---

## Technologies Used

* **C++**
* Standard Template Library (STL)

Key data structures used:

* `vector`
* `queue`
* `stack`
* `recursion`

---

## How to Run

Clone the repository:

```
git clone https://github.com/gope7oo/graphh.git
```

Compile the program:

```
g++ main.cpp -o graph
```

Run the program:

```
./graph
```

---

## Learning Goals

This project was created to practice:

* graph data structures
* traversal algorithms
* algorithm complexity analysis
* implementation of classical computer science algorithms in C++

---

## Possible Extensions

Future improvements could include:

* Dijkstra's shortest path algorithm
* A* search algorithm
* Minimum spanning tree algorithms (Prim / Kruskal)
* Graph visualization
* Weighted graphs

---
