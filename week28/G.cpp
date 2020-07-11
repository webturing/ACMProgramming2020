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

struct Circle {
    double x, y, r;

    friend bool is_joined(Circle a, Circle b) {
        return hypot(a.x - b.x, a.y - b.y) <= a.r + b.r;
    }
};

int n;
vector<int> F;

void Init() {
    F.resize(n + 1);
    for (int i = 1; i <= n; i++)F[i] = i;

}

int Find(int x) {
    return (x == F[x]) ? x : (F[x] = Find(F[x]));
}

void Merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx != fy) {
        F[fx] = fy;
    }

}

void Count() {
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (F[i] == i)++tot;
    }
    cout << tot << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin >> n) {
        vector<Circle> v(n);
        Init();
        for (int i = 0; i < n; i++) {
            cin >> v[i].x >> v[i].y >> v[i].r;
        }
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                if (is_joined(v[i], v[j]))
                    Merge(i + 1, j + 1);
            }
        Count();

    }
    return 0;
}
