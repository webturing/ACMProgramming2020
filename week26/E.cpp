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
    int n, m, k;
    while (cin >> n >> m >> k) {


        list<int> ls;
        for (int i = 1; i <= n; i++)ls.push_back(i);
        auto it = ls.begin();
        int s = 1;
        while (ls.size() > k) {
            if (s % m == 0) {
                it = ls.erase(it);
                s = 0;
                ++s;
            } else {
                ++it;
                ++s;
            }
            if (it == ls.end()) {
                it = ls.begin();
            }

        }
        copy(ls.begin(), ls.end(), ostream_iterator<int>(cout, " "));
        cout << endl;


    }

    return 0;
}
