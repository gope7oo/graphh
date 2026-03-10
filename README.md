# Graph Algorithms Library (C++)

A structured C++ library implementing **classical graph algorithms** for both **directed** and **undirected graphs**.  
This project is designed as a learning and portfolio project for graph algorithms and data structures.

---

## Features

### Graph Traversal
- Breadth-First Search (BFS)
- Depth-First Search (DFS) — iterative and recursive

### Connectivity & Properties
- Connected Components
- Cycle Detection (undirected)
- Bipartite Graph Check
- Bridges & Articulation Points (Tarjan’s Algorithm)

### Shortest Path Algorithms
- Dijkstra’s Algorithm (non-negative weights)
- Bellman-Ford Algorithm (supports negative weights)
- Floyd-Warshall Algorithm (all-pairs shortest path)

### Minimum Spanning Tree
- Kruskal’s Algorithm (DSU-based)

### Strongly Connected Components
- Kosaraju’s Algorithm
- Tarjan’s Algorithm (Bridges & Articulation Points)

### Graph Structure
- Topological Sort (Kahn’s Algorithm)

---

## Project Structure

graphh/
├── include/
│ └── Graph.h # Graph class definition
├── src/
│ ├── Graph.cpp # Constructor, addEdge, printGraph
│ ├── Traversal.cpp # BFS and DFS implementations
│ ├── Connectivity.cpp # Connected components, cycle detection, bipartite, bridges/articulation
│ ├── ShortestPath.cpp # Dijkstra, Bellman-Ford, Floyd-Warshall
│ ├── MST.cpp # Kruskal MST
│ └── SCC.cpp # Kosaraju SCC and Tarjan Bridges/Articulation
└── examples/
└── main.cpp # Example usage


## Features & Complexity
- Algorithm	Time Complexity
- BFS / DFS	O(V + E)
- Connected Components	O(V + E)
- Cycle Detection (undirected)	O(V + E)
- Bipartite Check	O(V + E)
- Bridges & Articulation Points	O(V + E)
- Dijkstra	O((V + E) log V)
- Bellman-Ford	O(V * E)
- Floyd-Warshall	O(V³)
- Kruskal MST	O(E log E)
- Kosaraju SCC	O(V + E)
- Topological Sort (Kahn)	O(V + E)

## Notes
Designed as a learning and portfolio project.
Fully modular with separate files per algorithm category.
Uses adjacency list representation for efficiency.
Works on both Windows and Linux with GCC / MinGW.
No external dependencies.
