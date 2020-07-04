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
    int n;
    while (cin >> n) {
        vector<pair<int, int>> a(n);
        for (auto &e:a)cin >> e.first >> e.second;
        sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) -> bool {
            return x.second < y.second;
        });
        int tot(0), start = 0;
        for (const auto &e:a) {
            if (e.first >= start) {
                ++tot;
                start = e.second;
            }
        }
        cout << tot << endl;
    }


    return 0;
}
