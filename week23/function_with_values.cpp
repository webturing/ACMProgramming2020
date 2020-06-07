#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)


template<typename T=int>
inline void oo(const string &str, T val) { cerr << str << val << endl; }

template<typename T=int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

bool prime(ll n) {//值函数
    if (n == 2)return true;
    if (n < 2 or n % 2 == 0)return false;
    for (ll c = 3; c <= n / c; c += 2) {
        if (n % c == 0)
            return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);//关闭cin/cout与scanf/printf流同步
    cin.tie(nullptr);
    cout.tie(nullptr);
    FOR(i, 1, 100) {
        if (prime(i)) {
            cout << i << " ";
        }
    }
    return 0;
}
