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

string f(int n) {
    if (n == 1)return "#";
    if (n == 2)return "RDL#";
    string s;
    s += string(n - 1, 'R');
    s += string(n - 1, 'D');
    s += string(n - 1, 'L');
    s += string(n - 2, 'U');
    s.push_back('R');
    return s + f(n - 2);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    size_t n(read<size_t>());
    vector<vector<int>> a(n, vector<int>(n, 0));
    string s = f(n);
    //cerr << s << endl;
    map<char, pair<int, int>> d;
    d['R'] = {0, 1};
    d['L'] = {0, -1};
    d['U'] = {-1, 0};
    d['D'] = {1, 0};

    int x(0), y(0), t = 1;
    a[x][y] = t;
    for (auto c:s) {
        if (c == '#')break;
        auto p = d[c];
        x += p.first;
        y += p.second;
        a[x][y] = ++t;

    }
    for (int i = 0; i < n; i++) {
        copy(a[i].begin(), a[i].end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}
