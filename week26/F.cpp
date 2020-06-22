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
    int M, N;
    while (cin >> M >> N) {
        vector<pair<int, int>> v;
        map<pair<int, int>, bool> G;
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++) {
                int t;
                cin >> t;
                if (t > 0) {
                    v.emplace_back(make_pair(i, j));
                    G[v.back()] = true;
                }
            }
        int tot = 0;
        int d[8][2] = {{1,  -1},
                       {1,  0},
                       {1,  1},
                       {0,  -1},
                       {0,  1},
                       {-1, -1},
                       {-1, 0},
                       {-1, 1}};
        for (auto &e:v) {
            if (G[e]) {
                ++tot;
                queue<pair<int, int>> Q;
                Q.push(e);
                while (Q.size()) {
                    pair<int, int> top = Q.front();
                    Q.pop();
                    G[top] = false;
                    int x = top.first;
                    int y = top.second;
                    for (int i = 0; i < 8; i++) {
                        int nx = x + d[i][0];
                        int ny = y + d[i][1];
                        pair<int, int> pt = make_pair(nx, ny);
                        if (G[pt]) {
                            G[pt] = false;
                            Q.push(pt);
                        }
                    }
                }
            }
        }
        cout << max(0, 100 - tot * 10) << endl;
    }
    return 0;
}