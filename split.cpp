#include <bits/stdc++.h>
using namespace std;

// Check if s[l..r] is a palindrome
bool isPalindrome(const string &s, int l, int r) {
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

// Flip bits in s[l..r]
void flip(string &s, int l, int r) {
    for(int i = l; i <= r; i++) {
        s[i] = (s[i] == '0') ? '1' : '0';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        vector<pair<int,int>> ops;

        int i = 0;
        while(i < n) {
            if(s[i] == t[i]) {
                i++;
                continue;
            }
            // Find the longest palindrome starting at i
            int r = n-1;
            while(r > i && !isPalindrome(s,i,r)) r--;
            // Flip this palindrome
            flip(s,i,r);
            ops.push_back({i+1, r+1}); // 1-indexed
            // Continue
        }

        cout << ops.size() << "\n";
        for(auto &p : ops) {
            cout << p.first << " " << p.second << "\n";
        }
    }
}
