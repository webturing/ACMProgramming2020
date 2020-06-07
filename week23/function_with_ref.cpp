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

bool foo(int &n) {//引用函数
    while (n % 2 == 0)n /= 2;
    while (n % 3 == 0)n /= 3;
    while (n % 5 == 0)n /= 5;

    return true;
}

pair<int, int> find_min_max(int *a, int n) {
    int mmax, mmin;
    mmax = mmin = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < mmin)mmin = a[i];
        if (a[i] > mmax)mmax = a[i];
    }
    return make_pair(mmin, mmax);
}

bool find_min_max2(int *a, int n, int &mmin, int &mmax) {
    mmax = mmin = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < mmin)mmin = a[i];
        if (a[i] > mmax)mmax = a[i];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);//关闭cin/cout与scanf/printf流同步
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 1234567890;
    foo(n);
    cout << n << endl;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    size_t len = sizeof(a) / sizeof(a[0]);
    pair<int, int> result = find_min_max(a, len);
    cout << result.first << " " << result.second << endl;
    int mmin, mmax;
    find_min_max2(a, len, mmin, mmax);
    cout << mmin << " " << mmax << endl;
    return 0;
}
