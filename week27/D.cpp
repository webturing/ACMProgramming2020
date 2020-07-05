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
    vector<int> primers{2, 3, 5, 7};
    for (int k = primers.back() + 2; k <= 1e6; k += 2) {
        auto flag = true;
        for (auto primer:primers) {
            if (primer * primer > k)break;
            if (k % primer == 0) {
                flag = false;
                break;
            }
        }
        if (flag)primers.emplace_back(k);
    }
    cerr<<primers.size()<<endl;
    int n(read());
    int tot = 0;
    if (n >= 3)++tot;
    for (auto primer:primers) {
        if (primer + 2 > n)break;
        if (binary_search(primers.begin(), primers.end(), primer + 2)) {
            ++tot;
        }
    }
    cout << tot << endl;
    return 0;
}
/**
1. 素数表的构造（滚动法，筛法）
 2. 二分查找
