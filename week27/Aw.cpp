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
    size_t n(read<size_t>());
    vector<vector<int>> a(n, vector<int>(n, 0));

    vector<vector<int>> d{{0,  1},
                          {1,  0},
                          {0,  -1},
                          {-1, 0}};

    int x(0), y(0), t = 1;
    a[x][y] = t;
    while (t++ <= n * n) {
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny])continue;
            a[x = nx][y = ny] = t;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        copy(a[i].begin(), a[i].end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}
