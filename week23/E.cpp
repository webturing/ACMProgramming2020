#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const int maxn = 1e6 + 10;
const int MOD=998244353;
ll dp[maxn];

ll f(int n) {
    if (dp[n])return dp[n];
    if (n == 1)return dp[n] = 1;//1
    if (n == 2)return dp[n] = 2;//1+1 2
    if (n == 3)return dp[n] = 4;//1+1+1 1+2 2+1 3
    return dp[n] = (f(n - 1) + f(n - 2) + f(n - 3)) % MOD;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}