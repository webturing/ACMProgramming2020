#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
inline void oo(string str, T val) { cerr << str << val << endl; }

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
    ll n(read()), left = 1, right = n;
    while (left <= right) {
        ll k = (left + right) >> 1;
        ll cmp = k * (k + 1) - 2 * n;
        if (cmp == 0) {
            cout << "YES" << endl;
            break;
        }
        if (cmp < 0) {
            left = k + 1;
        } else {
            right = k - 1;
        }

    }
    if (left > right)
        cout << "NO" << endl;


    return 0;
}
