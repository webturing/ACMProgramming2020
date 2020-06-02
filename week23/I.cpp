#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int main() {
    vector<ll> v;
    for (ll a = 1; a <= 9; a++)
        for (ll b = 0; b <= 9; b++)
            for (ll c = 0; c <= 9; c++) {
                ll n = 100 * a + 10 * b + 1 * c;
                if (a * a * a + b * b * b + c * c * c == n)v.emplace_back(n);
            }
    ll k;
    cin >> k;
    cout << binary_search(v.begin(), v.end(), k) << endl;
    return 0;
}