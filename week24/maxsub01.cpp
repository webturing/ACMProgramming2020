#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
inline void oo(const string &str, T val) { cerr << str << val << endl; }

template<typename T=int>
inline void oo(const string &str, vector<T> val) {
    cerr << str << " ";
    for (auto e:val) {
        cerr << e << " ";
    }
    cerr << endl;
}

template<typename T=int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int max_sub_cube(vector<int> &v) {//O(n^3)
    int best = 0, n = int(v.size());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int s = 0;
            for (int k = i; k <= j; k++) {
                s += v[k];
            }
            best = max(best, s);
        }
    return best;
}

int max_sub_square(vector<int> &v) {//O(n^2)
    vector<int> b(v);
    oo("pre=", b);
    partial_sum(b.begin(), b.end(), b.begin());//O(n)
    oo("post=", b);
    int best = 0, n = int(v.size());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int s = i > 0 ? b[j] - b[i - 1] : b[j];
            best = max(best, s);
        }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v{3, -2, 3, -5, 4};
    cout << max_sub_cube(v) << endl;
    cout << max_sub_square(v) << endl;
    return 0;
}
