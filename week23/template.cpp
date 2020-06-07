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


int main() {
    ios::sync_with_stdio(false);//关闭cin/cout与scanf/printf流同步
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    oo("n=", n);
    int m = read();//int m=read<int>();
    oo("m=", m);
    int y(read());
    oo("y=", y);
    double d = read<double>();
    string s = read<string>();
    FOR(i, 0, 10)cout << i << endl;// i int
    FOR(i, 0, 10.0) cout << i << endl;//double
    FORD(i, 10, 1)cout << i << endl;
    return 0;
}
