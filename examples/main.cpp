#include "../include/Graph.h"

int main(){

    Graph g(4,false);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.printGraph();

    g.bfs(0);
    g.DFS(0);
    g.DFSRecursive(0);

    cout<<"Components: "<<g.connectedComponents()<<endl;

    cout<<"Cycle: "<<(g.hasCycleUndirected()?"Yes":"No")<<endl;

    cout<<"Bipartite: "<<(g.isBipartite()?"Yes":"No")<<endl;

    auto dist=g.dijkstra(0);

    cout<<"Dijkstra: ";
    for(auto d:dist) cout<<d<<" ";
    cout<<endl;

    cout<<"MST cost: "<<g.kruskalMST()<<endl;

}