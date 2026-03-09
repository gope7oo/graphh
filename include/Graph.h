#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>

class Graph {
private:
    int V;
    bool directed;
    std::vector<std::vector<std::pair<int,int>>> adj;

    struct DSU {
        std::vector<int> par, rnk;
        DSU(int n);
        int find(int x);
        bool unite(int x,int y);
    };

    void DFSRecursiveHelper(int u, std::vector<bool>& visited);
    bool dfsCycle(int u,int par,std::vector<bool>& vis);

    void dfsKos1(int u,std::vector<bool>& vis,std::stack<int>& st);
    void dfsKos2(int u,std::vector<bool>& vis,
                 std::vector<int>& comp,
                 const std::vector<std::vector<int>>& transpose);

    void dfsBridgeArt(int u,int par,
                      std::vector<int>& disc,
                      std::vector<int>& low,
                      std::vector<bool>& ap,
                      std::vector<std::pair<int,int>>& bridges,
                      int& timer);

public:

    Graph(int v,bool dir=false);

    void addEdge(int u,int v,int w=1);

    void bfs(int start);
    void DFS(int start);
    void DFSRecursive(int start);

    int connectedComponents();
    bool hasCycleUndirected();
    bool isBipartite();

    std::vector<int> topoSort();

    std::vector<long long> dijkstra(int src);
    std::vector<long long> bellmanFord(int src);
    std::vector<std::vector<long long>> floydWarshall();

    long long kruskalMST();

    std::vector<std::vector<int>> kosarajuSCC();

    std::pair<std::vector<std::pair<int,int>>,std::vector<int>> findBridgesArt();

    void printGraph();
};

#endif