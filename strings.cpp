#include <bits/stdc++.h>
using namespace std;

// Comparator for lexicographically smallest concatenation
bool cmp(const string &a, const string &b) {
    return a + b < b + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<string> S(N);
        for (int i = 0; i < N; i++) cin >> S[i];

        // Step 1: Sort for A1
        sort(S.begin(), S.end(), cmp);

        // Step 2: Find first differing adjacent pair
        int idx = -1;
        for (int i = 0; i + 1 < N; i++) {
            if (S[i] != S[i+1]) {
                idx = i;
                break;
            }
        }

        // Step 3: Build A2
        // If all identical: A2 = A1
        string ans;
        ans.reserve(1000000);  // for speed

        if (idx == -1) {
            // All equal
            for (auto &x : S) ans += x;
        } else {
            // Swap S[idx] and S[idx+1] in the output only
            for (int i = 0; i < N; i++) {
                if (i == idx) ans += S[idx+1];
                else if (i == idx+1) ans += S[idx];
                else ans += S[i];
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
