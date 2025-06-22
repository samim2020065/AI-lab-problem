#include <bits/stdc++.h>
using namespace std;

queue<vector<int>> q;
set<vector<int>> visited;
map<vector<int>, vector<int>> parent;

// Possible moves (Missionaries, Cannibals)
vector<pair<int, int>> moves = {{1, 0}, {2, 0}, {0, 1}, {0, 2}, {1, 1}};

// Function to check if the state is valid
bool is_valid(int m, int c) {
    return (m == 0 || m >= c); // Missionaries should never be outnumbered
}

// Print solution path
void print_path(vector<int> state) {
    vector<vector<int>> path;
    while (state != vector<int>{3, 3, 1}) {
        path.push_back(state);
        state = parent[state];
    }
    path.push_back({3, 3, 1});
    reverse(path.begin(), path.end());

    for (auto &s : path) {
        int m = s[0], c = s[1], b = s[2];
        cout << "M M M  C C C   ";
        if (b) cout << "BOAT-L";
        else cout << "---------------BOAT-R";
        cout << "[" << 3 - m << "," << 3 - c << "]\n";
    }
}

// Solve the problem using BFS
void solve() {
    q.push({3, 3, 1});
    visited.insert({3, 3, 1});

    while (!q.empty()) {
        vector<int> curr = q.front();
        q.pop();
        int m = curr[0], c = curr[1], b = curr[2];

        // Goal state reached
        if (m == 0 && c == 0 && b == 0) {
            print_path(curr);
            return;
        }

        // Generate new states
        for (size_t i = 0; i < moves.size(); i++) {
            int dm = moves[i].first;
            int dc = moves[i].second;

            int nm = b ? m - dm : m + dm;
            int nc = b ? c - dc : c + dc;
            int nb = 1 - b; // Toggle boat position

            if (nm >= 0 && nm <= 3 && nc >= 0 && nc <= 3 &&
                is_valid(nm, nc) && is_valid(3 - nm, 3 - nc)) {
                
                vector<int> next_state = {nm, nc, nb};
                if (!visited.count(next_state)) {
                    visited.insert(next_state);
                    parent[next_state] = curr;
                    q.push(next_state);
                }
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
