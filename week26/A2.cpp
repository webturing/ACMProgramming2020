#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
inline void oo(const string &str, T val) { cerr << str << val << endl; }

template<typename T=int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<ll> cube;

    for (ll n; cin >> n;) {
        n = abs(n);
        ll left = 0, right = 1 << 10;//cbrt(INT_MAX)
        bool find = false;
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll cmp = (mid * mid * mid) - n;
            if (cmp == 0) {
                find = true;
                break;

            }
            if (cmp < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }


        if (find)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
