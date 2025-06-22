#include<bits/stdc++.h>

using namespace std;

int V = 6;
vector<vector<int>> adj(V);

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // For an undirected graph
}

void BFS(int start, int goal) {
    vector<bool> visited(V, false);
    queue<int> q;
    map<int, int> parent; 

    visited[start] = true;
    q.push(start);
    parent[start] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == goal) {
            cout << "Path: ";
            vector<int> path;
            for (int v = goal; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            for (int v : path) {
                cout << v << " ";
            }
            return;
        }

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                parent[neighbor] = node;
            }
        }
    }

    cout << "No path found!" << endl;
}

int main() { 
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    int start = 0, goal = 5;
    cout << "BFS from " << start << " to " << goal << ":\n";
    BFS(start, goal);

    return 0;
}
