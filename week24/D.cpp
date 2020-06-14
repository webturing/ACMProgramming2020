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

vector<int> primers{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
size_t n;
vector<int> a;
vector<bool> v;
bool flag = false;

void dfs(int k) {
    if (flag)
        return;
    if (k == n + 1) {

        if (binary_search(primers.begin(), primers.end(), a[1] + a[n])) {
            flag = true;
            copy(a.begin() + 1, a.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }

        return;
    }
    for (int i = 2; i <= n; i++) {
        if (v[i])continue;
        if (k > 1 && !binary_search(primers.begin(), primers.end(), i + a[k - 1]))continue;
        v[i] = true;
        a[k] = i;
        dfs(k + 1);
        v[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    if (n & 1) {
        cout << "no solution";
    }
    a.resize(n + 1);
    v.resize(n + 1);
    flag = false;
    fill(v.begin(), v.end(), false);
    a[1] = 1;
    v[1] = true;
    dfs(2);

    return 0;
}
