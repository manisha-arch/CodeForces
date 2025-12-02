#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    const int LOG = 12; // values are < 2^12
    // pref_b[i][bit] = basis value for prefix ending at i (bit is highest set bit)
    // pref_pos[i][bit] = position (index) of the element that created that basis vector
    vector<array<int, 12>> pref_b(n+1);
    vector<array<int, 12>> pref_pos(n+1);
    for (int bit = 0; bit < LOG; ++bit) {
        pref_b[0][bit] = 0;
        pref_pos[0][bit] = -1;
    }

    auto add_to_basis = [&](array<int,12> &B, array<int,12> &P, int val, int pos) {
        int x = val;
        int p = pos;
        for (int bit = LOG-1; bit >= 0 && x; --bit) {
            if (!(x & (1<<bit))) continue;
            if (B[bit] == 0) {
                B[bit] = x;
                P[bit] = p;
                return;
            }
            // prefer the vector with larger position to stay in B[bit]
            if (P[bit] < p) {
                swap(P[bit], p);
                swap(B[bit], x);
            }
            x ^= B[bit];
        }
    };

    // build prefix bases
    for (int i = 1; i <= n; ++i) {
        pref_b[i] = pref_b[i-1];
        pref_pos[i] = pref_pos[i-1];
        add_to_basis(pref_b[i], pref_pos[i], a[i], i);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        int used = 0;
        int cur = x;
        // try to reduce using pref[r], but only use vectors with pos >= l
        for (int bit = LOG-1; bit >= 0; --bit) {
            if (pref_pos[r][bit] >= l && (cur & (1<<bit))) {
                cur ^= pref_b[r][bit];
                ++used;
            }
        }
        if (cur != 0) cout << 0 << ' ';
        else cout << used << ' ';
    }
    cout << '\n';
    return 0;
}
