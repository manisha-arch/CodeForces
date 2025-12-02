#include <bits/stdc++.h>
using namespace std;

static int diff[2005][2005];
static int cover[2005][2005];
static int exact1[2005][2005];
static int pref[2005][2005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> U(N), D(N), L(N), R(N);

    for (int i = 0; i < N; i++) {
        cin >> U[i] >> D[i] >> L[i] >> R[i];
        diff[U[i]][L[i]] += 1;
        diff[D[i] + 1][L[i]] -= 1;
        diff[U[i]][R[i] + 1] -= 1;
        diff[D[i] + 1][R[i] + 1] += 1;
    }

    // Prefix-sum to build cover[][] 
    for (int r = 1; r <= 2000; r++) {
        for (int c = 1; c <= 2000; c++) {
            diff[r][c] += diff[r - 1][c] + diff[r][c - 1] - diff[r - 1][c - 1];
            cover[r][c] = diff[r][c];
        }
    }

    long long zero_total = 0;

    // Mark cells exactly covered once
    for (int r = 1; r <= 2000; r++) {
        for (int c = 1; c <= 2000; c++) {
            if (cover[r][c] == 0) zero_total++;
            if (cover[r][c] == 1) exact1[r][c] = 1;
        }
    }

    // Build prefix sum for exact1
    for (int r = 1; r <= 2000; r++) {
        for (int c = 1; c <= 2000; c++) {
            pref[r][c] = exact1[r][c]
                        + pref[r-1][c] 
                        + pref[r][c-1]
                        - pref[r-1][c-1];
        }
    }

    // Function for rectangle sum
    auto getSum = [&](int u, int d, int l, int r) {
        return pref[d][r] - pref[u-1][r] - pref[d][l-1] + pref[u-1][l-1];
    };

    // Answer
    for (int i = 0; i < N; i++) {
        long long uniqueCells = getSum(U[i], D[i], L[i], R[i]);
        cout << zero_total + uniqueCells << "\n";
    }

    return 0;
}
