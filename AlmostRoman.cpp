
#include "bits/stdc++.h"
#include <iostream>
using namespace std;
const long long MOD = 998244353;
using ll = long long;
using ld=long double;
#define INF (t) numeric_limits<t>::max()
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int tc;cin>>tc;
    while(tc--){
       int n, m;
        cin >> n >> m;

        int N = n - 1;      // d array size
        vector<int> need(N+2, 0); // need[i] = how many constraints require d[i] = 1

        vector<int> L(m), R(m);
        vector<vector<int>> byRight(N+1);

        for (int i = 0; i < m; i++) {
            cin >> L[i] >> R[i];
            R[i]--;                  // convert to d indexing: [L, R-1]
            if (L[i] <= R[i])
                byRight[R[i]].push_back(L[i]);
        }

        // maxLeft[i] = maximum L among constraints ending at i
        vector<int> maxLeft(N+1, 0);
        int curMax = 0;
        for (int i = 1; i <= N; i++) {
            for (int x : byRight[i]) curMax = max(curMax, x);
            maxLeft[i] = curMax;
        }

        // DP: dp[i] = number of valid d[1..i]
        vector<long long> dp(N+1, 0), pref(N+1, 0);
        dp[0] = 1;
        pref[0] = 1;

        for (int i = 1; i <= N; i++) {
            int Lpos = maxLeft[i] - 1;
            if (Lpos < 0) Lpos = 0;

            long long valid = pref[i-1];
            if (Lpos > 0) valid = (valid - pref[Lpos-1] + MOD) % MOD;

            long long noOne = (maxLeft[i] == 0 ? 1 : 0);

            dp[i] = (valid + noOne) % MOD;
            pref[i] = (pref[i-1] + dp[i]) % MOD;
        }

        long long ways_d = dp[N];
        long long ans = (ways_d * 2) % MOD;

        cout << ans << "\n";

    }

    return 0;

}
