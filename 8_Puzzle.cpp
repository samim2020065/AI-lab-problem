#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Dimensions of the puzzle
#define N 3

// Direction vectors for Up, Down, Left, Right
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// Goal state
vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// Node to represent a state
struct Node {
    vector<vector<int>> mat;
    int x, y; // position of 0 (blank)
    int cost; // g(n) + h(n)
    int level; // g(n)
    string path; // sequence of moves

    // Custom comparator for priority queue
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

// Function to calculate Manhattan Distance
int calculateManhattan(vector<vector<int>> &mat) {
    int dist = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val = mat[i][j];
            if (val != 0) {
                int goalX = (val - 1) / N;
                int goalY = (val - 1) % N;
                dist += abs(i - goalX) + abs(j - goalY);
            }
        }
    }
    return dist;
}

// Check if within bounds
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Serialize the matrix to a string for hashing
string serialize(const vector<vector<int>> &mat) {
    string key = "";
    for (auto &row : mat)
        for (int val : row)
            key += to_string(val);
    return key;
}

// A* Solver function
void solve(vector<vector<int>> &start, int startX, int startY) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    unordered_set<string> visited;

    Node root = {start, startX, startY, calculateManhattan(start), 0, ""};
    pq.push(root);

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        string key = serialize(curr.mat);
        if (visited.count(key))
            continue;

        visited.insert(key);

        if (curr.mat == goal) {
            cout << "Solved in " << curr.level << " moves.\n";
            cout << "Path: " << curr.path << endl;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int newX = curr.x + dx[dir];
            int newY = curr.y + dy[dir];

            if (isValid(newX, newY)) {
                vector<vector<int>> newMat = curr.mat;
                swap(newMat[curr.x][curr.y], newMat[newX][newY]);

                string move = "UDRL";
                Node child = {
                    newMat,
                    newX,
                    newY,
                    0, // will set below
                    curr.level + 1,
                    curr.path + move[dir]
                };
                int h = calculateManhattan(newMat);
                child.cost = child.level + h;

                pq.push(child);
            }
        }
    }

    cout << "No solution found.\n";
}

int main() {
    // Example: initial configuration (0 is the blank)
    vector<vector<int>> start = {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    int x = 1, y = 2; // Position of the blank tile (0)

    solve(start, x, y);

    return 0;
}
