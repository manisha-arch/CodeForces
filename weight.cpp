#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<double> sum(M + 1, 0);
    vector<int> cnt(M + 1, 0);

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        sum[A] += B;
        cnt[A] += 1;
    }

    for (int k = 1; k <= M; k++) {
        double avg = sum[k] / cnt[k];
        cout << fixed << setprecision(20) << avg << "\n";
    }

    return 0;
}
