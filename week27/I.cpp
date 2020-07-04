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
    for (vector<int> v(3); cin >> v[0] >> v[1] >> v[2];) {
        if (all_of(v.begin(), v.end(), [](int x) {
            return x == -1;
        }))
            break;
        auto pos = find_if(v.begin(), v.end(), [](int x) -> bool {
            return x <= 168;
        });
        if (pos == v.end()) {
            cout << "NO CRASH" << endl;
        } else {
            cout << "CRASH " << *pos << endl;
        }
    }

    return 0;
}
