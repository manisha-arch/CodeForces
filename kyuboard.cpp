#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
static const int B = 3000;   // block size

struct Block {
    int L, R;
    string s;
    vector<char> keep;  // characters kept after processing block
    int bal;            // pushes - pops

    void build() {
        keep.clear();
        bal = 0;
        vector<char> st;

        for (char c : s) {
            if (c != 'B') {
                st.push_back(c);
                bal++;
            } else {
                if (!st.empty()) {
                    st.pop_back();
                    bal--;
                }
            }
        }
        keep = st;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    int M = (N + B - 1) / B;
    vector<Block> blk(M);

    for (int i = 0; i < M; i++) {
        blk[i].L = i * B;
        blk[i].R = min(N, (i + 1) * B) - 1;
        blk[i].s = S.substr(blk[i].L, blk[i].R - blk[i].L + 1);
        blk[i].build();
    }

    while (Q--) {
        int t;
        cin >> t;

        if (t == 1) {
            // update
            int x;
            char c;
            cin >> x >> c;
            x--;

            int id = x / B;
            blk[id].s[x - blk[id].L] = c;
            blk[id].build();
        }
        else {
            // query
            int l, r;
            cin >> l >> r;
            l--, r--;

            vector<char> st;

            int bl = l / B, br = r / B;
            for (int id = bl; id <= br; id++) {
                int L = blk[id].L, R = blk[id].R;

                if (id == bl || id == br) {
                    // partial block
                    for (int i = max(l, L); i <= min(r, R); i++) {
                        char c = blk[id].s[i - L];
                        if (c != 'B') st.push_back(c);
                        else if (!st.empty()) st.pop_back();
                    }
                } else {
                    // full block
                    // apply keep[]
                    for (char c : blk[id].keep)
                        st.push_back(c);

                    // simulate pops
                    int pops = -blk[id].bal;
                    while (pops-- > 0 && !st.empty())
                        st.pop_back();
                }
            }

            if (st.empty()) {
                cout << -1 << "\n";
            } else {
                long long ans = 0;
                for (char c : st)
                    ans = (ans * 10 + (c - '0')) % MOD;
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
