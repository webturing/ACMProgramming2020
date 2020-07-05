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

    for (size_t n; cin >> n;) {
        size_t tot(0);
        for (int i = 0; n >> i; i++) {
            tot = tot * 2 + (n >> i & 1);
        }
        cout << tot << endl;
    }

    return 0;
}
/**
 * 1. 位运算 (n>>i)=0  n<2^i
 * 2. 位运算 速度远远大于算术运算
*/