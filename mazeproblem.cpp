
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
      
        long long n;
        cin >> n;

        if(n == 1){
            cout << 1 << "\n";
            continue;
        }
        if(n == 2){
            cout << 9 << "\n";
            continue;
        }

        long long interior = 5*(n*n - n - 1);
        long long edge = 4*(n*n - 1) - n;

        cout << max(interior, edge) << "\n";
       


       

    }

    return 0;

}
