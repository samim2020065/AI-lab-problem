#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        vector<pii> ops;
        bool possible = true;

        // Try to make b the reverse of a
        vector<int> pos_a(n + 1), pos_b(n + 1);
        for (int i = 0; i < n; ++i) {
            pos_a[a[i]] = i;
            pos_b[b[i]] = i;
        }

        vector<int> a_cp = a, b_cp = b;

        for (int i = 0; i < n; ++i) {
            if (a[i] == b[n - 1 - i]) continue;

            bool found = false;
            // Try to find a swap to match a[i] == b[n-1-i]
            for (int j = i + 1; j < n; ++j) {
                if (a[j] == b[n - 1 - i] && b[j] == a[i]) {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    ops.emplace_back(i + 1, j + 1);
                    found = true;
                    break;
                }
            }

            if (!found) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << "-1\n";
        } else {
            cout << ops.size() << "\n";
            for (auto [i, j] : ops) {
                cout << i << " " << j << "\n";
            }
        }
    }
    return 0;
}
