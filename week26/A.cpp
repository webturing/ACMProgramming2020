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
    for (ll n = 0; n * n * n <= INT_MAX; n++) {
        cube.emplace_back(n * n * n);
    }
    for (ll n; cin >> n;) {
        if (binary_search(cube.begin(), cube.end(), abs(n))) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}