#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, char, int, int> State;

bool is_valid(State state) {
    int ml, cl, mr, cr;
    char b;
    tie(ml, cl, b, mr, cr) = state;

    if (ml < 0 || cl < 0 || mr < 0 || cr < 0)
        return false;

    if ((ml > 0 && ml < cl) || (mr > 0 && mr < cr))
        return false;

    return true;
}

vector<pair<State, pair<int, int>>> get_successors(State state) {
    int ml, cl, mr, cr;
    char b;
    tie(ml, cl, b, mr, cr) = state;

    vector<pair<int, int>> moves = {{1, 0}, {2, 0}, {0, 1}, {0, 2}, {1, 1}};
    vector<pair<State, pair<int, int>>> successors;

    for (auto move : moves) {
        int mm = move.first, cm = move.second;
        State new_state;

        if (b == 'L') {
            new_state = make_tuple(ml - mm, cl - cm, 'R', mr + mm, cr + cm);
        } else {
            new_state = make_tuple(ml + mm, cl + cm, 'L', mr - mm, cr - cm);
        }

        if (is_valid(new_state)) {
            successors.push_back({new_state, {mm, cm}});
        }
    }

    return successors;
}

vector<pair<State, pair<int, int>>> solve_missionaries_cannibals() {
    State initial_state = make_tuple(3, 3, 'L', 0, 0);
    State goal_state = make_tuple(0, 0, 'R', 3, 3);

    queue<vector<pair<State, pair<int, int>>>> q;
    set<State> visited;

    q.push({{initial_state, {0, 0}}});

    while (!q.empty()) {
        vector<pair<State, pair<int, int>>> path = q.front();
        q.pop();

        State current_state = path.back().first;

        if (visited.count(current_state))
            continue;

        visited.insert(current_state);

        if (current_state == goal_state)
            return path;

        for (auto successor : get_successors(current_state)) {
            vector<pair<State, pair<int, int>>> new_path = path;
            new_path.push_back(successor);
            q.push(new_path);
        }
    }

    return {};
}

void print_solution(const vector<pair<State, pair<int, int>>>& solution) {
    cout << "Missionaries and Cannibals Problem\n";
    cout << "-----------------------------------\n\n";

    for (const auto& step : solution) {
        State state = step.first;
        int mm = step.second.first, cm = step.second.second;

        int ml, cl, mr, cr;
        char b;
        tie(ml, cl, b, mr, cr) = state;

        
        for (int j = 0; j < ml; j++) cout << "M ";
        for (int j = 0; j < cl; j++) cout << "C ";
        cout << setw(13 - 2 * (ml + cl)) << " ";

        
        if (b == 'L') {
            cout << "BOAT-L[";
        } else {
            cout << "------------BOAT-R[";
        }
        if (mm > 0) cout << mm << "M";
        if (cm > 0) cout << ((mm > 0) ? "," : "") << cm << "C";
        if (mm == 0 && cm == 0) cout << " ";
        cout << "]";

        if (b == 'L') {
            cout << "-------------";
        }
        cout << " ";

       
        for (int j = 0; j < mr; j++) cout << "M ";
        for (int j = 0; j < cr; j++) cout << "C ";

        cout << endl;
    }
}

int main() {
    vector<pair<State, pair<int, int>>> solution = solve_missionaries_cannibals();
    if (!solution.empty()) {
        print_solution(solution);
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}
