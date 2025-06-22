#include <bits/stdc++.h>
using namespace std;

const vector<vector<int>> GOAL_STATE = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

string boardToString(const vector<vector<int>>& board) {
    string s;
    for (const auto& row : board) {
        for (int val : row) {
            s += to_string(val) + ",";
        }
    }
    return s;
}

bool isGoalState(const vector<vector<int>>& board) {
    return board == GOAL_STATE;
}

vector<vector<int>> getNextState(const vector<vector<int>>& board, int x, int y, int nx, int ny) {
    vector<vector<int>> newBoard = board;
    swap(newBoard[x][y], newBoard[nx][ny]);
    return newBoard;
}

vector<pair<int, int>> getNeighbors(int x, int y) {
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<pair<int, int>> neighbors;
    
    for (const auto& dir : directions) {
        int dx = dir.first, dy = dir.second;
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            neighbors.push_back({nx, ny});
        }
    }
    return neighbors;
}

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "---" << endl;
}

void printSolution(const vector<vector<vector<int>>>& path) {
    for (const auto& state : path) {
        printBoard(state);
    }
}

void solvePuzzle(const vector<vector<int>>& initialBoard) {
    queue<pair<vector<vector<int>>, vector<vector<vector<int>>>>> q;
    unordered_set<string> visited;

    q.push({initialBoard, {initialBoard}});

    while (!q.empty()) {
        pair<vector<vector<int>>, vector<vector<vector<int>>>> front = q.front();
        vector<vector<int>> currentBoard = front.first;
        vector<vector<vector<int>>> path = front.second;
        q.pop();

        if (isGoalState(currentBoard)) {
            cout << "Solution found in " << path.size() - 1 << " moves:" << endl;
            printSolution(path);
            return;
        }

        string stateKey = boardToString(currentBoard);
        if (visited.count(stateKey)) continue;
        visited.insert(stateKey);

        int x = -1, y = -1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (currentBoard[i][j] == 0) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        for (const auto& dir : getNeighbors(x, y)) {
            int nx = dir.first, ny = dir.second;
            vector<vector<int>> nextBoard = getNextState(currentBoard, x, y, nx, ny);
            if (!visited.count(boardToString(nextBoard))) {
                vector<vector<vector<int>>> newPath = path;
                newPath.push_back(nextBoard);
                q.push({nextBoard, newPath});
            }
        }
    }

    cout << "No solution found." << endl;
}

int main() {
    vector<vector<int>> initialBoard = {
        {7, 2, 4},
        {5, 0, 6},
        {8, 3, 1}
    };

    solvePuzzle(initialBoard);

    return 0;
}
