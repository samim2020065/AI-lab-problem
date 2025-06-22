#include <bits/stdc++.h>
#define sz 1000

using namespace std;

int V ;
vector<vector<int>> adj;

vector<bool> visited(sz, false);
    

void addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // For undirected graph
}

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    
    for (int i : adj[v]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
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
