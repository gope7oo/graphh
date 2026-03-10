#include "../include/Graph.h"

/*
Breadth First Search (BFS)

Explores the graph level by level starting from a source node.

Applications:
    - Shortest path in unweighted graphs
    - Connectivity testing
    - Level order traversal

Algorithm:
    1. Start from the source vertex
    2. Visit all its neighbors
    3. Continue expanding level by level

Time Complexity:
    O(V + E)

Space Complexity:
    O(V)
*/

void Graph::bfs(int start){

    queue<int> q;
    vector<bool> visited(V,false);

    q.push(start);
    visited[start]=true;

    cout<<"BFS: ";

    while(!q.empty()){

        int cur=q.front();
        q.pop();

        cout<<cur<<" ";

        for(auto [v,w]:adj[cur]){
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
            }
        }
    }

    cout<<endl;
}

/*
Depth First Search (Iterative)

Same as BFS but using a stack not a queue
Uses a stack to simulate recursion and explore as deep
as possible before backtracking.

Time Complexity:
    O(V + E)
*/

void Graph::DFS(int start){

    vector<bool> visited(V,false);
    stack<int> st;

    st.push(start);
    visited[start]=true;

    cout<<"DFS: ";

    while(!st.empty()){

        int cur=st.top();
        st.pop();

        cout<<cur<<" ";

        for(auto [v,w]:adj[cur]){
            if(!visited[v]){
                visited[v]=true;
                st.push(v);
            }
        }
    }

    cout<<endl;
}

/*
Depth First Search (Recursive)

Recursive implementation of DFS.

Uses system call stack to explore nodes until a dead end
is reached, then backtracks.

Helper Function:
    DFSRecursiveHelper()

Time Complexity:
    O(V + E)
*/

void Graph::DFSRecursiveHelper(int u,vector<bool>& visited){

    visited[u]=true;
    cout<<u<<" ";

    for(auto [v,w]:adj[u]){
        if(!visited[v]){
            DFSRecursiveHelper(v,visited);
        }
    }
}

void Graph::DFSRecursive(int start){

    vector<bool> visited(V,false);

    cout<<"DFS: ";

    DFSRecursiveHelper(start,visited);

    cout<<endl;
}