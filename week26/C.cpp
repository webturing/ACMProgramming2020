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
struct data {
    ll x1, x2, y;
    int flag;
} a[801];
ll hash[201];
ll sum[801];
int col[801];

inline bool cp(data a, data b) { return a.y < b.y; }

void pushup(int size, int l, int r) {
    if (col[size])sum[size] = hash[r + 1] - hash[l];
    else if (l == r)sum[size] = 0;
    else sum[size] = sum[size * 2] + sum[size * 2 + 1];
}

void update(int L, int R, int flag, int l, int r, int size) {
    if (L <= l && R >= r) {
        col[size] += flag;
        pushup(size, l, r);
        return;
    }
    int m = (l + r) / 2;
    if (L <= m)update(L, R, flag, l, m, size * 2);
    if (R > m)update(L, R, flag, m + 1, r, size * 2 + 1);
    pushup(size, l, r);
}

int main() {
    int T;
    cin >> T;
    while (T--) {

        int L, H, n;
        cin >> L >> H >> n;
        int x1, y1, x2, y2;
        for (int i = 1; i <= n; i++) {
            cin >> x1 >> y1 >> x2 >> y2;
            a[2 * i - 1].x1 = a[2 * i].x1 = x1;
            a[2 * i - 1].x2 = a[2 * i].x2 = x2;
            a[2 * i - 1].y = y1;
            a[2 * i].y = y2;
            a[2 * i - 1].flag = 1;
            a[2 * i].flag = -1;
            hash[2 * i - 1] = x1;
            hash[2 * i] = x2;
        }
        sort(a + 1, a + 2 * n + 1, cp);
        sort(hash + 1, hash + 2 * n + 1);
        memset(col, 0, sizeof(col));
        memset(sum, 0, sizeof(sum));
        ll ans = 0;
        for (int i = 1; i <= 2 * n; i++) {
            int l = lower_bound(hash + 1, hash + 2 * n + 1, a[i].x1) - hash;
            int r = lower_bound(hash + 1, hash + 2 * n + 1, a[i].x2) - hash - 1;
            if (l <= r)update(l, r, a[i].flag, 1, 2 * n, 1);
            ans += sum[1] * (a[i + 1].y - a[i].y);
        }
        cout << L * H - ans << endl;
    }

    return 0;
}