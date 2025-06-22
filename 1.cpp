#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> penalty(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') penalty[i] = a[i];
    }

    multiset<int> wrong_penalties;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') wrong_penalties.insert(a[i]);
    }

    int min_penalty = wrong_penalties.empty() ? 0 : *wrong_penalties.rbegin();

    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            auto it = wrong_penalties.find(a[i]);
            if (it != wrong_penalties.end()) wrong_penalties.erase(it);
        }
        
        if (k > 0) {
            int j = i;
            while (j < n && k > 0) {
                if (s[j] == 'B') {
                    auto it = wrong_penalties.find(a[j]);
                    if (it != wrong_penalties.end()) wrong_penalties.erase(it);
                }
                j++;
                k--;
            }
        }
        
        min_penalty = min(min_penalty, wrong_penalties.empty() ? 0 : *wrong_penalties.rbegin());
    }
    
    cout << min_penalty << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
