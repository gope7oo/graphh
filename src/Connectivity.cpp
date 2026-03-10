#include "../include/Graph.h"

/*
Connected Components

Finds how many separate subgraphs exist in the graph.

Definition:
    A connected component is a set of vertices where each
    vertex is reachable from any other vertex in the set.

Algorithm:
    - Perform BFS/DFS from each unvisited vertex.

Time Complexity:
    O(V + E)
*/

int Graph::connectedComponents(){

    vector<bool> visited(V,false);

    int cnt=0;

    for(int i=0;i<V;i++){

        if(!visited[i]){

            cnt++;

            queue<int> q;
            q.push(i);
            visited[i]=true;

            while(!q.empty()){

                int u=q.front();
                q.pop();

                for(auto [v,w]:adj[u]){

                    if(!visited[v]){
                        visited[v]=true;
                        q.push(v);
                    }
                }
            }
        }
    }

    return cnt;
}

/*
Cycle Detection in Undirected Graph

Uses DFS with parent tracking.

Idea:
    If we reach a visited node that is NOT the parent,
    a cycle exists.

Time Complexity:
    O(V + E)
*/

bool Graph::dfsCycle(int u,int par,vector<bool>& vis){

    vis[u]=true;

    for(auto [v,w]:adj[u]){

        if(v==par) continue;

        if(vis[v]) return true;

        if(dfsCycle(v,u,vis)) return true;
    }

    return false;
}

bool Graph::hasCycleUndirected(){

    if(directed){
        cout<<"Error: Use for undirected graphs\n";
        return false;
    }

    vector<bool> visited(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i] && dfsCycle(i,-1,visited)) return true;
    }

    return false;
}


/*
Bipartite Graph Check

Determines if the graph can be colored with two colors
such that no adjacent vertices share the same color.

Algorithm:
    BFS coloring.

Applications:
    - Matching problems
    - Scheduling problems
    - Graph partitioning

Time Complexity:
    O(V + E)
*/

bool Graph::isBipartite(){

    vector<int> color(V,-1);

    for(int i=0;i<V;i++){

        if(color[i]==-1){

            queue<int> q;

            q.push(i);
            color[i]=0;

            while(!q.empty()){

                int u=q.front();
                q.pop();

                for(auto [v,w]:adj[u]){

                    if(color[v]==-1){

                        color[v]=1-color[u];
                        q.push(v);

                    }else if(color[v]==color[u]){
                        return false;
                    }
                }
            }
        }
    }

    return true;
}