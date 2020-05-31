#include<bits/stdc++.h>

using namespace std;
using ll=unsigned long long;
const int maxn = 1000000 + 50;
ll dp[maxn];
ll b[5] = {1, 2, 4, 5, 10};
ll n;

int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++)dp[i] = i;//i元至少可以用i个1元兑换
    for (ll i = 0; i < 5; i++)dp[b[i]] = 1;//货币单位肯定只需要1张
    for (ll i = 3; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            if (i <= b[j])continue;
            dp[i] = min(dp[i], dp[i - b[j]] + 1);//松弛迭代
        }
    }
    cout << dp[n] << endl;
    return 0;

}