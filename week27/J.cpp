#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
inline void oo(const string &str, T val) { cerr << str << val << endl; }

template<typename T=int>
inline T in() {
    T x;
    cin >> x;
    return x;
}

#define endl '\n'
#define rep(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define per(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

ll r(ll n) {
    ll m = 0;
    while (n) {
        m = m * 10 + n % 10;
        n /= 10;
    }
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (ll a, b; cin >> a >> b;) {
        cout << r(r(a) * r(b)) << endl;
    }

    return 0;
}
/**
 * 1. 简单子函数
 * 2. 整数反转
*/