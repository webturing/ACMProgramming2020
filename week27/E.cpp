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
        int tot(0);
        for (int i = 0; i < 32; i++) {
            tot += (n >> i) & 1;
        }
        cout << (tot & 1 ? "odd" : "even") << endl;
    }


    return 0;
}
/**
 * 1. C/C++ unsigned
 * 2. 位运算 >> &
 * 3. 奇数判断 n&1
*/