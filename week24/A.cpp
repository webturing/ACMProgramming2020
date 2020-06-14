#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
inline void oo(string str, T val) { cerr << str << val << endl; }

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
    int right = 0;
    for (string line; cin >> line;) {
        auto p = min(line.find('+'), line.find('-'));
        line.insert(p, " ");
        line.insert(p + 2, " ");

        auto q = line.find('=');
        line.insert(q, " ");
        line.insert(q + 2, " ");
        cerr << line << endl;
        string op, eq;
        istringstream iss(line);
        ll a, b, c;

        iss >> a >> op >> b >> eq >> c;
        switch (op[0]) {
            case '+':
                if (a + b == c)++right;
                break;
            case '-':
                if (a - b == c)++right;
                break;
        }
    }
    cout << "RIGHT:" << right << endl;

    return 0;
}
