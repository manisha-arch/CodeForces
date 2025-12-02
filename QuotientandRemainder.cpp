
#include "bits/stdc++.h"
#include <iostream>
using namespace std;
using ll = long long;

#define INF (t) numeric_limits<t>::max()
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int tc;cin>>tc;
    while(tc--){
      
       int n;
        ll k;
        cin >> n >> k;
        vector<ll> q(n), r(n);
        for (int i = 0; i < n; ++i) cin >> q[i];
        for (int i = 0; i < n; ++i) cin >> r[i];

        sort(q.begin(), q.end());
        sort(r.begin(), r.end());

        // compress q into (value, count)
        vector<pair<ll,int>> Q;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && q[j] == q[i]) ++j;
            Q.emplace_back(q[i], j - i);
            i = j;
        }

        // For each unique q compute maxR = floor((k - q) / (q + 1))
        // If k - q < 0 then maxR < 0 and no r works
        struct Node { ll maxR; ll qv; int cnt; };
        vector<Node> nodes;
        nodes.reserve(Q.size());
        for (auto &p : Q) {
            ll qv = p.first;
            int cnt = p.second;
            if (qv > k) {
                // since qv > k, (k - qv) negative -> maxR < 0 -> skip but keep node with maxR = -1
                nodes.push_back({-1, qv, cnt});
            } else {
                ll maxR = (k - qv) / (qv + 1);
                nodes.push_back({maxR, qv, cnt});
            }
        }

        // sort nodes by maxR ascending
        sort(nodes.begin(), nodes.end(), [](const Node &a, const Node &b){
            if (a.maxR != b.maxR) return a.maxR < b.maxR;
            return a.qv < b.qv;
        });

        ll ans = 0;
        int idx = 0;             // pointer over r[]
        long long pool = 0;      // number of r's <= current maxR that are available in pool
        long long used = 0;      // how many r's already used (cumulatively)
        // Note: availableNow = pool - used

        for (auto &nd : nodes) {
            if (nd.maxR < 0) continue; // no r works for this q
            // add r values <= nd.maxR into pool
            while (idx < n && r[idx] <= nd.maxR) {
                pool++;
                idx++;
            }
            long long availableNow = pool - used;
            if (availableNow <= 0) continue;
            long long take = min<long long>(nd.cnt, availableNow);
            ans += take;
            used += take;
        }

        cout << ans << '\n';
    }

    return 0;

}
