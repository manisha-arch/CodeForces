#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull BASE = 131;

struct Hash {
    vector<ull> h, p;
    Hash(const string &s) {
        int n = s.size();
        h.assign(n+1,0);
        p.assign(n+1,1);
        for(int i=0;i<n;i++){
            h[i+1] = h[i]*BASE + s[i];
            p[i+1] = p[i]*BASE;
        }
    }
    ull get(int l,int r){ return h[r+1] - h[l]*p[r-l+1]; }
};

int main() {
    string s = "aaaabbbbaaaa";
    Hash H(s);
    cout << H.get(0,3) << "\n"; // hash of "aaaa"
    cout << H.get(4,7) << "\n"; // hash of "bbbb"
}
