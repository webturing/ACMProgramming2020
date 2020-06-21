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
    int n(read());
    vector<int> a(n);
    for (auto &e:a)cin >> e;
    int m(read());
    int left = *max_element(a.begin(), a.end()), right = accumulate(a.begin(), a.end(), 0), best = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        int tot(0), sum(0);
        for (auto &e:a) {
            if (e + sum > mid) {
                ++tot;
                sum = e;
            } else {
                sum += e;
            }
        }
        if (sum > 0)++tot;
        if (tot <= m) {
            best = min(best, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }

    }
    cout << best << endl;

    return 0;
}
