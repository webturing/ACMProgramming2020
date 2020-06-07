#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const size_t maxn = 1e6 + 10;
const ll MOD = 998244353;
ll dp[maxn] = {0ll};//全部为0
// size_t === unsigned  int
ll f(size_t n) {
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
        // fill(dp,dp+maxn,0ll);//每次初始化
        size_t n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}