#include "../include/Graph.h"

/*
Dijkstra's Algorithm

Computes the shortest path from a source vertex to all
other vertices in a graph with non-negative weights.

Data Structure:
    Min Priority Queue (Min Heap)

Idea:
    Always expand the node with the smallest current
    distance.

Time Complexity:
    O((V + E) log V)
*/

vector<long long> Graph::dijkstra(int src){

    vector<long long> dist(V,LLONG_MAX/2);
    dist[src]=0;

    priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<>> pq;

    pq.push({0,src});

    while(!pq.empty()){

        auto [d,u]=pq.top();
        pq.pop();

        if(d>dist[u]) continue;

        for(auto [v,w]:adj[u]){

            if(dist[v] > dist[u]+w){

                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }

    return dist;
}

/*
Bellman-Ford Algorithm

Computes shortest paths from a source vertex and
supports negative edge weights.

Features:
    - Detects negative weight cycles.

Algorithm:
    Relax all edges V-1 times.

Time Complexity:
    O(V * E)
*/

vector<long long> Graph::bellmanFord(int src){

    vector<long long> dist(V,LLONG_MAX/2);
    dist[src]=0;

    for(int i=0;i<V-1;i++){

        for(int u=0;u<V;u++){

            for(auto [v,w]:adj[u]){

                if(dist[u]!=LLONG_MAX/2 &&
                   dist[v] > dist[u]+w){

                    dist[v]=dist[u]+w;
                }
            }
        }
    }

    return dist;
}

/*
Floyd-Warshall Algorithm

Computes shortest paths between ALL pairs of vertices.

Technique:
    Dynamic Programming.

Works With:
    - Negative edges
    - No negative cycles

Time Complexity:
    O(V^3)
*/

vector<vector<long long>> Graph::floydWarshall(){

    vector<vector<long long>> dist(V,
        vector<long long>(V,LLONG_MAX/2));

    for(int i=0;i<V;i++) dist[i][i]=0;

    for(int u=0;u<V;u++){
        for(auto [v,w]:adj[u]){
            dist[u][v]=min(dist[u][v],(long long)w);
        }
    }

    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][k]<LLONG_MAX/2 &&
                   dist[k][j]<LLONG_MAX/2)
                    dist[i][j]=min(dist[i][j],
                                   dist[i][k]+dist[k][j]);

    return dist;
}