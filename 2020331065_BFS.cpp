#include <iostream>
#include <vector>

using namespace std;

int V;
vector<vector<int>> adj;

void addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // For undirected graph
}

void DFSUtil(int v, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";
    
    for (int i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

void DFS(int start) {
    vector<bool> visited(V, false);
    DFSUtil(start, visited);
}

int main() {
    V = 6;
    adj.resize(V);
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    
    cout << "Depth-First Search (DFS) starting from node 0:" << endl;
    DFS(0);
    
    return 0;
}
