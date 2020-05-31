#include<bits/stdc++.h>

using namespace std;
using ll=long long;
//阶乘、模运算、离线计算
int main() {
    ll n;
    cin >> n;
    if (n >= 25)n = 25;
    ll a[n + 1] = {1, 1};//0!=1!=1
    for (ll i = 2; i <= n; i++) {
        a[i] = (a[i - 1] * i) % 1000000;
    }
    ll s = 0;
    for (ll i = 1; i <= n; i++) {
        s = (s + a[i]) % 1000000;
    }
    cout << s << endl;


    return 0;
}