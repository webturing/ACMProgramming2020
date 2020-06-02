#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int main() {
    vector<ll> v(5, 0);
    while (cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4]) {
        if (count(v.begin(), v.end(), 0) == 5)
            break;
        if (v[1] * 2 == v[0] + v[2]) {
            ll d = v[1] - v[0], t = v.back();
            for (int i = 1; i <= 5; i++) {
                if (i > 1)cout << " ";
                cout << (t = t +  d);
            }
            cout << endl;
        } else {
            ll d = v[1] / v[0], t = v.back();
            for (int i = 1; i <= 5; i++) {
                if (i > 1)cout << " ";
                cout << (t = t * d);
            }
            cout << endl;
        }


    }
    return 0;
}