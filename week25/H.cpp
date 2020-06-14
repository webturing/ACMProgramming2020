#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const int MAX = 501;
ll dp[MAX][MAX];

int main() {
    ll m, n, t;
    cin >> m >> n;
    ll best = -2e9;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t;
            dp[i][j] = dp[i - 1][j] + t;
        }
    }
    ll s;
    //j行k列的和-(i-1)行k列的和
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; ++j) {
            s = 0;
            int k;
            for (k = 1; k <= n; ++k) {
                s += dp[j][k] - dp[i - 1][k];
                best = max(best, s);
                if (s < 0) s = 0;
            }
        }
    }
    cout << best << endl;
    return 0;
}
