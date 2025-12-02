#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    set<pair<long long, long long>> st;

    for (int i = 0; i < N; i++) {
        long long x, r;
        cin >> x >> r;
        long long a = x - r;
        long long b = x + r;
        if (a > b) swap(a, b);
        st.insert({a, b});
    }

    cout << st.size() << "\n";
}
