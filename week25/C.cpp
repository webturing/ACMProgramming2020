
#include <iostream>

using namespace std;
using ll=long long;

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    ll r, t;
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    r = extended_gcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

int main() {
    ll x, y, m, n, l, p, c, a, b;
    cin >> x >> y >> m >> n >> l;
    a = n - m;
    c = x - y;
    b = l;
    if (a < 0) {
        a = -a;
        c = -c;
    }
    p = extended_gcd(a, b, x, y);
    if (c % p != 0)
        cout << "Impossible" << endl;
    else {
        x = x * c / p;
        ll t = b / p;
        if (x >= 0)
            x = x % t;
        else
            x = x % t + t;
        cout << x << endl;
    }
    return 0;
}
