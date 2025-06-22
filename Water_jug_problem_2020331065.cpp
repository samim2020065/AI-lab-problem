#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<pair<int, int>>& path) {
    for (auto& state : path) {
        cout << "(" << state.first << ", " << state.second << ")"<<endl;
    }
    cout << "Solution found in " << path.size() - 1 << " steps."<<endl;
}

void solveWaterJug(int X, int Y, int Z) {
    set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    map<pair<int, int>, vector<pair<int, int>>> paths;
    
    q.push({0, 0});
    paths[{0, 0}] = {{0, 0}};
    
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int a = current.first, b = current.second;
        
        if ((a == Z || b==Z )) {
            printSolution(paths[current]);
            return;
        }
        
        if (visited.count({a, b})) continue;
        visited.insert({a, b});
        
        vector<pair<int, int>> nextStates = {
            {X, b},  
            {a, Y},  
            {0, b},  
            {a, 0},  
            {max(0, a - (Y - b)), min(Y, b + a)},  
            {min(X, a + b), max(0, b - (X - a))}   
        };
        
        for (auto& next : nextStates) {
            if (!visited.count(next)) {
                q.push(next);
                paths[next] = paths[current];
                paths[next].push_back(next);
                // cout << "Updated path for state (" << next.first << ", " << next.second << "): ";
                // for (auto& p : paths[next]) {
                //     cout << "(" << p.first << "," << p.second << ") ";
                // }
                // cout << endl;

            }
        }
    }
    cout << "No solution found."<<endl;
}

int main() {
    int X = 3, Y = 4, Z = 2;
    solveWaterJug(X, Y, Z);
    return 0;
}
