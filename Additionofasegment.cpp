
#include "bits/stdc++.h"
#include <iostream>
using namespace std;
using ll = long long;
using ld=long double;
#define INF (t) numeric_limits<t>::max()
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int tc;cin>>tc;
    while(tc--){
      
        int n;
        cin >> n;

        long long S = 0;   // total sum of b_i
        int p = 0;         // count of positions with b_i > 0
        for(int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            S += x;
            if(x > 0) p++;
        }

        // maximum possible length
        long long ans = min({ (long long)n, (long long)p, S - n + 1 });

        cout << ans << "\n";

       

    }

    return 0;

}
