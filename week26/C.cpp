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

#define lson l , m , rt << 1
#define rson m , r , rt << 1 | 1

const int maxn = 100005;
int cnt[maxn << 2];
int sum[maxn << 2];
int X[maxn];

struct Seg {
    int h, l, r;
    int s;

    Seg() {}

    Seg(int a, int b, int c, int d) : l(a), r(b), h(c), s(d) {}

    bool operator<(const Seg &cmp) const {
        return h < cmp.h;
    }
} ss[maxn];

void PushUp(int rt, int l, int r) {
    if (cnt[rt]) sum[rt] = X[r] - X[l];
    else if (l == r) sum[rt] = 0;
    else sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        cnt[rt] += c;
        PushUp(rt, l, r);
        return;
    }
    int m = (l + r) >> 1;
    if (L < m) update(L, R, c, lson);//注意不是小于等于
    if (m < R) update(L, R, c, rson);
    PushUp(rt, l, r);
}

int Bin(int key, int n, int X[]) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (X[m] == key) return m;
        if (X[m] < key) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int W, H;
        cin >> W >> H;
        int tot = W * H;
        int m = 0, n;
        cin >> n;
        while (n--) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            X[m] = a;
            ss[m++] = Seg(a, c, b, 1);
            X[m] = c;
            ss[m++] = Seg(a, c, d, -1);
        }
        sort(X, X + m);
        sort(ss, ss + m);

        int k = unique(X, X + m) - X;
        for (int i = 1; i < m; i++) {
            if (X[i] != X[i - 1]) X[k++] = X[i];
        }
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        int ret = 0;
        for (int i = 0; i < m - 1; i++) {
            int l = Bin(ss[i].l, k, X);
            int r = Bin(ss[i].r, k, X);
            if (l <= r) update(l, r, ss[i].s, 0, k - 1, 1);
            ret += sum[1] * (ss[i + 1].h - ss[i].h);
        }
        cout << tot - ret << endl;
    }
    return 0;
}