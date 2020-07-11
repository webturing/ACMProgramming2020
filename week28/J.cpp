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
    for (double a, b, c; cin >> a >> b >> c;) {
        double x = acos((b * b + c * c - a * a) / (2 * b * c));
        //cerr << "x=" << x << endl;
        double R = a / sin(x) / 2;
        double p = (a + b + c) / 2;
        double S = sqrt(p * (p - a) * (p - b) * (p - c));
        double r = S / p;
        cout << fixed << setprecision(3) << M_PI * r * r << " "
             << fixed << setprecision(3) << M_PI * R * R << endl;

    }

    return 0;
}
