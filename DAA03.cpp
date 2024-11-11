//Bellman-Ford Algorithm using Dynamic Programming.
//Name : Kalash Malge
//Roll No. : TIA31
//Batch : B

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


struct Edge {
    int src, dest, weight;
};


void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;


    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    
    for (int j = 0; j < E; j++) 
    {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    
    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i + 1 << " \t\t " << dist[i] << endl;
    }
}

int main() {
    int V, E, src;
    
    
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

   
    for (int i = 0; i < E; i++) {
        cout << "Enter source, destination, and weight of edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        edges[i].src--; 
        edges[i].dest--; 
    }

    
    cout << "Enter the source vertex: ";
    cin >> src;
    src--;  
    
    bellmanFord(V, E, edges, src);

    return 0;
}

