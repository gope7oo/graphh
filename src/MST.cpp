#include "../include/Graph.h"

/*
Kruskal's Minimum Spanning Tree Algorithm

Finds a tree connecting all vertices with minimum cost.

Algorithm:
    1. Sort edges by weight
    2. Add smallest edge that doesn't form a cycle
    3. Use DSU to detect cycles

Time Complexity:
    O(E log E)
*/

long long Graph::kruskalMST(){

    if(directed){
        cout<<"MST only for undirected graphs\n";
        return 0;
    }

    vector<tuple<int,int,int>> edges;

    for(int u=0;u<V;u++){

        for(auto [v,w]:adj[u]){

            if(u<v)
                edges.push_back({w,u,v});
        }
    }

    sort(edges.begin(),edges.end());

    DSU dsu(V);

    long long cost=0;

    int used=0;

    for(auto [w,u,v]:edges){

        if(dsu.unite(u,v)){

            cost+=w;
            used++;

            if(used==V-1) break;
        }
    }

    return cost;
}