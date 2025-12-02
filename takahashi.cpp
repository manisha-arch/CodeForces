#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long N, H;
        cin >> N >> H;

        long long prev_t = 0;
        long long L = H, R = H;  // feasible altitude range at current time

        bool ok = true;

        for (int i = 0; i < N; i++) {
            long long t, l, u;
            cin >> t >> l >> u;

            long long dt = t - prev_t;

            // Expand range by movement ability
            L -= dt;
            R += dt;

            if (L < 1) L = 1;  // cannot be zero or below

            // Intersect with required interval
            L = max(L, l);
            R = min(R, u);

            if (L > R) ok = false;

            prev_t = t;
        }

        cout << (ok ? "Yes" : "No") << "\n";
    }

    return 0;
}
